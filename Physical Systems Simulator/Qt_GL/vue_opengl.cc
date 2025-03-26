#include "vue_opengl.h"
#include "vertex_shader.h" // Identifiants Qt de nos différents attributs
#include "../general/Systeme/Systeme.h"
#include "../general/Balle/Balle.h"
#include "../general/Pendule2D/Pendule2D.h"
#include "../general/Pendule3D/Pendule3D.h"
#include "../general/Plan/Plan.h"
#include "../general/Brique/Brique.h"
#include "../general/Vecteurs/Methodes.h"
#include "../general/ObjetCompose/ObjetCompose.h"

// ======================================================================
    void VueOpenGL::dessine(Systeme const& a_dessiner){
        for(auto obj : a_dessiner.getS_mv()) {
            obj->dessine_sur(*this);
        }
        for(auto obs : a_dessiner.getS_stat()) {
            obs->dessine_sur(*this);
        }
    }

void VueOpenGL::dessine(const Balle& a_dessiner){
     QMatrix4x4 matrice;
     matrice.translate(a_dessiner.getParam()[0], a_dessiner.getParam()[1], a_dessiner.getParam()[2]);
     matrice.scale(a_dessiner.Rayon());
     dessineSphere(matrice, 0.0, 0.0, 1.0);
}

void VueOpenGL::dessine(const Brique& a_dessiner) {
   Vecteur O(a_dessiner.Origine());
   Vecteur l(a_dessiner.Largeur());
   Vecteur L(a_dessiner.Longueur());
   Vecteur H(a_dessiner.Hauteur());

   QMatrix4x4 matrice;
   matrice.setToIdentity();

   prog.setUniformValue("vue_modele", matrice_vue * matrice);

   glBegin(GL_QUADS);
   //Face 1
   prog.setAttributeValue(CouleurId, 1.0, 1.0, 1.0);
   prog.setAttributeValue(SommetId, O[0], O[1], O[2]);
   prog.setAttributeValue(SommetId, O[0] + L[0], O[1]+L[1], O[2] + L[2]);
   prog.setAttributeValue(SommetId, O[0] + L[0] + H[0], O[1] + L[1] + H[1],  O[2] + L[2] + H[2]);
   prog.setAttributeValue(SommetId, O[0] + H[0], O[1] + H[1], O[2] + H[2]);

   //Face 2
   prog.setAttributeValue(CouleurId, 1.0, 1.0, 1.0);
   prog.setAttributeValue(SommetId, O[0] + l[0], O[1] + l[1], O[2] + l[2]);
   prog.setAttributeValue(SommetId, O[0] + l[0] + L[0], O[1] + l[1] + L[1], O[2] +l[2] + L[2]);
   prog.setAttributeValue(SommetId, O[0] + l[0] + L[0] + H[0],O[1] + l[1] + L[1] + H[1], O[2]+l[2] + L[2] + H[2]);
   prog.setAttributeValue(SommetId, O[0] + l[0] + H[0], O[1] + l[1] + H[1],O[2] + l[2] + H[2]);


   //Face 3
   prog.setAttributeValue(CouleurId, 1.0, 1.0, 1.0); // bleu
   prog.setAttributeValue(SommetId, O[0], O[1], O[2]);
   prog.setAttributeValue(SommetId, O[0] + H[0], O[1] + H[1], O[2] + H[2]);
   prog.setAttributeValue(SommetId, O[0] + l[0] + H[0], O[1] + l[1] + H[1], O[2] + l[2] + H[2]);
   prog.setAttributeValue(SommetId, O[0] + l[0], O[1] + l[1], O[2] + l[2]);


   //Face 4
   prog.setAttributeValue(CouleurId, 1.0, 1.0, 1.0); // cyan
   prog.setAttributeValue(SommetId, O[0] + L[0], O[1] + L[1], O[2] + L[2]);
   prog.setAttributeValue(SommetId, O[0] + L[0] + H[0], O[1] + L[1] + H[1], O[2] + L[2] + H[2]);
   prog.setAttributeValue(SommetId, O[0] + l[0] + L[0] + H[0], O[1] + L[1] + l[1] + H[1], O[2] + L[2] + l[2] + H[2]);
   prog.setAttributeValue(SommetId, O[0] + l[0] + L[0], O[1] + L[1] + l[1], O[2] + L[2] + l[2]);


   //Face 5
   prog.setAttributeValue(CouleurId, 1.0, 1.0, 1.0); // jaune
   prog.setAttributeValue(SommetId, O[0], O[1], O[2]);
   prog.setAttributeValue(SommetId, O[0] + l[0], O[1] + l[1], O[2] + l[2]);
   prog.setAttributeValue(SommetId, O[0] + L[0] + l[0] , O[1] + L[1] + l[1], O[2] + L[2] + l[2]);
   prog.setAttributeValue(SommetId, O[0] + L[0] , O[1] + L[1], O[2] + L[2]);

   //Face 6
   prog.setAttributeValue(CouleurId, 1.0, 1.0, 1.0); // magenta
   prog.setAttributeValue(SommetId, O[0] + H[0], O[1] + H[1], O[2] + H[2]);
   prog.setAttributeValue(SommetId, O[0] + l[0] + H[0], O[1] + l[1] + H[1], O[2] + l[2] + H[2]);
   prog.setAttributeValue(SommetId, O[0] + L[0] + l[0] + H[0], O[1] + L[1] + l[1] + H[1], O[2] + L[2] + l[2] + H[2]);
   prog.setAttributeValue(SommetId, O[0] + L[0] + H[0] , O[1] + L[1] + H[1], O[2] + L[2] + H[2]);


   glEnd();


}

