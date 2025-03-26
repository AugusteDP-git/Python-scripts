#pragma once
#include <iostream>
#include <cmath>
#include <string>
#include "../Vecteurs/Methodes.h"
#include "../objetmobile/objetmobile.h"
#include "../Affichable/Affichable.h"
#include "../Dessinable/Dessinable.h"
#include "../support_a_dessin/support_a_dessin.h"

class Systeme;

class Balle : public ObjetMobile, public Affichable {
public:

	Balle(double ray, double mv, Vecteur p=3, Vecteur vit=3, Vecteur force = 3, std::string nom="", int deg_lib=3)
	:ObjetMobile(ray, mv, p,vit, force, nom, deg_lib)
	{};
	
	Balle(const Balle& ) = default;
	
	virtual Vecteur evolution()const override;

    virtual void set_dP(Vecteur) override;
	
	virtual std::ostream& affiche(std::ostream& sortie)const;

    virtual Vecteur get_vit() const override;

    virtual Vecteur get_pos() const override;

    virtual ObjetMobile* copie() const override;
	
    virtual void ajoute_a(Systeme& s) override;
	virtual void dessine_sur(SupportADessin& support) override {
		support.dessine(*this);
	}

};
	


