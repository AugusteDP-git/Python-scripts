#include <iostream>
#include "../Vecteurs/Methodes.h"
#include "../Balle/Balle.h"
#include "Champforces.h"
using namespace std;

int main() 
{
	Vecteur g(0,0,-9.81);
	Vecteur p(1,2,3);
	Vecteur v(0,0.1,0.2);
	Vecteur p2(2,4,6);
	Vecteur Force(0,0,0);
	ChampsForces c2(g,"Champ de gravité");
	Balle b1(0.2, 3, p, v, Force, "Balle de rugby");
	Balle b2(0.4,2.5, p2, v, Force, "Balle de foot");
	
	cout << "Nous avons :" << endl;
	cout << "Une balle : " << endl;
	cout << b1;
	cout << endl;
	cout << "et une autre balle : " << endl;
	cout << b2;
	
	cout << "Un champ de force apparaît..." << endl;
	cout << endl;
	
	c2.agit_sur(b1);
	c2.agit_sur(b2);
	
	cout << "A present nous avons :" << endl;
	cout << "Un champs de force :" << endl;
	cout << c2 << endl;
	cout << "Une balle : " << endl;
	cout << b1;
	cout << endl;
	cout << "et une autre balle : " << endl;
	cout << b2 << endl;
	
	cout << "Ici l'intensité est dans la direction : " << c2.normale() << endl;
	cout << "et a pour norme : " << c2.V0() << endl << endl;
	if(c2.zone(b1)) cout<< "La balle de rugby est bien dans la zone du champs de gravité" << endl;
	if(c2.zone(b2)) cout<< "La balle de foot est bien dans la zone du champs de gravité" << endl;
	
	return 0;
}
