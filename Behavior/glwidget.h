//////////////////////////////////////////////////////////////////////////
// glwidget.h -- Header file for useful methods of the openGL window in QT
//
// Tiantian Liu
// 11/11/2011
// University of Pennsylvania


#ifndef _GLWIDGET_H
#define _GLWIDGET_H

#include <QtOpenGL/QGLWidget>
#include <QPropertyAnimation>
#include <QComboBox>
#include <QLabel>
#include <QSlider>
#include <QToolBar>
#include <QAction>
#include <QApplication>
#include <QFileDialog>
#include <QTimer>
#include "Camera.h"
#include "Animation.h"
#include "OpenGLViewer.h"
#include "interpolationdialog.h"
#include "skeletondialog.h"

enum PlayMode {PFW, PBW, STP, SFW, SBW};

class GLWidget : public QGLWidget {

    Q_OBJECT // must include this if you use Qt signals/slots

public:
    GLWidget(QWidget *parent = NULL);
    void Update_Toolbar();

public slots:
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionPlay_Back_triggered();
    void on_actionStep_Back_triggered();
    void on_actionPause_triggered(bool checked);
    void on_actionStep_Forward_triggered();
    void on_actionPlay_triggered();
    void on_slider_valueChanged();
    void on_comboBoxSwitch_Motion_currentIndexChanged(int index);
    void on_actionCoord_triggered(bool checked);
    void on_actionIK_triggered(bool checked);
    void on_actionSkeleton_triggered();
    void on_actionApply_triggered();
    void on_actionBlend_triggered();
    void on_actionResetCamera_triggered();
    void on_timer_timeout();

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    void PickObject(int x, int y);
    void ComputePos(int x, int y);
    int ProcessHits(GLint hits, GLuint buffer[]);
    void enterEvent(QEvent * event);
    void leaveEvent(QEvent *);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *);

public:

    // actions
    QToolBar *toolBar;
    QSlider *slider;
    QLabel *label;
    QComboBox *comboBoxSwitch_Motion;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionPlay_Back;
    QAction *actionStep_Back;
    QAction *actionPause;
    QAction *actionStep_Forward;
    QAction *actionPlay;
    QAction *actionCoord;
    QAction *actionIK;
    QAction *actionSkeleton;
    QAction *actionApply;
    QAction *actionBlend;
    QAction *actionResetCamera;
    //QAction *action;
    //QComboBox *methodChooseComboBox;

    // Animation
    QTimer *timer;

    // parameters
    OpenGLViewer m_viewer;
    Camera m_camera;
    Player m_player;
    PlayMode mode;
    int deltaFrame;
    int	m_lastMouseX, m_lastMouseY;
    int m_mouseButton;
    bool m_altKey;
    bool m_shiftKey;

    friend class SkeletonDialog;
};

#endif
