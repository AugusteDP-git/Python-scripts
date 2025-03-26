#pragma once

#include <QOpenGLWidget>        // Classe pour faire une fenêtre OpenGL
#include <QTime>            // Classe pour gérer le temps
#include "vue_opengl.h"
#include "../general/Systeme/Systeme.h"


class GLWidget : public QOpenGLWidget
/* La fenêtre hérite de QOpenGLWidget ;
 * les événements (clavier, souris, temps) sont des méthodes virtuelles à redéfinir.
 */
{
public:
  GLWidget(Systeme const& s_, QWidget* parent = nullptr)
    :s(s_),QOpenGLWidget(parent)
  {
     /* for(auto obj : s_.getS_mv()){
          s.ajouter_mob(obj->copie());
      }
      for(auto obs : s_.getS_stat()){
          s.ajouter_obs(obs->copie());
      }
      for(auto chp : s_.get_chp()){
          s.ajouter_chp(chp->copie());
      }
      s.change_int(s_.getInt());*/
  }
  virtual ~GLWidget() = default;

private:
  // Les 3 méthodes clés de la classe QOpenGLWidget à réimplémenter
  virtual void initializeGL()                  override;
  virtual void resizeGL(int width, int height) override;
  virtual void paintGL()                       override;

  // Méthodes de gestion d'évènements
  virtual void keyPressEvent(QKeyEvent* event) override;
  virtual void timerEvent(QTimerEvent* event)  override;

  // Méthodes de gestion interne
  void pause();

  VueOpenGL vue;

  // Timer
  int timerId;
  // pour faire évoluer les objets avec le bon "dt"
  QTime chronometre;

  // objets à dessiner, faire évoluer
  Systeme s;
};
