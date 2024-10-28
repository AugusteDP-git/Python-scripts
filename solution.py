import os
import typing
from sklearn.gaussian_process.kernels import *
import numpy as np
from sklearn.gaussian_process import GaussianProcessRegressor
from sklearn.model_selection import cross_val_score
import matplotlib.pyplot as plt
from matplotlib import cm
from sklearn.cluster import KMeans
from sklearn.preprocessing import StandardScaler



EXTENDED_EVALUATION = True
EVALUATION_GRID_POINTS = 300 

COST_W_UNDERPREDICT = 50.0
COST_W_NORMAL = 1.0

class Model(object):
 

    def __init__(self):
        self.rng = np.random.default_rng(seed=0)
        self.model = None
        self.kmeans = None
        self.kernels = [
            ConstantKernel(1.0, (1e-3, 1e3)) * Matern(length_scale = 1.0, length_scale_bounds = (1e-5, 1e5)) + WhiteKernel(1, (1e-5, 1e5)),
            ConstantKernel(1.0, (1e-3, 1e3)) * ExpSineSquared(length_scale= 1.0, length_scale_bounds = (1e-3, 1e3)),
            ConstantKernel(1.0, (1e-3, 1e3)) * RationalQuadratic(length_scale = 1.0, length_scale_bounds = (1e-3, 1e3)),
            ConstantKernel(1.0, (1e-3, 1e3)) * RBF(length_scale = 1.0, length_scale_bounds = (1e-5, 1e5)) + WhiteKernel(1, (1e-5, 1e5)),
        ]
    

    def generate_predictions(self, test_coordinates: np.ndarray, test_area_flags: np.ndarray) -> typing.Tuple[np.ndarray, np.ndarray, np.ndarray]:

        gp_mean = np.zeros(test_coordinates.shape[0], dtype=float)
        gp_std = np.zeros(test_coordinates.shape[0], dtype=float)

        for i,x in enumerate(test_coordinates):
          x = np.array(x).reshape(1, -1)
          x_cluster = self.kmeans.predict(x)
          for gpr in self.model:
            if x_cluster == gpr[1]:
              y_mean, y_std = gpr[0].predict(x, return_std = True)
              break

          gp_mean[i] = y_mean
          gp_std[i] = y_std

        predictions = np.zeros(test_coordinates.shape[0], dtype=float)

        for k in range(len(gp_mean)):
          if bool(test_area_flags[k]) == True:
            predictions[k] = gp_mean[k] + 1.96 * gp_std[k]

          else: predictions[k] = gp_mean[k]

        return predictions, gp_mean, gp_std

    def clustering(self, train_coordinates, train_targets, kernel):
      n_clusters = np.linspace(10,2000,20, dtype = int)

      best_gprs = []
      max_log_likelihood = -np.inf
      optimal_kmeans = None

      for n_cluster in n_clusters:
        gprs = []
        log_likelihood = 0

        kmeans = KMeans(n_clusters=n_cluster)
        clusters = kmeans.fit_predict(train_coordinates)

        for k in np.unique(clusters):
          mask = (k == clusters)
          X_cluster = train_coordinates[mask]
          Y_cluster = train_targets[mask]

          gpr = GaussianProcessRegressor(kernel = kernel, normalize_y=True).fit(X_cluster, Y_cluster)
          gprs.append([gpr,k])
          log_likelihood += gpr.log_marginal_likelihood_value_

        if log_likelihood > max_log_likelihood:
          max_log_likelihood = log_likelihood
          best_gprs = gprs
          optimal_kmeans = kmeans

      return optimal_kmeans, best_gprs, max_log_likelihood


    def train_model(self, train_targets: np.ndarray, train_coordinates: np.ndarray, train_area_flags: np.ndarray):
        
        best_log_marginal_likelihood = -np.inf



        for kernel in self.kernels:
          kmeans, gprs, log_likelihood = self.clustering(train_coordinates, train_targets, kernel)

          if log_likelihood > best_log_marginal_likelihood:
            self.model = gprs
            self.kmeans = kmeans
            best_log_marginal_likelihood = log_likelihood

        pass


def calculate_cost(ground_truth: np.ndarray, predictions: np.ndarray, area_flags: np.ndarray) -> float:
  
    assert ground_truth.ndim == 1 and predictions.ndim == 1 and ground_truth.shape == predictions.shape

    cost = (ground_truth - predictions) ** 2
    weights = np.ones_like(cost) * COST_W_NORMAL

    mask = (predictions < ground_truth) & [bool(area_flag) for area_flag in area_flags]
    weights[mask] = COST_W_UNDERPREDICT

    return np.mean(cost * weights)


def check_within_circle(coordinate, circle_parameters):
  
    return (coordinate[0] - circle_parameters[0])**2 + (coordinate[1] - circle_parameters[1])**2 < circle_parameters[2]**2

