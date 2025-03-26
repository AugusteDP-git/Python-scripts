#include <iostream>
#include <cmath>
#include "Obstacles.h"
#include "../Systeme/Systeme.h"
using namespace std;

//pour l'affichage
ostream& Obstacle::affiche(ostream& sortie)const{
	sortie << origine <<" # origine" << endl;
	return sortie;
}

//pour obtenir l'origine
Vecteur Obstacle::Origine() const{
	return origine;
}

//gestion des chocs entre objet mobile et obtsalce
void Obstacle::agit_sur(ObjetMobile& b1){

    if((b1.get_pos() - point_plus_proche(b1)).norme() >= b1.Rayon()) {
        return;//s'il n'y a pas de contact il n'y a pas de choc
    }

    Vecteur n(~(b1.get_pos() - point_plus_proche(b1)));
    double alpha(b1.Restitution());
    double lambda(1.0+alpha);
	double Fn1(b1.getForce()*n);

	if(Fn1<0) {
		b1.ajoute_force(-Fn1*n);
    }
    double v(-b1.get_vit()*n);
	double mu(b1.Frottement());
    Vecteur vc(b1.get_vit()+v*n);
    Vecteur dv(3);
    if((7.0*mu*lambda*v)>=2.0*vc.norme()){
        dv=(lambda*v*n)-((2.0/7.0)*vc);
	} else {
		dv=lambda*v*(n-mu*(~vc));
	}
    b1.set_dP(b1.get_vit()+dv);
	return;
}

void Obstacle::ajoute_a(Systeme& s){
	s.ajouter_obs(this);
}
