#include <iostream>
#include "Brique.h"
#include "../Systeme/Systeme.h"
using namespace std;

Vecteur Brique::Longueur() const{
    return longueur;
}
Vecteur Brique::Largeur() const{
    return largeur;
}

//affichage d'une brique
ostream& Brique::affiche(ostream& sortie)const {
	sortie << "Brique : " <<endl;
	Obstacle::affiche(sortie);
	sortie << longueur << " #longueur Brique" << endl;
	sortie << largeur << " #largeur Brique" << endl;
	sortie << hauteur << " #hauteur Brique" << endl;
	return sortie;
} 

//pour obtenir la hateur comme un vecteur
Vecteur Brique::Hauteur() const{
	Vecteur h(longueur^largeur);
	h=~h;
	h=h*hauteur;
	return h;
}

	
//cherhce le point de la brique le plus proche d'un objet mobile
Vecteur Brique::point_plus_proche(const ObjetMobile& o) {
	Vecteur x2;
	Vecteur h(Hauteur());
	Vecteur O(this->Origine());
	Vecteur n(~h);
	Vecteur el(~largeur);
	Vecteur eL(~longueur);
	//calcule le point le plus proche de la première face de la brique
    Vecteur x(pointparface(O, -n, el, eL, o.getParam()));
	x2=x;
	//idem pour la 2ème face
    x=pointparface(O, -el, -n, eL, o.getParam());
	if((o.getParam()-x).norme()<(o.getParam()-x2).norme()){
		x2=x;
	}//on conserve le meilleur résultat
	//on itère pour les 4 autres faces
    x=pointparface(O, -eL, -n, el, o.getParam());
	if((o.getParam()-x).norme()<(o.getParam()-x2).norme()){
		x2=x;
	}
	O+=longueur+largeur+Hauteur();
    x=pointparface(O, n, -el, -eL, o.getParam());
	if((o.getParam()-x).norme()<(o.getParam()-x2).norme()){
		x2=x;
	}
    x=pointparface(O, el, -n, -eL, o.getParam());
	if((o.getParam()-x).norme()<(o.getParam()-x2).norme()){
		x2=x;
	}
    x=pointparface(O, eL, -n, -el, o.getParam());
	if((o.getParam()-x).norme()<(o.getParam()-x2).norme()){
		x2=x;
	}
	return x2;
}

//trouve le point d'une face le plus proche d'un point de l'espace
Vecteur Brique::pointparface(Vecteur O, Vecteur n, Vecteur el, Vecteur eL, Vecteur P) const {
	el=~el;
	eL=~eL;
	
	Vecteur x2(P+((O-P)*n)*n);
	//le point le plus proche du plan de la face du point de l'espace
	
	double x2L((x2-O)*eL);
	double x2l((x2-O)*el);

	double L(longueur.norme());
	double l(largeur.norme());

    //ici on cherhce a ce que le point du plan soit bien dans la face
	if(x2L>L) {
		x2-=(x2L-L)*eL;
	}
	else {
		 if(x2L<0) {
			 x2-=x2L*eL;
		 }
	}
	if(x2l>l) {
		x2-=(x2l-l)*el;
	}
	else {
		 if(x2l<0) {
			 x2-=x2l*el;
		 }
	}
	return x2;
}

//pour être ajouté a un système
void Brique::ajoute_a(Systeme &s){
    s.ajouter_obs(new Brique(*this));
}

Obstacle* Brique::copie() const{
    return new Brique(*this);
}
