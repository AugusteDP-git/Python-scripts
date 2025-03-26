#include "IntegrateurNewark.h"

using namespace std;

void IntegrateurNewark::integre(ObjetMobile& o) const{
	
	Vecteur dPdt(o.getdPdt());
	Vecteur P(o.getParam());
	
	Vecteur s(o.evolution());
	Vecteur q(o.getParam());
	Vecteur r(o.evolution());
	
	o.dPdt_(o.getdPdt());
	o.P_(o.getParam());
	
	do {
		q = o.getParam();
		r = o.evolution();
		o.dPdt_(dPdt+ (dt_ / 2.0) * (r + s));
		o.P_(P + dt_ * dPdt + ((dt_ * dt_) / 3.0) * ((0.5 * r) + s));
	} while ( (o.getParam() - q).norme() >= epsilon);
}

ostream& IntegrateurNewark::affiche(ostream& sortie) const{
	sortie << "Integrateur Newark : " << endl;
	Integrateur::affiche(sortie);
	return sortie;
}

Integrateur* IntegrateurNewark::copie() const{
    return new IntegrateurNewark(*this);
}
