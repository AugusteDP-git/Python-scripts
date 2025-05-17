import random
import time
import numpy as np
import torch
import torch.nn as nn
import torch.optim as optim
from gymnasium.utils import seeding
from utils import ReplayBuffer, get_env, run_episode
import copy

class MLP(nn.Module):
    '''
    A simple ReLU MLP constructed from a list of layer widths.
    '''
    def __init__(self, sizes):
        super().__init__()
        layers = []
        for i, (in_size, out_size) in enumerate(zip(sizes[:-1], sizes[1:])):
            layers.append(nn.Linear(in_size, out_size))
            if i < len(sizes) - 2:
                layers.append(nn.ReLU())
        self.layers = nn.Sequential(*layers)
    
    def forward(self, x):
        return self.layers(x)


class Critic(nn.Module):
    '''
    Simple MLP Q-function.
    '''
    def __init__(self, obs_size, action_size, num_layers, num_units):
        super().__init__()
        #####################################################################

        self.net = MLP([obs_size + action_size] + ([num_units] * num_layers) + [1])

        #####################################################################

    def forward(self, x, a):
        #####################################################################

        value = self.net(torch.cat([x,a], dim=-1))

        #####################################################################
        return value


class Actor(nn.Module):
    '''
    Simple Tanh deterministic actor.
    '''
    def __init__(self, action_low, action_high,  obs_size, action_size, num_layers, num_units):
        super().__init__()
        #####################################################################

        self.net = MLP([obs_size] + ([num_units] * num_layers) + [action_size])
        
        #self.mu_net = nn.Sequential([nn.ReLU(),nn.Linear(num_units, action_size)])
        #self.std_net = nn.Sequential([nn.ReLU(),nn.Linear(num_units, action_size)])
        
        #####################################################################
        # store action scale and bias: the actor's output can be squashed to [-1, 1]
        self.action_scale = (action_high - action_low) / 2
        self.action_bias = (action_high + action_low) / 2

    def forward(self, x):
        #####################################################################
 
        mus = self.net(torch.Tensor(x))
        action = torch.tanh(mus)

        #####################################################################
        return action