void VueOpenGL::dessine(const Pendule2D & a_dessiner) {
    QMatrix4x4 matrice;
    //Initialise la Balle aux dimensions souhaitées
    matrice.setToIdentity();
    prog.setUniformValue("vue_modele", matrice_vue * matrice);
    //trace la ligne qui relie la balle à l'origine
    glBegin(GL_LINES);
    prog.setAttributeValue(CouleurId, 1.0, 1.0, 1,0);
    prog.setAttributeValue(SommetId, a_dessiner.Origine()[0], a_dessiner.Origine()[1], a_dessiner.Origine()[2]);
    prog.setAttributeValue(SommetId, a_dessiner.getPosition()[0], a_dessiner.getPosition()[1], a_dessiner.getPosition()[2]);
    glEnd();
    matrice.setToIdentity();
    matrice.translate(a_dessiner.getPosition()[0], a_dessiner.getPosition()[1], a_dessiner.getPosition()[2]);
    matrice.scale(a_dessiner.Rayon());
    //dessine la balle
    dessineSphere(matrice,1.0,0.0,0.0);
}

void VueOpenGL::dessine(const Pendule3D & a_dessiner){
    QMatrix4x4 matrice;
    matrice.setToIdentity();
    prog.setUniformValue("vue_modele", matrice_vue * matrice);
    //trace la ligne qui relie la balle à l'origine
    glBegin(GL_LINES);
    prog.setAttributeValue(CouleurId, 1.0, 1.0, 1,0);
    prog.setAttributeValue(SommetId, a_dessiner.getPosition()[0], a_dessiner.getPosition()[1], a_dessiner.getPosition()[2]);
    prog.setAttributeValue(SommetId, a_dessiner.Origine()[0], a_dessiner.Origine()[1], a_dessiner.Origine()[2]);
    glEnd();
    matrice.setToIdentity();
    matrice.translate(a_dessiner.getPosition()[0], a_dessiner.getPosition()[1], a_dessiner.getPosition()[2]);
    matrice.scale(a_dessiner.Rayon());
    //dessine la balle
    dessineSphere(matrice,1.0,0.0,0.0);
}

