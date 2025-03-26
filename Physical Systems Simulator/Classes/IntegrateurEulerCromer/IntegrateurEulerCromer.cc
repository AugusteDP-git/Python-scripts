#include "IntegrateurEulerCromer.h"
using namespace std;

void IntegrateurEulerCromer::integre(ObjetMobile& o) const {
	
	o.dPdt_(o.getdPdt() + dt_*o.evolution());	
	o.P_( o.getParam() + dt_*o.getdPdt());
}

double IntegrateurEulerCromer::dt() const {
	return dt_;
}

ostream& IntegrateurEulerCromer::affiche(ostream& sortie) const{
	sortie << "Integrateur Euler-Cromer : " << endl;
	Integrateur::affiche(sortie);
	return sortie;
}

Integrateur* IntegrateurEulerCromer::copie() const{
    return new IntegrateurEulerCromer(*this);
}
