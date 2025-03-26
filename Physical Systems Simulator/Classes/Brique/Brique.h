#pragma once
#include "../Obstacles/Obstacles.h"
#include "../Vecteurs/Methodes.h"
#include "../Dessinable/Dessinable.h"
#include "../support_a_dessin/support_a_dessin.h"
#include "../Affichable/Affichable.h"

class Systeme;

//Une brique est un obstacle
class Brique: public Obstacle {
private:
	Vecteur longueur;
	Vecteur largeur;
	double hauteur;
	//la hauteur est représenté comme un double car on connait sa direction : orthogonal au plan longueur-largeur
	

	Vecteur pointparface(Vecteur O, Vecteur n, Vecteur el, Vecteur eL, Vecteur P) const;
	//methode interne pour calculer le point le plus proche d'une face par rapport a un point de l'espace
	
public:
	
	Brique(Vecteur origine, Vecteur lo,Vecteur la, double hauteur)
	: Obstacle(origine), longueur(lo), largeur(la), hauteur(hauteur) 
	{
		orth(longueur,largeur);
		//on s'assure de l'orthogonalisation de la longueur et la largueur
	}
	
	virtual ~Brique() {}
	
	//pour l'affichage
	virtual std::ostream& affiche(std::ostream& sortie)const override;
	
	//pour pouvoir trouver le point de la brique le plus proche d'un objet mobile (pour gerer les chocs)
	Vecteur point_plus_proche(const ObjetMobile& o) override;
	
	virtual void dessine_sur(SupportADessin& support) override {
		support.dessine(*this);
	}
    Vecteur Largeur() const;
    Vecteur Longueur() const;
    Vecteur Hauteur() const;

	//pour être ajouté a un système
	virtual void ajoute_a(Systeme& s) override;
	
	virtual Obstacle* copie() const override;
	
};
