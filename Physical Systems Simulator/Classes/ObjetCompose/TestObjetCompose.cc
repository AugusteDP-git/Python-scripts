#include <iostream>
#include "ObjetCompose.h"
#include "../Brique/Brique.h"
#include "../Vent/Vent.h"
#include "../Champforces/Champforces.h"
#include "../Systeme/Systeme.h"

using namespace std;

int main() {
	
	//Allocation dynamique uniquement pour les objet compose
	//creation d'un objet compose
	ObjetCompose obj_c;
	cout<<obj_c<<endl;
	
	//Brique
	Vecteur origine(0,0,0);
	Vecteur L(2,0,0);
	Vecteur l(0,1,0);
	Brique* ptr_b (new Brique(origine, L, l, 0.5));
	obj_c.ajouter_obs(ptr_b);
	
	//Balle
	Balle* ptr_ba(new Balle(5.0, 2.0));
	obj_c.ajouter_mob(ptr_ba);
	
	//Vent
	Vecteur intensite(10, 0, 0);
	Vecteur La(0, 3, 0);
	Vent* ptr_v(new Vent(intensite, La, 7, 1.0));
	obj_c.ajouter_chp(ptr_v);
	
	//Champ de force 
	Vecteur g(0, 0, 10);
	ChampsForces* ptr_c(new ChampsForces(g));
	obj_c.ajouter_chp(ptr_c);
	
	//verification du tout (et de l'affichage)
	cout<<obj_c<<endl;
	
	//test des getteurs
	cout << *obj_c.get_chp(1) << endl ;
	
	//verification de la methode ajoute_a pour ObjetCompose, ObjetMobile, Obstacle et ChampsForces
	Systeme s;
	obj_c.ajoute_a(s);
	cout<<s<<endl;
	
	
			
	return 0;
}
