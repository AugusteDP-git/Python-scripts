CXX = g++
CC = $(CXX)
CXXFLAGS = -std=c++11 -Wall
all:TestIntegrateur3

TestIntegrateur3: TestIntegrateur3.o IntegrateurNewark.o \
../Integrateur/Integrateur.o ../Vecteurs/Methodes.o ../Affichable/Affichable.o \
../objetmobile/objetmobile.o ../Champforces/Champforces.o ../Balle/Balle.o \
../Systeme/Systeme.o ../TextViewer/TextViewer.o ../constantes/constantes.o \
../Obstacles/Obstacles.o ../Plan/Plan.o ../Pendule2D/Pendule2D.o 

TestIntegrateur3.o: TestIntegrateur3.cc ../Vecteurs/Methodes.h \
 ../Vecteurs/../Affichable/Affichable.h ../Balle/Balle.h \
 ../Balle/../objetmobile/objetmobile.h \
 ../Balle/../objetmobile/../Dessinable/Dessinable.h \
 ../Balle/../support_a_dessin/support_a_dessin.h ../Plan/Plan.h \
 ../Plan/../Obstacles/Obstacles.h ../Champforces/Champforces.h \
 ../constantes/constantes.h ../Systeme/Systeme.h \
 ../Systeme/../Integrateur/Integrateur.h \
 ../Systeme/../Pendule2D/Pendule2D.h \
 ../Systeme/../IntegrateurNewark/IntegrateurNewark.h \
 ../IntegrateurEulerCromer/IntegrateurEulerCromer.h \
 ../TextViewer/TextViewer.h ../TextViewer/../Pendule3D/Pendule3D.h \
 ../TextViewer/../Brique/Brique.h


IntegrateurNewark.o: IntegrateurNewark.cc IntegrateurNewark.h \
 ../Integrateur/Integrateur.h ../Integrateur/../Vecteurs/Methodes.h \
 ../Integrateur/../Vecteurs/../Affichable/Affichable.h \
 ../Integrateur/../objetmobile/objetmobile.h \
 ../Integrateur/../objetmobile/../Dessinable/Dessinable.h

../Integrateur/Integrateur.o: ../Integrateur/Integrateur.cc ../Integrateur/Integrateur.h
../Vecteurs/Methodes.o: ../Vecteurs/Methodes.cc ../Vecteurs/Methodes.h
../Affichable/Affichable.o: ../Affichable/Affichable.cc ../Affichable/Affichable.h
../objetmobile/objetmobile.o: ../objetmobile/objetmobile.cc ../objetmobile/objetmobile.h
../Champforces/Champforces.o: ../Champforces/Champforces.cc ../Champforces/Champforces.h
../Balle/Balle.o: ../Balle/Balle.cc ../Balle/Balle.h
../Systeme/Systeme.o: ../Systeme/Systeme.cc ../Systeme/Systeme.h
../TextViewer/TextViewer.o: ../TextViewer/TextViewer.cc ../TextViewer/TextViewer.h
../constantes/constantes.o: ../constantes/constantes.h ../constantes/constantes.cc
../Obstacles/Obstacles.o: ../Obstacles/Obstacles.cc ../Obstacles/Obstacles.h
../Pendule2D/Pendule2D.o: ../Pendule2D/Pendule2D.cc ../Pendule2D/Pendule2D.h
../Plan/Plan.o: ../Plan/Plan.cc ../Plan/Plan.h
