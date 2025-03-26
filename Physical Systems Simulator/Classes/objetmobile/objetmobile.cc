#include <vector>
#include <iostream>
#include "objetmobile.h"
#include "../Affichable/Affichable.h"
using namespace std;

ostream& ObjetMobile::affiche(ostream& sortie) const{
		sortie << P << " # position" << endl;
		sortie << dPdt << " # vitesse" << endl;
		return sortie;
}

void ObjetMobile::Force_(Vecteur f){
    force = f;
}
	
Vecteur ObjetMobile::getParam() const
{
	return P;
}

Vecteur ObjetMobile::getdPdt() const
{
	return dPdt;
}

void ObjetMobile::ajoute_force(Vecteur const& df)
{
	force += df;
}

void ObjetMobile::P_(Vecteur p) {
		P=p;
}

void ObjetMobile::dPdt_(Vecteur p) {
		dPdt=p;
}

double ObjetMobile::volume() const {
    return ((4.0*M_PI*rayon*rayon*rayon)/3.0);
}

double ObjetMobile::masse() const {
	return masse_vol*volume();
}

double ObjetMobile::Rayon() const{
	return rayon;
}

double ObjetMobile::Restitution() const{
	return restitution;
}
	
double ObjetMobile::Frottement() const{
	return frottement;
}

Vecteur ObjetMobile::getForce() const{
	return force;
}

void ObjetMobile::agit_sur(ObjetMobile& b2){
	double R1(this->Rayon());
	double R2(b2.Rayon());
    Vecteur x1(this->get_pos());
    Vecteur x2(b2.get_pos());
	Vecteur dist(x1-x2);
	
	if(dist.norme()>R1+R2) {return;}//s'il n'y a pas de contact il n'y a pas de choc
	
	Vecteur n(~(dist));
	double alpha(b2.Restitution());

	double m1(this->masse());
	double m2(b2.masse());
	double lambda(((1+alpha)*m2)/(m1+m2));
	double Fn1(this->getForce()*n);
	double Fn2(b2.getForce()*n);
	if(Fn1<0) {
		this->ajoute_force(-Fn1*n);
		b2.ajoute_force(Fn1*n);
    }
	if(Fn2<0) {
		this->ajoute_force(Fn2*n);
		b2.ajoute_force(-Fn2*n);
	}
    Vecteur v1(this->get_vit());
    Vecteur v2(b2.get_vit());
	double v((v2-v1)*n);
	double mu(b2.Frottement());
	Vecteur vc(v1-v2+v*n);
	Vecteur dv;
    if((7*mu*(1+alpha)*v)>=2*vc.norme()){
		dv=lambda*v*n;
		dv-=((2*m2)/(7*(m1+m2)))*vc;
	} else {
		dv=lambda*v*(n-mu*(~vc));
	}
    this->set_dP(v1+dv);
    b2.set_dP(v2-(m1/m2)*dv);
	return;
	}



