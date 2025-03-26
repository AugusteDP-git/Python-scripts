#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "../Vecteurs/Methodes.h"
#include "../objetmobile/objetmobile.h"
#include "../Obstacles/Obstacles.h"
#include "../Dessinable/Dessinable.h"
#include "../Champforces/Champforces.h"
#include "../Systeme/Systeme.h"
#include "../Affichable/Affichable.h"

class ObjetCompose : public Dessinable, public Affichable {
	protected:
	//4 tableaux d'element qui peuvent composer l'objet composé :
	//objet mobile
	std::vector<ObjetMobile*> mob_compo;
	//obstacle
	std::vector<Obstacle*> obs_compo;
	//champs de force
	std::vector<ChampsForces*> chp_compo;
	//objet composé
	std::vector<ObjetCompose*> comp_compo;
	
	//methode interne pour la destruction
	void clean();
	
	public :
	
    //pour ajouter un objet_composé a un systeme
	void ajoute_a(Systeme& s);
	
	//pour ajouter des elements dans nos compositions
	virtual void ajouter_mob(ObjetMobile* o);
	virtual void ajouter_obs(Obstacle* o);
	virtual void ajouter_chp(ChampsForces* o);
	virtual void ajouter_comp(ObjetCompose* o);
	

	virtual void dessine_sur(SupportADessin& support) override {
		support.dessine(*this);
	}
	
    ObjetCompose* copie() const;

    std::vector<ObjetCompose*> get_comp() const;
    std::vector<ObjetMobile*> get_mob() const;
    std::vector<Obstacle*> get_obs() const;
    
    //constructeur par defaut, par copie et destructeur
	ObjetCompose() = default;
	ObjetCompose(ObjetCompose const&) = delete;
	 virtual ~ObjetCompose(){
		 clean();
		 }
    //pour l'affichage
	std::ostream& affiche(std::ostream& sortie) const override;
	
	//getteurs 
	Obstacle* get_obs(unsigned int i);
	ObjetMobile* get_mob(unsigned int i);
	ChampsForces* get_chp(unsigned int i);
	ObjetCompose* get_comp(unsigned int i);
	
	//pour agir sur des objets mobiles
	void agit_sur(ObjetMobile & b);

};
