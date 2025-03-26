#pragma once
#include "../Vecteurs/Methodes.h"
#include "../objetmobile/objetmobile.h"
#include "../Affichable/Affichable.h"
#include "../Balle/Balle.h"
#include "../Dessinable/Dessinable.h"

class Systeme;

//Obstacle est une classe mère virtuelle pure, qui est affichable et dessinable.
class Obstacle: public Dessinable, public Affichable{
protected:
	Vecteur origine;
	//on décrit ici un obstacle que par son origine
public:
	//constructeur et destructeur
    Obstacle(Vecteur origine = 3):origine(origine) {}
	
	virtual ~Obstacle() {}
	
	//trouve le point le plus proche entre l'obtsacle et un objet mobile pour gérer les chocs
	virtual Vecteur point_plus_proche(const ObjetMobile& o)=0;
	
	//pour l'affichage
	virtual std::ostream& affiche(std::ostream& sortie)const override;
	
	//pour agir sur les objet mobile (choc)
	void agit_sur(ObjetMobile& b1);
	
	//pour obtenir l'origine d'un obtsalce
    Vecteur Origine() const ;

	//pour être ajouté a un système
    virtual void ajoute_a(Systeme& s);

    virtual Obstacle* copie() const = 0;

   
};

