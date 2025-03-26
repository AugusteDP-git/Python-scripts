QT += core gui opengl widgets
QMAKE_CXXFLAGS += -std=c++11

win32:LIBS += -lopengl32


TARGET = Graphisme_Projet

LIBS += -L../general -lgeneral
PRE_TARGETDEPS += ../general/libgeneral.a

INCLUDEPATH = ../general


SOURCES += \
    main_qt_gl.cc \
    glwidget.cc \
    vue_opengl.cc \
    glsphere.cc \
    ../general/Affichable/Affichable.cc \
    ../general/Balle/Balle.cc \
    ../general/Brique/Brique.cc \
    ../general/Champforces/Champforces.cc \
    ../general/constantes/constantes.cc \
    ../general/Integrateur/Integrateur.cc \
    ../general/IntegrateurEulerCromer/IntegrateurEulerCromer.cc \
    ../general/IntegrateurNewark/IntegrateurNewark.cc \
    ../general/objetmobile/objetmobile.cc \
    ../general/ObjetCompose/ObjetCompose.cc \
    ../general/Obstacles/Obstacles.cc \
    ../general/Pendule2D/Pendule2D.cc \
    ../general/Pendule3D/Pendule3D.cc \
    ../general/Plan/Plan.cc \
    ../general/Systeme/Systeme.cc \
    ../general/Vecteurs/Methodes.cc \
    ../general/Vent/Vent.cc \
    ../general/Ventilateur/Ventilateur.cc

HEADERS += \
    glwidget.h \
    vertex_shader.h \
    vue_opengl.h \
    glsphere.h \
    ../general/Dessinable/Dessinable.h \
    ../general/support_a_dessin/support_a_dessin.h \
    ../general/Systeme/Systeme.h \
    ../general/Balle/Balle.h \
    ../general/ObjetCompose/ObjetCompose.h \
    ../general/Pendule2D/Pendule2D.h \
    ../general/Pendule3D/Pendule3D.h \
    ../general/Plan/Plan.h \
    ../general/Brique/Brique.h \
    ../general/Vent/Vent.h \
    ../general/Ventilateur/Ventilateur.h

RESOURCES += \
    resource.qrc
