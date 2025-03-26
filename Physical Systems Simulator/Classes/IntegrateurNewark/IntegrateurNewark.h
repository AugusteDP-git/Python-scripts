#pragma once
#include "../Integrateur/Integrateur.h"
#include "../Vecteurs/Methodes.h"
#include "../objetmobile/objetmobile.h"
#include <cmath>
class IntegrateurNewark: public Integrateur{
private:
static constexpr double epsilon = pow(10, -15);

public:
    virtual void integre(ObjetMobile& o) const override;
	IntegrateurNewark(double dt = 0.01):Integrateur(dt) {}	
	double dt() const;
	std::ostream& affiche(std::ostream&) const override;
    virtual Integrateur* copie() const override;
};
