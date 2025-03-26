#include "Brique.h"
#include <iostream>
#include "../Balle/Balle.h"
using namespace std;

int main() 
{
	Vecteur origine(7,-2,-5);
	Vecteur L(4,0,0);
	Vecteur l(0,8,0);
	Brique brique(origine, L, l, 2);
	cout << brique << endl;
	
	Vecteur o(0,8,-5);
	Balle b(1,1, o);
	cout<<"Le point le plus proche entre la brique "<<endl<<brique<<"et le point : "<<b.getParam()<<endl;
	cout<< "est : "<<endl;
	cout<<brique.point_plus_proche(b)<<endl;
	return 0;
}
