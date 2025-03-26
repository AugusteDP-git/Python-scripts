CXX = g++
CC = $(CXX)
CXXFLAGS = -std=c++11 -Wall
all:TestBrique

TestBrique: TestBrique.o ../Vecteurs/Methodes.o ../objetmobile/objetmobile.o ../Obstacles/Obstacles.o ../Affichable/Affichable.o Brique.o ../Systeme/Systeme.o ../Champforces/Champforces.o ../constantes/constantes.o ../Balle/Balle.o

TestBrique.o: TestBrique.cc Brique.h ../Obstacles/Obstacles.h \
 ../Obstacles/../Vecteurs/Methodes.h \
 ../Obstacles/../Vecteurs/../Affichable/Affichable.h \
 ../Obstacles/../objetmobile/objetmobile.h ../Obstacles/../Balle/Balle.h \
 ../Obstacles/../Balle/../Dessinable/Dessinable.h \
 ../Obstacles/../Balle/../support_a_dessin/support_a_dessin.h

 ..objetmobile/objetmobile.o: ../objetmobile/objetmobile.cc ../objetmobile/objetmobile.h
..Vecteurs/Methodes.o: ../Vecteurs/Methodes.cc ../Vecteurs/Methodes.h ../Vecteurs/ClassErreur.h
../Obstacles/Obstacles.o: ../Obstacles/Obstacles.cc ../Obstacles/Obstacles.h
Brique.o: Brique.cc Brique.h ../Obstacles/Obstacles.h \
 ../Obstacles/../Vecteurs/Methodes.h \
 ../Obstacles/../Vecteurs/../Affichable/Affichable.h \
 ../Obstacles/../objetmobile/objetmobile.h ../Obstacles/../Balle/Balle.h \
 ../Obstacles/../Balle/../Dessinable/Dessinable.h \
 ../Obstacles/../Balle/../support_a_dessin/support_a_dessin.h


