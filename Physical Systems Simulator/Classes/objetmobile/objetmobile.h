	#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "../Vecteurs/Methodes.h"
#include "../Dessinable/Dessinable.h"

class Systeme;

class ObjetMobile:public Dessinable{
	protected :
	
	Vecteur P;
	Vecteur dPdt;
	Vecteur force;
	std::string nom;
	int deg_lib;//pour degre de liberte
	double rayon;
	double masse_vol;
	//Gestion des chocs entre sphère mobiles :
    static constexpr double restitution=0.8;
    static constexpr double frottement=0.01;
	//les valeurs sont ici arbitraires : a modifier
	
	public:
	
	ObjetMobile(double ray, double masse_volumique, Vecteur p=3, Vecteur dpdt=3, Vecteur force=3, std::string nom ="", unsigned int d=3)
	: P(p), dPdt(dpdt), force(force), nom(nom), deg_lib(d), rayon(ray), masse_vol(masse_volumique)
	{
		if(P.GetSize()!=d ){
			Vecteur v(d);
			P.memetaille(v);
		}
		if (dPdt.GetSize()!=d){
			Vecteur v(d);
			dPdt.memetaille(v);
		}
	}
	ObjetMobile(const ObjetMobile& autre) = default;

	virtual Vecteur getParam() const;
	
	virtual Vecteur getdPdt() const;
	
	virtual Vecteur evolution() const = 0;
		
	virtual std::ostream& affiche(std::ostream& sortie) const;
	
	void ajoute_force(Vecteur const&);
	
	virtual double volume() const;
	
	virtual double masse() const;
	
	double Rayon() const;
	
	double Restitution() const;
	
	double Frottement() const;
	
	Vecteur getForce() const;
	
	virtual void agit_sur(ObjetMobile& b2);
	
	virtual void P_(Vecteur p);
	
	virtual void dPdt_(Vecteur p);

    virtual void set_dP(Vecteur ) = 0;

    virtual Vecteur get_vit() const = 0;

    virtual Vecteur get_pos() const = 0;

    void Force_(Vecteur f);

    virtual ObjetMobile* copie() const = 0;

    virtual void ajoute_a(Systeme& s) = 0;
	
	virtual ~ObjetMobile() {}
	
};