class Agent:



    def __init__(self, env):
        # automatically select compute device
        self.device = 'cuda' if torch.cuda.is_available() else 'cpu'
        self.buffer_size: int = 50_000  # no need to change

        #########################################################################

        self.batch_size: int = 256
        self.gamma: float = 0.99  # MDP discount factor, 
        self.exploration_noise: float = 0.1  # epsilon for epsilon-greedy exploration
        
        
        #########################################################################
        # extract informations from the environment
        self.obs_size = np.prod(env.observation_space.shape)  # size of observations
        self.action_size = np.prod(env.action_space.shape)  # size of actions
        # extract bounds of the action space
        self.action_low = torch.tensor(env.action_space.low).float()
        self.action_high = torch.tensor(env.action_space.high).float()

        #####################################################################
        self.Actor = Actor(self.action_low, self.action_high, self.obs_size, self.action_size, 4, 512).to(self.device)
        self.q1 = Critic(self.obs_size, self.action_size, 4, 512).to(self.device)
        self.q2 = Critic(self.obs_size, self.action_size, 4, 512).to(self.device)


        self.target_agent = copy.deepcopy(self)
        self.target_agent.Actor.to(self.device)
        self.target_agent.q1.to(self.device)
        self.target_agent.q2.to(self.device)
        for p in self.target_agent.Actor.net.parameters():
            p.requires_grad = False
        for p in self.target_agent.q1.net.parameters():
            p.requires_grad = False
        for p in self.target_agent.q2.net.parameters():
            p.requires_grad = False


        

        self.pi_optimizer = optim.Adam(self.Actor.net.parameters(), lr=3e-4)
        self.q2_optimizer = optim.Adam(self.q2.net.parameters(), lr=3e-4)
        self.q1_optimizer = optim.Adam(self.q1.net.parameters(), lr=3e-4)

        #####################################################################
        # create buffer
        self.buffer = ReplayBuffer(self.buffer_size, self.obs_size, self.action_size, self.device)
        self.train_step = 0
    
    def train(self):
        '''
        Updates actor and critic with one batch from the replay buffer.
        '''
        obs, action, next_obs, done, reward = self.buffer.sample(self.batch_size)
        obs.to(self.device)
        action.to(self.device)
        next_obs.to(self.device)
        reward.to(self.device)

        #####################################################################
        with torch.no_grad():
            a2 = self.Actor(next_obs)
            q1_pi_targ = self.target_agent.q1(next_obs, a2)
            q2_pi_targ = self.target_agent.q2(next_obs, a2)
            q_pi_targ = torch.min(q1_pi_targ, q2_pi_targ)
            # q_pi_targ = q2_pi_targ
            
            
            #backup = reward + gamma * (q_pi_targ.reshape(reward.shape) - alpha * logp_a2)
            backup = reward + self.gamma * q_pi_targ.reshape(reward.shape)


        self.q1_optimizer.zero_grad()
        q1 = self.q1(obs, action)
        Q1_loss = torch.mean((q1.reshape(reward.shape) - backup) ** 2)
        Q1_loss.backward()

        self.q1_optimizer.step()


        self.q2_optimizer.zero_grad()
        q2 = self.q2(obs, action)
        Q2_loss = torch.mean((q2.reshape(reward.shape) - backup) ** 2)
        Q2_loss.backward()

        self.q2_optimizer.step()

        for p in self.q1.net.parameters():
            p.requires_grad = False
        for p in self.q2.net.parameters():
            p.requires_grad = False
        
        
        self.pi_optimizer.zero_grad()
        pi= self.Actor(obs)

        q1_pi = self.q1(obs, pi)
        q2_pi = self.q2(obs, pi)
        q_pi = torch.min(q1_pi, q2_pi)

        #loss_pi = (alpha * logprob - q_pi.reshape(reward.shape)).mean()
        loss_pi = (- q_pi.reshape(reward.shape)).mean()
        loss_pi.backward()
        self.pi_optimizer.step()

        for p in self.q1.net.parameters():
            p.requires_grad = True
        for p in self.q2.net.parameters():
            p.requires_grad = True

        Tau = 0.005


        for param_target, param in zip(self.target_agent.Actor.net.parameters(), self.Actor.net.parameters()):
            param_target.data.copy_(param_target.data * (1.0 - Tau) + param.data * Tau)

        for param_target, param in zip(self.target_agent.q1.net.parameters(), self.q1.net.parameters()):
            param_target.data.copy_(param_target.data * (1.0 - Tau) + param.data * Tau)

        for param_target, param in zip(self.target_agent.q2.net.parameters(), self.q2.net.parameters()):
            param_target.data.copy_(param_target.data * (1.0 - Tau) + param.data * Tau)
        #####################################################################

    def get_action(self, obs, train):
        '''
        Returns the agent's action for a given observation.
        The train parameter can be used to control stochastic behavior.
        '''
        #####################################################################
  
        with torch.no_grad():
            Tobs = torch.from_numpy(obs).float().to(self.device)
            action = self.Actor(Tobs).detach().cpu()
        
        #####################################################################
        return action

    def store(self, transition):
        '''
        Stores the observed transition in a replay buffer containing all past memories.
        '''
        obs, action, reward, next_obs, terminated = transition
        self.buffer.store(obs, next_obs, action, reward, terminated)



if __name__ == '__main__':

    WARMUP_EPISODES = 10  # initial episodes of uniform exploration
    TRAIN_EPISODES = 50  # interactive episodes
    TEST_EPISODES = 300  # evaluation episodes
    save_video = False
    verbose = True
    seeds = np.arange(10)  # seeds for public evaluation

    start = time.time()
    print(f'Running public evaluation.') 
    test_returns = {k: [] for k in seeds}

    for seed in seeds:

        # seeding to ensure determinism
        seed = int(seed)
        for fn in [random.seed, np.random.seed, torch.manual_seed]:
            fn(seed)
        torch.backends.cudnn.deterministic = True

        env = get_env()
        env.action_space.seed(seed)
        env.np_random, _ = seeding.np_random(seed)

        agent = Agent(env)

        for _ in range(WARMUP_EPISODES):
            run_episode(env, agent, mode='warmup', verbose=verbose, rec=False)

        for _ in range(TRAIN_EPISODES):
            run_episode(env, agent, mode='train', verbose=verbose, rec=False)

        for n_ep in range(TEST_EPISODES):
            video_rec = (save_video and n_ep == TEST_EPISODES - 1)  # only record last episode
            with torch.no_grad():
                episode_return = run_episode(env, agent, mode='test', verbose=verbose, rec=video_rec)
            test_returns[seed].append(episode_return)

    avg_test_return = np.mean([np.mean(v) for v in test_returns.values()])
    within_seeds_deviation = np.mean([np.std(v) for v in test_returns.values()])
    across_seeds_deviation = np.std([np.mean(v) for v in test_returns.values()])
    print(f'Score for public evaluation: {avg_test_return}')
    print(f'Deviation within seeds: {within_seeds_deviation}')
    print(f'Deviation across seeds: {across_seeds_deviation}')

    print("Time :", (time.time() - start)/60, "min")
