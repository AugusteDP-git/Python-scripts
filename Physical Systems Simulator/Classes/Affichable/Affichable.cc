#include <iostream>
#include "Affichable.h"
using namespace std;

ostream& operator <<(ostream& sortie, const Affichable& instance){
	return instance.affiche(sortie);
}
