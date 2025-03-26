#include "Integrateur.h"
using namespace std;

ostream& Integrateur::affiche(ostream& sortie) const{
	sortie << "dt = " << dt_<< endl;
	return sortie;
}
