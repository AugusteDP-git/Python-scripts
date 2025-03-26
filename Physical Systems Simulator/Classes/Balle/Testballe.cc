#include <iostream>
#include <string>
#include "../Vecteurs/Methodes.h"
#include "../objetmobile/objetmobile.h"
#include "Balle.h"
#include "../constantes/constantes.h"
#include "../Champforces/Champforces.h"
using namespace std;

int main()
{
	
	ChampsForces c(g, "gravité");

	Balle b1(0.2, 3, Vecteur(1,2,3), Vecteur(0,0.1,0.2));
	c.agit_sur(b1);
	
	cout << "Nous avons : " << endl;
	cout << "Un champ de force : " << endl;
	cout << c << endl;
	cout << "Une Balle :" << endl;
	cout << b1 << endl;
	return 0;
}