void VueOpenGL::dessine(const Plan & a_dessiner) {
    QMatrix4x4 matrice;
    matrice.translate(a_dessiner.Origine()[0], a_dessiner.Origine()[1], a_dessiner.Origine()[2]);
    prog.setUniformValue("vue_modele", matrice_vue * matrice);

    Vecteur v1(1,1,1);
    orth(a_dessiner.Normale(),v1);
    Vecteur v2((v1^a_dessiner.Normale()));

    glBegin(GL_QUADS);
    prog.setAttributeValue(CouleurId, 0.0, 1.0, 1.0);
    prog.setAttributeValue(SommetId,a_dessiner.Origine()[0] + v1[0]*10, a_dessiner.Origine()[1] + v1[1]*10,
            a_dessiner.Origine()[2] + v1[2]*10);
    prog.setAttributeValue(SommetId,a_dessiner.Origine()[0] + v2[0]*10,a_dessiner.Origine()[1] + v2[1] * 10,
            a_dessiner.Origine()[2] + v2[2] * 10);
    prog.setAttributeValue(SommetId,a_dessiner.Origine()[0]-v1[0]*10, a_dessiner.Origine()[1]-v1[1] * 10,
            a_dessiner.Origine()[2] -v1[2] * 10);
    prog.setAttributeValue(SommetId,a_dessiner.Origine()[0] -v2[0] * 10, a_dessiner.Origine()[1]-v2[1] * 10,
            a_dessiner.Origine()[2]-v2[2] * 10);
    glEnd();

}

void VueOpenGL::dessine(const ObjetCompose& a_dessiner) {
    for(auto obj :  a_dessiner.get_mob()){
        obj->dessine_sur(*this);
    }
    for(auto obs : a_dessiner.get_obs()){
        obs->dessine_sur(*this);
    }
    for(auto comp : a_dessiner.get_comp()){
        comp->dessine_sur(*this);
    }

}

// ======================================================================
void VueOpenGL::init()
{


  prog.addShaderFromSourceFile(QOpenGLShader::Vertex,   ":/vertex_shader.glsl");
  prog.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/fragment_shader.glsl");

  prog.bindAttributeLocation("sommet",  SommetId);
  prog.bindAttributeLocation("couleur", CouleurId);

  prog.bind();

  glEnable(GL_DEPTH_TEST);
  glDisable(GL_CULL_FACE);

  sphere.initialize();                                      // initialise la sphère
  initializePosition();
}

// ======================================================================
void VueOpenGL::initializePosition()
{
  // position initiale
  matrice_vue.setToIdentity();
  matrice_vue.translate(0.0, -0.01, -2.0);
  matrice_vue.rotate(90.0, 0.0, -1.0, 0.0);
  matrice_vue.rotate(90.0, -1.0, 0.0, 0.0);

}

// ======================================================================
void VueOpenGL::translate(double x, double y, double z)
{
  /* Multiplie la matrice de vue par LA GAUCHE.
   * Cela fait en sorte que la dernière modification apportée
   * à la matrice soit appliquée en dernier (composition de fonctions).
   */
  QMatrix4x4 translation_supplementaire;
  translation_supplementaire.translate(x, y, z);
  matrice_vue = translation_supplementaire * matrice_vue;
}

// ======================================================================
void VueOpenGL::rotate(double angle, double dir_x, double dir_y, double dir_z)
{
  // Multiplie la matrice de vue par LA GAUCHE
  QMatrix4x4 rotation_supplementaire;
  rotation_supplementaire.rotate(angle, dir_x, dir_y, dir_z);
  matrice_vue = rotation_supplementaire * matrice_vue;
}

// ======================================================================

void VueOpenGL::dessineSphere (QMatrix4x4 const& point_de_vue,
                               double rouge, double vert, double bleu)
{
  prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);
  prog.setAttributeValue(CouleurId, rouge, vert, bleu);  // met la couleur
  sphere.draw(prog, SommetId);                           // dessine la sphère
}
