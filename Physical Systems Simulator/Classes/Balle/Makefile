CXX = g++
CC = $(CXX)
CXXFLAGS = -std=c++11 -Wall
all:Testballe

Testballe: Testballe.o  ../Vecteurs/Methodes.o ../Affichable/Affichable.o \
../objetmobile/objetmobile.o Balle.o ../Obstacles/Obstacles.o\
 ../constantes/constantes.o ../Systeme/Systeme.o \
../Champforces/Champforces.o

Testballe.o: Testballe.cc ../Vecteurs/Methodes.h \
 ../Vecteurs/../Affichable/Affichable.h ../objetmobile/objetmobile.h \
 ../objetmobile/../Dessinable/Dessinable.h Balle.h \
 ../support_a_dessin/support_a_dessin.h ../constantes/constantes.h \
 ../Champforces/Champforces.h

Balle.o: Balle.cc ../Vecteurs/Methodes.h \
 ../Vecteurs/../Affichable/Affichable.h Balle.h \
 ../objetmobile/objetmobile.h ../objetmobile/../Dessinable/Dessinable.h \
 ../support_a_dessin/support_a_dessin.h ../Systeme/Systeme.h \
 ../Systeme/../Obstacles/Obstacles.h \
 ../Systeme/../Champforces/Champforces.h \
 ../Systeme/../Integrateur/Integrateur.h \
 ../Systeme/../Pendule2D/Pendule2D.h \
 ../Systeme/../Pendule2D/../constantes/constantes.h \
 ../Systeme/../Plan/Plan.h \
 ../Systeme/../IntegrateurNewark/IntegrateurNewark.h

../Vecteurs/Methodes.o: ../Vecteurs/Methodes.cc ../Vecteurs/Methodes.h 
../objetmobile/objetmobile.o: ../objetmobile/objetmobile.cc ../objetmobile/objetmobile.h
../constantes/constantes.o: ../constantes/constantes.cc ../constantes/constantes.h
../Champforces/Champforces.o: ../Champforces/Champforces.cc ../Champforces/Champforces.h
../Systeme/Systeme.o: ../Systeme/Systeme.cc ../Systeme/Systeme.h
../Obstacles/Obstacles.o: ../Obstacles/Obstacles.cc ../Obstacles/Obstacles.h
