#include <vector>
#include <iostream>
#include "ObjetCompose.h"
#include "../objetmobile/objetmobile.h"
#include "../Obstacles/Obstacles.h"
#include "../Champforces/Champforces.h"
#include "../Systeme/Systeme.h"
using namespace std;

//pour copier
ObjetCompose* ObjetCompose::copie() const{
    ObjetCompose* o(new ObjetCompose);
    for(auto obj : mob_compo){
        o->ajouter_mob(obj->copie());
    }
    for(auto obs: obs_compo){
        o->ajouter_obs(obs->copie());
    }
    for(auto chp: chp_compo){
        o->ajouter_chp(chp->copie());
    }
    for(auto cp : comp_compo){
        o->ajouter_comp(cp->copie());
    }
    return o;
}

//getteurs des tableaux d'element
vector<ObjetCompose*> ObjetCompose::get_comp() const{
    vector<ObjetCompose*> out;
    for(auto comp : comp_compo){
        out.push_back(comp->copie());
    }
    return out;
}

vector<ObjetMobile*> ObjetCompose::get_mob() const{
    vector<ObjetMobile*> out;
    for(auto obj : mob_compo){
        out.push_back(obj->copie());
    }
    return out;
}

vector<Obstacle*> ObjetCompose::get_obs() const{
    vector<Obstacle*> out;
    for(auto obs : obs_compo){
        out.push_back(obs->copie());
    }
    return out;
}

//pour ajouter l'objet composer a un systeme on ajoute chaque composante a ce systeme
void ObjetCompose::ajoute_a(Systeme& s){
	for(size_t i(0); i<obs_compo.size();++i) {
        obs_compo[i]->copie()->ajoute_a(s);
	}
	obs_compo.clear();
    //ici on vide les pointeurs sur les composants,
	// sinon on se retrouve avec une situation ou on a beaucoup de pointeurs en allocation dynamique,
	//creant alors des segmentation fault loors des destructions
	for(size_t i(0); i<mob_compo.size();++i) {
        mob_compo[i]->copie()->ajoute_a(s);
	}
	mob_compo.clear();
	for(size_t i(0); i<chp_compo.size();++i) {
        chp_compo[i]->copie()->ajoute_a(s);
	}
	chp_compo.clear();
	for(size_t i(0); i<comp_compo.size();++i) {
        comp_compo[i]->copie()->ajoute_a(s);
	}
	comp_compo.clear();
}

//pour ajouter des composants
void ObjetCompose::ajouter_mob(ObjetMobile* o){
	mob_compo.push_back(o);
}

void ObjetCompose::ajouter_obs(Obstacle* o){
	obs_compo.push_back(o);
}

void ObjetCompose::ajouter_chp(ChampsForces* o){
	chp_compo.push_back(o);
}

void ObjetCompose::ajouter_comp(ObjetCompose* o){
	comp_compo.push_back(o);
}

//affichage
ostream& ObjetCompose::affiche(ostream& sortie) const{
	
	if( mob_compo.size() != 0) {
		sortie << "Objets mobiles :" << endl;

		for (auto& elt : mob_compo) {
			elt->affiche(sortie);
			sortie << endl;
		}
	}
	
	if( obs_compo.size() != 0) {
		sortie << endl << "Obstacles :" << endl;
		for (auto& obs: obs_compo) {
			sortie << *obs << endl;
		}
	}
	
	if( chp_compo.size() != 0) {
		sortie << endl << "Champs de forces :" << endl;
		for(auto& chp : chp_compo) {
			sortie << *chp << endl;
		}
	}
	if( comp_compo.size() != 0) {
		sortie << endl << "Objets Composes :" << endl ;
		for(auto& oc : comp_compo) {
			sortie << *oc << endl;
		}
	}
	return sortie;
}

//getteurs
Obstacle* ObjetCompose::get_obs(unsigned int i){
	if(i<1) i=1;
	if(i>obs_compo.size()) i=obs_compo.size();
	return obs_compo[i-1];
}
//on demande le ième composant et obtenons le [i-1] pour commencer a compter de 1 et non 0
ObjetMobile* ObjetCompose::get_mob(unsigned int i){
	if(i<1) i=1;
	if(i>mob_compo.size()) i=mob_compo.size();
	return mob_compo[i-1];
}

ChampsForces* ObjetCompose::get_chp(unsigned int i){
	if(i<1) i=1;
	if(i>chp_compo.size()) i=chp_compo.size();
	return chp_compo[i-1];
}

ObjetCompose* ObjetCompose::get_comp(unsigned int i){
	if(i<1) i=1;
	if(i>comp_compo.size()) i=comp_compo.size();
	return comp_compo[i-1];
}

//agit_sur qui fait agir chaque composante sur l'objet mobile
void ObjetCompose::agit_sur(ObjetMobile & b){
	if( mob_compo.size() != 0) {
		for (auto& om : mob_compo) {
			om->agit_sur(b);
		}
	}
	
	if( obs_compo.size() != 0) {
		for (auto& obs: obs_compo) {
			obs->agit_sur(b);
		}
	}
	
	if( chp_compo.size() != 0) {
		for(auto& chp : chp_compo) {
			chp->agit_sur(b);
		}
	}
	if( comp_compo.size() != 0) {
		for(auto& oc : comp_compo) {
			oc->agit_sur(b);
		}
	}
}

//s'assure de la destruction des valeurs pointe par la composition, pour le destructeur
void ObjetCompose::clean(){
	for (auto& mob : mob_compo){
		delete mob;
	}
	mob_compo.clear();
	for (auto& obs : obs_compo){
		delete obs;
	}
	obs_compo.clear();
	for (auto& chp : chp_compo){
		delete chp;
	}
	chp_compo.clear();	
	for (auto& comp : comp_compo){
		delete comp;
	}
	comp_compo.clear();
}



