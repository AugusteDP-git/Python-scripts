#include "IntegrateurEulerCromer.h"
#include "../Balle/Balle.h"
#include "../constantes/constantes.h"
#include "../Champforces/Champforces.h"
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	Vecteur g(0,0,-9.81);
	Vecteur p(0,0,0);
	Vecteur v(0,0.1,0.2);
	Vecteur p2(2,4,6);
	Vecteur Force(0,0,0);
	ChampsForces c(g,"Champ de gravitê");
	Balle b1(0.2, 3, p, v, Force, "Balle de rugby");
	c.agit_sur(b1);
	
	IntegrateurEulerCromer integrateur(0.01);
	cout << "Nous avons :" << endl;
	cout << "Un champs de force :" << endl;
	cout << c << endl;
	cout << "Une balle : " << endl;
	cout << b1;
	cout << endl;
	
	for (int i(1); i < 10; ++i){
		cout << "L'integration " << i << " donne:" << endl;
		integrateur.integre(b1);
		cout << b1 << endl;
		cout << "====================================" << endl;
	}	
	return 0;
}
