CXX = g++
CC = $(CXX)
CXXFLAGS = -std=c++11 -Wall
all:TestObstacle

TestObstacle: TestObstacle.o ../Vecteurs/Methodes.o ../objetmobile/objetmobile.o Obstacles.o ../Affichable/Affichable.o ../Balle/Balle.o ../Systeme/Systeme.o ../Integrateur/Integrateur.o ../Champforces/Champforces.o ../constantes/constantes.o ../IntegrateurEulerCromer/IntegrateurEulerCromer.o  

TestObstacle.o: TestObstacle.cc Obstacles.h ../Vecteurs/Methodes.h \
 ../Vecteurs/../Affichable/Affichable.h ../objetmobile/objetmobile.h \
 ../Balle/Balle.h ../Balle/../Dessinable/Dessinable.h \
 ../Balle/../support_a_dessin/support_a_dessin.h

Obstacles.o: Obstacles.cc Obstacles.h ../Vecteurs/Methodes.h \
 ../Vecteurs/../Affichable/Affichable.h ../objetmobile/objetmobile.h \
 ../Balle/Balle.h ../Balle/../Dessinable/Dessinable.h \
 ../Balle/../support_a_dessin/support_a_dessin.h

../Vecteurs/Methodes.o: ../Vecteurs/Methodes.h ../Vecteurs/Methodes.cc
../objetmobile/objetmobile.o: ../objetmobile/objetmobile.h ../objetmobile/objetmobile.cc
../Affichable/Affichable.o: ../Affichable/Affichable.h ../Affichable/Affichable.cc
../Balle/Balle.o: ../Balle/Balle.h ../Balle/Balle.cc

