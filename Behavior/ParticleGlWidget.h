//////////////////////////////////////////////////////////////////////////
// ParticleWidget.h -- Header file for useful methods of the firework openGL window in QT.
//
// Tiantian Liu
// 11/17/2011
// University of Pennsylvania

#pragma once

#include <QtOpenGL/QGLWidget>
#include <QKeyEvent>
#include <QTimer>
#include <QImage>
#include "ParticleSystem.h"
#include "Rocket.h"
#include "Spark.h"
#include "Simulation.h"

class ParticleGLWidget : public QGLWidget {

    Q_OBJECT // must include this if you use Qt signals/slots

public:
    ParticleGLWidget(QWidget *parent = NULL);
    
public slots:
    void on_timer_timeout();

protected:
    void initializeGL();
    void resizeGL(int cx, int cy);
    void paintGL();
    void enterEvent(QEvent * event);
    void leaveEvent(QEvent *);
    void keyPressEvent(QKeyEvent *event);

public:

    // Animation
    QTimer *timer;

    // Background img
    QImage bgImgBuffer, glBgImg;

    // parameters
    CSimulation m_Sim;
};
