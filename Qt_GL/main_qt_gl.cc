#include <QApplication>
#include <iostream>
#include "glwidget.h"
#include "../general/Systeme/Systeme.h"
#include "../general/Balle/Balle.h"
#include "../general/Brique/Brique.h"
#include "../general/Plan/Plan.h"
#include "../general/IntegrateurNewark/IntegrateurNewark.h"
#include "../general/Pendule2D/Pendule2D.h"
#include "../general/Pendule3D/Pendule3D.h"
#include "../general/Champforces/Champforces.h"
#include "../general/IntegrateurEulerCromer/IntegrateurEulerCromer.h"
#include "../general/Vent/Vent.h"
#include "../general/ObjetCompose/ObjetCompose.h"
#include "../general/Ventilateur/Ventilateur.h"
#include <vector>
using namespace std;
int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    Vecteur origine(0, 0, 0.3);
    Vecteur vit(0, 0.8, 2);
    Balle b1(0.051111, 3, origine, vit);
    Balle b2(0.051111, 3, Vecteur(0.0471,-1.0, 1.2511111));
    ChampsForces c(g, "gravite");
    Vecteur origine_3(0, 1.2, 0.45);
    Vecteur theta(vector<double>{1.5});
    Vecteur thetapoint(vector<double>{-0.5});
    Vecteur direc(0,1,0);
    Pendule2D p1(0.05, 190.985931710274, 0.2, 0.005, direc, origine_3, theta, thetapoint);
    Vecteur(vector<double>{-0.5,1});
    Vecteur d1(0,0.3, 0);
    Vecteur d2(0.25,0,0);
    double Hauteur(0.25);
    Brique b(Vecteur(-0.15,-0.6,0),d2,d1,Hauteur);
    p1.ajoute_force(p1.masse() * g);
    Systeme s1;
    s1.ajouter_mob(new Pendule2D(p1));
    s1.ajouter_mob(new Balle(b1));
    s1.ajouter_mob(new Balle(b2));
    b.ajoute_a(s1);
    s1.ajouter_chp(new ChampsForces(c));
    s1.ajouter_obs(new Plan(Vecteur(0,0,1)));

    GLWidget w(s1);
    w.show();

  return a.exec();
}
