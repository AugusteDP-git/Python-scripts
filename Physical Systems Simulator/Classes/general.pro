TEMPLATE = lib
TEMPLATE = subdirs
CONFIG = staticlib
QMAKE_CXXFLAGS += -std=c++11

SUBDIRS += ../general/Affichable \
    ../general/Balle \
    ../general/Brique \
    ../general/Champforces \
    ../general/constantes \
    ../general/Dessinable \
    ../general/Integrateur \
    ../general/IntegrateurEulerCromer \
    ../general/IntegrateurNewark \
    ../general/objetmobile \
    ../general/ObjetCompose \
    ../general/Obstacles \
    ../general/Pendule2D \
    ../general/Pendule3D \
    ../general/Plan \
    ../general/support_a_dessin \
    ../general/Systeme \
    ../general/Vecteurs \
    ../general/Vent \
    ../general/Ventilateur


