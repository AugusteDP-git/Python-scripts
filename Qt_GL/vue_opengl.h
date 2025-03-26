#pragma once

#include <QOpenGLShaderProgram> // Classe qui regroupe les fonctions OpenGL liées aux shaders
#include <QMatrix4x4>
#include "../general/support_a_dessin/support_a_dessin.h"
#include "glsphere.h"

class VueOpenGL : public SupportADessin {
 public:
  // méthode(s) de dessin (héritée(s) de SupportADessin)
  virtual void dessine(Systeme const& a_dessiner) override;
  virtual void dessine(Balle const&) override;
  virtual void dessine(Pendule2D const&) override;
  virtual void dessine(Pendule3D const&) override;
  virtual void dessine(Plan const&) override;
  virtual void dessine(Brique const&) override;
  virtual void dessine(ObjetCompose const&) override;

  // méthodes de (ré-)initialisation
  void init();
  void initializePosition();

  // méthode set
  void setProjection(QMatrix4x4 const& projection)
  { prog.setUniformValue("projection", projection); }

  // Méthodes set
  void translate(double x, double y, double z);
  void rotate(double angle, double dir_x, double dir_y, double dir_z);
  
  // méthode utilitaire offerte pour simplifier
  void dessineSphere(QMatrix4x4 const& point_de_vue, double rouge = 1.0,
                     double vert = 1.0, double bleu = 1.0);

 private:
  // Un shader OpenGL encapsulé dans une classe Qt
  QOpenGLShaderProgram prog;
  //Sphère
  GLSphere sphere;
  // Caméra
  QMatrix4x4 matrice_vue;
};
