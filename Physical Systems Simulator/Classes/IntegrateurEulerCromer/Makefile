CXX = g++
CC = $(CXX)
CXXFLAGS = -std=c++11 -Wall
all:TestIntegrateur2

TestIntegrateur2: TestIntegrateur2.o IntegrateurEulerCromer.o \
../Integrateur/Integrateur.o ../Vecteurs/Methodes.o ../objetmobile/objetmobile.o \
../Balle/Balle.o ../constantes/constantes.o ../Champforces/Champforces.o ../Affichable/Affichable.o \
../Systeme/Systeme.o ../Obstacles/Obstacles.o

TestIntegrateur2.o: TestIntegrateur2.cc IntegrateurEulerCromer.h \
 ../Integrateur/Integrateur.h ../Integrateur/../Vecteurs/Methodes.h \
 ../Integrateur/../Vecteurs/../Affichable/Affichable.h \
 ../Integrateur/../objetmobile/objetmobile.h \
 ../Integrateur/../objetmobile/../Dessinable/Dessinable.h \
 ../constantes/constantes.h ../Balle/Balle.h \
 ../Balle/../support_a_dessin/support_a_dessin.h \
 ../Champforces/Champforces.h
IntegrateurEulerCromer.o: IntegrateurEulerCromer.cc \
 IntegrateurEulerCromer.h ../Integrateur/Integrateur.h \
 ../Integrateur/../Vecteurs/Methodes.h \
 ../Integrateur/../Vecteurs/../Affichable/Affichable.h \
 ../Integrateur/../objetmobile/objetmobile.h \
 ../Integrateur/../objetmobile/../Dessinable/Dessinable.h \
 ../constantes/constantes.h

../Vecteurs/Methodes.o: ../Vecteurs/Methodes.cc ../Vecteurs/Methodes.h 
../objetmobile/objetmobile.o: ../objetmobile/objetmobile.cc ../objetmobile/objetmobile.h
../Balle/Balle.o: ../Balle/Balle.cc ../Balle/Balle.h
../constantes/constantes.o: ../constantes/constantes.cc ../constantes/constantes.h
../Champforces/Champforces.o: ../Champforces/Champforces.cc ../Champforces/Champforces.h
../Affichable/Affichable.o: ../Affichable/Affichable.cc ../Affichable/Affichable.h
../Systeme/Systeme.o: ../Systeme/Systeme.cc ../Systeme/Systeme.h
../Obstacles/Obstacles.o: ../Obstacles/Obstacles.cc ../Obstacles/Obstacles.h
