#pragma once
#include "../Integrateur/Integrateur.h"
#include "../constantes/constantes.h"

class IntegrateurEulerCromer: public Integrateur {
public:
    virtual void integre(ObjetMobile& o) const override;
	IntegrateurEulerCromer(double dt = 0.01):Integrateur(dt) {}	
	double dt() const;
    virtual Integrateur* copie() const override;
	virtual std::ostream& affiche(std::ostream&) const override;
};
