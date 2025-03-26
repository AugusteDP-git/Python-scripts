CXX = g++
CC = $(CXX)
CXXFLAGS = -std=c++11 -Wall
all:Testchamp

Testchamp: Testchamp.o ../Vecteurs/Methodes.o ../objetmobile/objetmobile.o Champforces.o ../Balle/Balle.o ../constantes/constantes.o ../Affichable/Affichable.o ../Systeme/Systeme.o ../Integrateur/Integrateur.o ../IntegrateurEulerCromer/IntegrateurEulerCromer.o  ../Obstacles/Obstacles.o
Testchamp.o: Testchamp.cc ../Vecteurs/Methodes.h \
 ../Vecteurs/../Affichable/Affichable.h ../Balle/Balle.h \
 ../Balle/../objetmobile/objetmobile.h \
 ../Balle/../objetmobile/../Dessinable/Dessinable.h \
 ../Balle/../support_a_dessin/support_a_dessin.h Champforces.h

objetmobile/objetmobile.o: ../objetmobile/objetmobile.cc ../objetmobile/objetmobile.h
Vecteurs/Methodes.o: ../Vecteurs/Methodes.cc ../Vecteurs/Methodes.h ../Vecteurs/ClassErreur.h
Champforces.o: Champforces.cc ../Vecteurs/Methodes.h \
 ../Vecteurs/../Affichable/Affichable.h ../objetmobile/objetmobile.h \
 ../objetmobile/../Dessinable/Dessinable.h Champforces.h ../Balle/Balle.h \
 ../Balle/../support_a_dessin/support_a_dessin.h \
 ../constantes/constantes.h ../Systeme/Systeme.h \
 ../Systeme/../Obstacles/Obstacles.h \
 ../Systeme/../Integrateur/Integrateur.h \
 ../Systeme/../Pendule2D/Pendule2D.h ../Systeme/../Plan/Plan.h \
 ../Systeme/../IntegrateurNewark/IntegrateurNewark.h

../Balle/Balle.o: ../Balle/Balle.h ../Balle/Balle.cc
../constantes/constantes.o: ../constantes/constantes.cc ../constantes/constantes.h
../Affichable/Affichable.o: ../Affichable/Affichable.cc ../Affichable/Affichable.h
