CXX = g++
CC = $(CXX)
CXXFLAGS = -std=c++11 -Wall -g
all:TestObjetCompose

TestObjetCompose: TestObjetCompose.o ../Vecteurs/Methodes.o ObjetCompose.o ../Systeme/Systeme.o ../Obstacles/Obstacles.o ../objetmobile/objetmobile.o ../Vent/Vent.o ../Champforces/Champforces.o ../Affichable/Affichable.o ../constantes/constantes.o ../Balle/Balle.o ../IntegrateurEulerCromer/IntegrateurEulerCromer.o ../Integrateur/Integrateur.o ../IntegrateurNewark/IntegrateurNewark.o ../Brique/Brique.o


TestObjetCompose.o: TestObjetCompose.cc ObjetCompose.h \
 ../Vecteurs/Methodes.h ../Vecteurs/../Affichable/Affichable.h \
 ../objetmobile/objetmobile.h ../objetmobile/../Dessinable/Dessinable.h \
 ../Obstacles/Obstacles.h ../Obstacles/../Balle/Balle.h \
 ../Obstacles/../Balle/../support_a_dessin/support_a_dessin.h \
 ../Champforces/Champforces.h ../Systeme/Systeme.h \
 ../Systeme/../Integrateur/Integrateur.h \
 ../Systeme/../Pendule2D/Pendule2D.h \
 ../Systeme/../Pendule2D/../constantes/constantes.h \
 ../Systeme/../Plan/Plan.h \
 ../Systeme/../IntegrateurNewark/IntegrateurNewark.h ../Brique/Brique.h \
 ../Vent/Vent.h


ObjetCompose.o: ObjetCompose.cc ObjetCompose.h ../Vecteurs/Methodes.h \
 ../Vecteurs/../Affichable/Affichable.h ../objetmobile/objetmobile.h \
 ../objetmobile/../Dessinable/Dessinable.h ../Obstacles/Obstacles.h \
 ../Obstacles/../Balle/Balle.h \
 ../Obstacles/../Balle/../support_a_dessin/support_a_dessin.h \
 ../Champforces/Champforces.h ../Systeme/Systeme.h \
 ../Systeme/../Integrateur/Integrateur.h \
 ../Systeme/../Pendule2D/Pendule2D.h \
 ../Systeme/../Pendule2D/../constantes/constantes.h \
 ../Systeme/../Plan/Plan.h \
 ../Systeme/../IntegrateurNewark/IntegrateurNewark.h



Methodes.o: ../Vecteurs/Methodes.cc ../Vecteurs/Methodes.h ../Vecteurs/ClassErreur.h

Systeme.o: ../Systeme/Systeme.cc ../Systeme/Systeme.h \
 ../Systeme/../objetmobile/objetmobile.h \
 ../Systeme/../objetmobile/../Vecteurs/Methodes.h \
 ../Systeme/../objetmobile/../Vecteurs/../Affichable/Affichable.h \
 ../Systeme/../Obstacles/Obstacles.h \
 ../Systeme/../Obstacles/../Balle/Balle.h \
 ../Systeme/../Obstacles/../Balle/../Dessinable/Dessinable.h \
 ../Systeme/../Obstacles/../Balle/../Dessinable/../supportADessin/supportADessin.h \
 ../Systeme/../Champforces/Champforces.h \
 ../Systeme/../IntegrateurEulerCromer/IntegrateurEulerCromer.h \
 ../Systeme/../IntegrateurEulerCromer/../Integrateur/Integrateur.h \
 ../Systeme/../IntegrateurEulerCromer/../constantes/constantes.h \
 ../Systeme/../Pendule2D/Pendule2D.h ../Systeme/../Plan/Plan.h

Obstacles.o: ../Obstacles/Obstacles.cc ../Obstacles/Obstacles.h \
 ../Obstacles/../Vecteurs/Methodes.h \
 ../Obstacles/../Vecteurs/../Affichable/Affichable.h \
 ../Obstacles/../objetmobile/objetmobile.h ../Obstacles/../Balle/Balle.h \
 ../Obstacles/../Balle/../Dessinable/Dessinable.h \
 ../Obstacles/../Balle/../Dessinable/../Support_a_dessin/Support_a_dessin.h
 
 objetmobile.o: ../objetmobile/objetmobile.cc ../objetmobile/objetmobile.h \
 ../objetmobile/../Vecteurs/Methodes.h \
 ../objetmobile/../Vecteurs/../Affichable/Affichable.h

Champforces.o: ../Champforces/Champforces.cc \
 ../Champforces/../Vecteurs/Methodes.h \
 ../Champforces/../Vecteurs/../Affichable/Affichable.h \
 ../Champforces/../objetmobile/objetmobile.h ../Champforces/Champforces.h \
 ../Champforces/../Balle/Balle.h \
 ../Champforces/../Balle/../Dessinable/Dessinable.h \
 ../Champforces/../Balle/../Dessinable/../SupportADessin/SupportADessin.h \
 ../Champforces/../constantes/constantes.h

Affichable.o: ../Affichable/Affichable.cc ../Affichable/Affichable.h
