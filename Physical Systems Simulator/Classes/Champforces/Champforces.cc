#include <iostream>
#include <cmath>
#include <string>
#include "../Vecteurs/Methodes.h"
#include "../objetmobile/objetmobile.h"
#include "Champforces.h"
#include "../Balle/Balle.h"
#include "../constantes/constantes.h"
#include "../Systeme/Systeme.h"
using namespace std;
	
ChampsForces* ChampsForces::copie() const{
    return new ChampsForces(*this);
}

//pour agir sur des objets mobiles
void ChampsForces::agit_sur(ObjetMobile & b){
    double rho_air(1.2);
	Vecteur force(intensite);
	force *= b.masse() - b.volume()*rho_air;
	b.ajoute_force(force);

}
//affichage
ostream& ChampsForces::affiche(ostream& sortie)const{
		if (nom != ""){
		 	sortie << "\""<< nom << "\" ";
		}
		sortie << endl;
		sortie << intensite << " # intensite" << endl;
		return sortie;
}

//pour etre ajouté a un système
void ChampsForces::ajoute_a(Systeme& s) {
    s.ajouter_chp(new ChampsForces(*this));
}

//pour obtenir la norme de l'intensité
double ChampsForces::V0() const{
    return intensite.norme();
}

//pour obtenir un vecteur unitaire de l'intensité
Vecteur ChampsForces::normale() const{
    return ~intensite;
}


