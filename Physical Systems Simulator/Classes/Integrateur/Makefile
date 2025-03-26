CXX = g++
CC = $(CXX)
CXXFLAGS = -std=c++11 -Wall
all:TestIntegrateur

TestIntegrateur: TestIntegrateur.o Integrateur.o ../Vecteurs/Methodes.o ../objetmobile/objetmobile.o \
../Affichable/Affichable.o ../constantes/constantes.o


TestIntegrateur.o: TestIntegrateur.cc ../Vecteurs/Methodes.h \
 ../Vecteurs/../Affichable/Affichable.h ../objetmobile/objetmobile.h \
 ../objetmobile/../Dessinable/Dessinable.h Integrateur.h

Integrateur.o: Integrateur.cc Integrateur.h ../Vecteurs/Methodes.h \
 ../Vecteurs/../Affichable/Affichable.h ../objetmobile/objetmobile.h \
 ../objetmobile/../Dessinable/Dessinable.h

../Vecteurs/Methodes.o: ../Vecteurs/Methodes.h ../Vecteurs/Methodes.cc
../objetmobile/objetmobile.o: ../objetmobile/objetmobile.cc ../objetmobile/objetmobile.h
../Affichable/Affichable.o: ../Affichable/Affichable.cc ../Affichable/Affichable.h
../constantes/constantes.o: ../constantes/constantes.cc ../constantes/constantes.h
