#pragma once
#include <string>
#include "../Vecteurs/Methodes.h"
#include "../objetmobile/objetmobile.h"
#include "../Affichable/Affichable.h"

class Systeme;

//Cette classe est affichable
class ChampsForces : public Affichable{
protected:
	//elle est définie par une intensité et peut avoir un nom
	Vecteur intensite;
	std::string nom;
	
public:
	//constructeur et destructeur
    ChampsForces(Vecteur v=3, std::string nom ="")
	:intensite(v), nom(nom)
	{}
	
	virtual ~ChampsForces() {}

    virtual ChampsForces* copie() const;
    
	//teste si un objetmobile est dans la zone du champ de force,
	//cette zone étant infinie on retourne toujours "true". 
	//Cette méthode est surtout nécessaire a sa sous-classe Vent
    virtual bool zone(ObjetMobile& b) const {return true;}

	//pour ajouter un champs de force a un système
    virtual void ajoute_a(Systeme& s);

	//pour l'affichage
    virtual std::ostream& affiche(std::ostream& sortie)const;

	//pour obtenir un vecteur unitaire dans la direction d'intensité
    Vecteur normale() const;
    
    //pour agir sur un objet mobile
	void agit_sur(ObjetMobile & b);

	//pour obtenir la norme de l'intensité
    double V0() const;
};

