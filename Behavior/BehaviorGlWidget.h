#ifndef BEHAVIORGLWIDGET_H
#define BEHAVIORGLWIDGET_H

#include <QtOpenGL/QGLWidget>
#include <QToolBar>
#include <QAction>
#include <QApplication>
#include <QTimer>
#include <QMouseEvent>
#include <QKeyEvent>
#include <qgl.h>
#include <QtOpenGL>
#include <GL/GLU.h>
#include <GL/glut.h>

#include "controlpaneldialog.h"
#include "Agent.h"
#include "AgentDisplay.h"
#include "Transformation.h"
#include "BehaviorCamera.h"
#include "BehaviorSimulation.h"

class CBehaviorSimulation;
class BehaviorCamera;
class ControlPanelDialog;

class BehaviorGlWidget : public QGLWidget {

    Q_OBJECT // must include this if you use Qt signals/slots

public:
    BehaviorGlWidget(QWidget *parent = NULL);

public slots:

    void on_timer_timeout();
    void on_actionShowControlPanel_triggered(bool checked);
    void on_actionResetCamera_triggered();
    void on_actionPlay_triggered(bool checked);

protected:
    void initializeGL();
    void resizeGL(int cx, int cy);
    void paintGL();
    void ComputePostion(int x, int y, vec2 &goal);
    void enterEvent(QEvent * event);
    void leaveEvent(QEvent *);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

public:

    // actions
    QToolBar *toolBar;
    QAction *actionShowControlPanel;
    QAction *actionResetCamera;
    QAction *actionPlay;
 
    // Animation
    QTimer *timer;

    // parameters
    int	m_lastMouseX, m_lastMouseY;
    int m_mouseButton;
    bool m_altKey;
    bool onPlay;
    int groundsize;
    int groundstep;
    vec2 goal;
    CBehaviorSimulation sim;
    BehaviorCamera m_BehaviorCamera;
    ControlPanelDialog *control;


    friend class ControlPanelDialog;
};

#endif // BEHAVIORGLWIDGET_H
