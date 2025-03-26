#include <iostream>
#include <string>
#include "../Vecteurs/Methodes.h"
#include "../Balle/Balle.h"
#include "../objetmobile/objetmobile.h"
#include "../Plan/Plan.h"
#include "../Champforces/Champforces.h"
#include "../constantes/constantes.h"
#include "../Systeme/Systeme.h"
#include "../Integrateur/Integrateur.h"
#include "../IntegrateurEulerCromer/IntegrateurEulerCromer.h"
#include "../TextViewer/TextViewer.h"
#include "../Pendule2D/Pendule2D.h"
#include <vector>
using namespace std;

int main()
{
	TextViewer t(cout);
	Vecteur origine_1(0, 1.36675, 0.283821);
	Vecteur origine(0, 0, 0.3);
	Vecteur vit_1(0, 0.715449, 0.0957368);
	Vecteur vit(0, 0.8, 2);
	Balle b1(0.051111, 3, origine, vit);
	
	
	ChampsForces c(g, "gravite");

	Vecteur ez(0,0,1);
	Vecteur O(0, 0, 0);
	
	Vecteur origine_3(0, 1.4, 0.45);
	Plan p(ez, O);
	
	Vecteur theta(vector<double>{1.5});
	
	//test2, les valeurs ne sont pas les mêmes car nous prenons en compte la poussée d'Archimède
	cout << "TEST 2" << endl;
	Vecteur thetapoint(vector<double>{-0.5});
	Vecteur direc(0,1,0);
	Pendule2D p1(0.05, 190.985931710274, 0.2, 0.005, direc, origine_3, theta, thetapoint);
	c.agit_sur(b1);
	c.agit_sur(p1);
	Systeme s1;
	s1.ajouter_mob(new Balle(b1));
	s1.ajouter_mob(new Pendule2D(p1));
	s1.ajouter_chp(new ChampsForces(c));
	cout << s1 << endl;
	
	cout << "Le Système évolue : " << endl;
	cout << "Dans l'ordre : " << endl;
	cout << "Position balle, Vitesse balle, theta pendule, theta point pendule " << endl << endl;

	for(int i(0); i < 20; ++i){
		s1.evolue();
		t.dessine(s1);
	}
	cout << endl << s1;
	return 0;
}