def identify_city_area_flags(grid_coordinates):
   
    circles = np.array([[0.5488135, 0.71518937, 0.17167342],
                    [0.79915856, 0.46147936, 0.1567626 ],
                    [0.26455561, 0.77423369, 0.10298338],
                    [0.6976312,  0.06022547, 0.04015634],
                    [0.31542835, 0.36371077, 0.17985623],
                    [0.15896958, 0.11037514, 0.07244247],
                    [0.82099323, 0.09710128, 0.08136552],
                    [0.41426299, 0.0641475,  0.04442035],
                    [0.09394051, 0.5759465,  0.08729856],
                    [0.84640867, 0.69947928, 0.04568374],
                    [0.23789282, 0.934214,   0.04039037],
                    [0.82076712, 0.90884372, 0.07434012],
                    [0.09961493, 0.94530153, 0.04755969],
                    [0.88172021, 0.2724369,  0.04483477],
                    [0.9425836,  0.6339977,  0.04979664]])

    area_flags = np.zeros((grid_coordinates.shape[0],))

    for i,coordinate in enumerate(grid_coordinates):
        area_flags[i] = any([check_within_circle(coordinate, circ) for circ in circles])

    return area_flags

def execute_extended_evaluation(model: Model, output_dir: str = '/results'):
    
    print('Performing extended evaluation')

    grid_lat, grid_lon = np.meshgrid(
        np.linspace(0, EVALUATION_GRID_POINTS - 1, num=EVALUATION_GRID_POINTS) / EVALUATION_GRID_POINTS,
        np.linspace(0, EVALUATION_GRID_POINTS - 1, num=EVALUATION_GRID_POINTS) / EVALUATION_GRID_POINTS,
    )
    visualization_grid = np.stack((grid_lon.flatten(), grid_lat.flatten()), axis=1)
    grid_area_flags = identify_city_area_flags(visualization_grid)

    predictions, gp_mean, gp_stddev = model.generate_predictions(visualization_grid, grid_area_flags)
    predictions = np.reshape(predictions, (EVALUATION_GRID_POINTS, EVALUATION_GRID_POINTS))
    gp_mean = np.reshape(gp_mean, (EVALUATION_GRID_POINTS, EVALUATION_GRID_POINTS))

    vmin, vmax = 0.0, 65.0

    fig, ax = plt.subplots()
    ax.set_title('Extended visualization of task 1')
    im = ax.imshow(predictions, vmin=vmin, vmax=vmax)
    cbar = fig.colorbar(im, ax=ax)

    figure_path = os.path.join(output_dir, 'extended_evaluation.pdf')
    fig.savefig(figure_path)
    print(f'Saved extended evaluation to {figure_path}')

    plt.show()
    
def extract_area_information(train_x: np.ndarray, test_x: np.ndarray) -> typing.Tuple[np.ndarray, np.ndarray, np.ndarray, np.ndarray]:
    
    train_coordinates = np.zeros((train_x.shape[0], 2), dtype=float)
    train_area_flags = np.zeros((train_x.shape[0],), dtype=bool)
    test_coordinates = np.zeros((test_x.shape[0], 2), dtype=float)
    test_area_flags = np.zeros((test_x.shape[0],), dtype=bool)


    train_coordinates = train_x[:, :2]
    train_area_flags = train_x[:, 2].astype(bool)
    test_coordinates = test_x[:, :2]
    test_area_flags = test_x[:, 2].astype(bool)

    assert train_coordinates.shape[0] == train_area_flags.shape[0] and test_coordinates.shape[0] == test_area_flags.shape[0]
    assert train_coordinates.shape[1] == 2 and test_coordinates.shape[1] == 2
    assert train_area_flags.ndim == 1 and test_area_flags.ndim == 1

    return train_coordinates, train_area_flags, test_coordinates, test_area_flags


def main():
    train_x = np.loadtxt('train_x.csv', delimiter=',', skiprows=1)
    train_y = np.loadtxt('train_y.csv', delimiter=',', skiprows=1)
    test_x = np.loadtxt('test_x.csv', delimiter=',', skiprows=1)

    scaler = StandardScaler()
    train_x = scaler.fit_transform(train_x)
    test_x = scaler.transform(test_x)
    train_coordinates, train_area_flags, test_coordinates, test_area_flags = extract_area_information(train_x, test_x)

    model = Model()

    print('Training model')
    model.train_model(train_y, train_coordinates, train_area_flags)

    print('Predicting on test features')
    predictions = model.generate_predictions(test_coordinates, test_area_flags)
    print(predictions)

    if EXTENDED_EVALUATION:
        execute_extended_evaluation(model, output_dir='.')


if __name__ == "__main__":
    main()
