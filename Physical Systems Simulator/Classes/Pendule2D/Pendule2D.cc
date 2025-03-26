#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include "Pendule2D.h"
#include "../constantes/constantes.h"
#include "../Balle/Balle.h"
#include "../Systeme/Systeme.h"
using namespace std;

void Pendule2D::ajoute_a(Systeme &s){
    s.ajouter_mob(new Pendule2D(*this));
}

ostream& operator<<(ostream& sortie, Pendule2D p)
{
    p.affiche(sortie);
    return sortie;
}

ObjetMobile* Pendule2D::copie() const{
    return new Pendule2D(*this);
}

ostream& Pendule2D::affiche(ostream& sortie)const{
	sortie << "Pendule: " << nom << endl;
	sortie << masse() << " # masse pendule" << endl;
	sortie << longueur_ << " # longueur pendule" << endl;
	sortie << frottements_ << " # frottement pendule" << endl;
	sortie << origine_ << " # origine pendule" << endl;
	sortie << d_ << " # direction pendule" << endl;
	sortie << P[0] << " # theta pendule" << endl;
	sortie << dPdt[0] << " # theta point pendule" << endl;
	sortie << evolution()[0] << " # f() pendule" << endl;
	sortie << getPosition() << " # position bout pendule" << endl;
	sortie << getVitesse() << " # vitesse bout pendule" << endl;
		
		
	return sortie;
}
	

Vecteur Pendule2D::evolution()const{
	double f( (1 / (masse() * longueur_))*(( cos(P[0])*(force*d_))
	-sin(P[0])*(force*z_repere)
	-(frottements_/longueur_)*dPdt[0]));
	
	return Vecteur(vector<double>{f});
}

Vecteur Pendule2D::getPosition() const{
	return origine_ + longueur_*cos(P[0])*z_repere + 
	longueur_*sin(P[0])*d_;
	
}

Vecteur Pendule2D::getVitesse() const{
	return longueur_*dPdt[0] * (cos(P[0])*d_ - 
	sin(P[0])*z_repere);
	
}

void Pendule2D::setTheta(Vecteur v) {
	if (v.GetSize() == 3) {
        if((abs(v[0]) < epsilon) and (abs(v[1]) < epsilon) and (abs(v[2]) < epsilon)) {
			dPdt_(Vecteur(vector<double>{0}));
		}
		else {
            if (abs(v[0]) >= epsilon ) {
				dPdt_(Vecteur(vector<double>{(v[0]) / (longueur_ * cos(P[0]) * d_[0])}));
			}
            else if( abs(v[1]) >= epsilon ) {
				dPdt_(Vecteur(vector<double>{(v[1]) / (longueur_ * cos(P[0]) * d_[1])}));
			}
			
            else if( abs(v[2]) >= epsilon ) {
				dPdt_(Vecteur(vector<double>{(v[2]) / (longueur_ * sin(P[0]) * z_repere[1])}));
			}
		}
	}
}

void Pendule2D::set_dP(Vecteur p){
    setTheta(p);
}

Vecteur Pendule2D::get_vit() const{
    return getVitesse();
}

Vecteur Pendule2D::get_pos() const{
    return getPosition();
}
Vecteur Pendule2D::Origine() const{
    return origine_;
}
