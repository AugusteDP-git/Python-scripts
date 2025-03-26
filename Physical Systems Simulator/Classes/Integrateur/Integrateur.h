#pragma once
#include "../Vecteurs/Methodes.h"
#include "../objetmobile/objetmobile.h"
#include "../Affichable/Affichable.h"
class Integrateur: public Affichable {
protected:
	double dt_;
public:
	virtual void integre(ObjetMobile& o) const = 0;
	Integrateur(Integrateur const&) = default;
	Integrateur(double dt):dt_(dt) {}
	virtual std::ostream& affiche(std::ostream& sortie) const override;
    virtual Integrateur* copie() const = 0;
	virtual ~Integrateur() {}
};
