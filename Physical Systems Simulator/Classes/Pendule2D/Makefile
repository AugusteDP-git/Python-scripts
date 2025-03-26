CXX = g++
CC = $(CXX)
CXXFLAGS = -std=c++11 -Wall
all:TestPendule2D

TestPendule2D: ../objetmobile/objetmobile.o ../Vecteurs/Methodes.o ../constantes/constantes.o Pendule2D.o  \
../Affichable/Affichable.o ../Balle/Balle.o ../IntegrateurEulerCromer/IntegrateurEulerCromer.o ../Champforces/Champforces.o \
../Integrateur/Integrateur.o ../Systeme/Systeme.o ../Obstacles/Obstacles.o


TestPendule2D.o: TestPendule2D.cc ../Champforces/Champforces.h \
 ../Champforces/../Vecteurs/Methodes.h \
 ../Champforces/../Vecteurs/../Affichable/Affichable.h \
 ../Champforces/../objetmobile/objetmobile.h \
 ../Champforces/../objetmobile/../Dessinable/Dessinable.h \
 ../Balle/Balle.h ../Balle/../support_a_dessin/support_a_dessin.h \
 Pendule2D.h ../constantes/constantes.h \
 ../IntegrateurEulerCromer/IntegrateurEulerCromer.h \
 ../IntegrateurEulerCromer/../Integrateur/Integrateur.h

../objetmobile/objetmobile.o: ../objetmobile/objetmobile.cc ../objetmobile/objetmobile.h
../Vecteurs/Methodes.o: ../Vecteurs/Methodes.cc ../Vecteurs/Methodes.h ../Vecteurs/ClassErreur.h
../constantes/constantes.o: ../constantes/constantes.cc ../constantes/constantes.h
Pendule2D.o: Pendule2D.cc Pendule2D.h ../Vecteurs/Methodes.h \
 ../Vecteurs/../Affichable/Affichable.h ../objetmobile/objetmobile.h \
 ../objetmobile/../Dessinable/Dessinable.h ../Balle/Balle.h \
 ../Balle/../support_a_dessin/support_a_dessin.h \
 ../constantes/constantes.h ../Systeme/Systeme.h \
 ../Systeme/../Obstacles/Obstacles.h \
 ../Systeme/../Champforces/Champforces.h \
 ../Systeme/../Integrateur/Integrateur.h ../Systeme/../Plan/Plan.h \
 ../Systeme/../IntegrateurNewark/IntegrateurNewark.h

../Balle/Balle.o: ../Balle/Balle.h ../Balle/Balle.cc
../IntegrateurEulerCromer/IntegrateurEulerCromer.o: ../IntegrateurEulerCromer/IntegrateurEulerCromer.cc ../IntegrateurEulerCromer/IntegrateurEulerCromer.h
../Champforces/Champforces.o: ../Champforces/Champforces.cc ../Champforces/Champforces.h
../Affichable/Affichable.o: ../Affichable/Affichable.cc ../Affichable/Affichable.h
../Integrateur/Integrateur.o: ../Integrateur/Integrateur.cc ../Integrateur/Integrateur.h
../Systeme/Systeme.o: ../Systeme/Systeme.cc ../Systeme/Systeme.h
../Obstacles/Obstacles.o: ../Obstacles/Obstacles.cc ../Obstacles/Obstacles.h
