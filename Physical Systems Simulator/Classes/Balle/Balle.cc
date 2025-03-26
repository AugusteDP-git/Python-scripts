#include <iostream>
#include <cmath>
#include <string>
#include "../Vecteurs/Methodes.h"
#include "Balle.h"
#include "../objetmobile/objetmobile.h"
#include "../Systeme/Systeme.h"
using namespace std;


ostream& Balle::affiche(ostream& sortie)const{
		sortie << "Balle: " << nom << endl;
		sortie << masse() << " # masse" << endl;
		sortie << rayon << " # rayon" << endl;
		sortie << masse_vol << " # masse volumique" << endl;
		sortie << force << " # force" << endl;
		ObjetMobile::affiche(sortie);
		sortie << evolution() << " # f() (evolution)" << endl;
		return sortie;
	}
	
Vecteur Balle::get_pos() const{
    return P;
}
Vecteur Balle::get_vit() const{
    return dPdt;
}
Vecteur Balle::evolution()const{
	return force*(1/masse());
}

ObjetMobile* Balle::copie() const {
    return new Balle(*this);
}

void Balle::set_dP(Vecteur p){
    this->dPdt_(p);
}

void Balle::ajoute_a(Systeme &s){
    s.ajouter_mob(new Balle(*this));
}

