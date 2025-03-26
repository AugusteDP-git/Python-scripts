CXX = g++
CC = $(CXX)
CXXFLAGS = -std=c++11 -Wall
all:testobjetmobile

testobjetmobile: testobjetmobile.o ../Vecteurs/Methodes.o objetmobile.o ../Affichable/Affichable.o \
../constantes/constantes.o 

testobjetmobile.o: testobjetmobile.cc objetmobile.h \
 ../Vecteurs/Methodes.h ../Vecteurs/../Affichable/Affichable.h

objetmobile.o: objetmobile.cc objetmobile.h ../Vecteurs/Methodes.h \
 ../Vecteurs/../Affichable/Affichable.h
../Vecteurs/Methodes.o: ../Vecteurs/Methodes.cc ../Vecteurs/Methodes.h \
 ../Vecteurs/../Affichable/Affichable.h ../Vecteurs/ClassErreur.h \
 ../Vecteurs/../constantes/constantes.h
 ../Affichable/Affichable.o: ../Affichable/Affichable.h ../Affichable/Affichable.cc
../constantes/constantes.o: ../constantes/constantes.h ../constantes/constantes.cc
