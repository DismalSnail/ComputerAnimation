//////////////////////////////////////////////////////////////////////////
// ParticleWidget.cpp -- Source file for useful methods of the firework openGL window in QT.
//
// Tiantian Liu
// 11/17/2011
// University of Pennsylvania

#include "ParticleGLWidget.h"
#include <QDebug>

ParticleGLWidget::ParticleGLWidget(QWidget *parent) : QGLWidget(parent) {

    // timer
    timer = new QTimer(this);
    timer->setInterval(40);
    timer->setSingleShot(false);
    timer->setObjectName(QString::fromUtf8("timer"));
    timer->stop();

    // image;
    bgImgBuffer.load(QString::fromUtf8(":/images/images/Background.png"));
    if (!bgImgBuffer.isNull())
  	this->glBgImg = QGLWidget::convertToGLFormat(bgImgBuffer);

    this->setStatusTip("Use the Keyboard Line From 'A' to ';' to Fire a Rocket.");
    QMetaObject::connectSlotsByName(this);
}

void ParticleGLWidget::initializeGL() {

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f );
    glShadeModel(GL_FLAT);
}

void ParticleGLWidget::resizeGL(int cx, int cy) {

    if(cy == 0) cy = 1;
    // Set Viewport to window dimensions
    //  glViewport(offset.x, offset.y, cx, cy); // (950,660)
    glViewport(0, 0, cx, cy);
    // Reset coordinate system
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, cx, 0, cy);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void ParticleGLWidget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT);	// Clear Screen And Depth Buffer
    glLoadIdentity();

    //glDrawPixels(bgImgBuffer.width(), bgImgBuffer.height(), GL_RGBA, GL_UNSIGNED_BYTE, glBgImg.bits());
    if (m_Sim.GetParticleNum() > 0){
            m_Sim.Display();
    }
}

void ParticleGLWidget::enterEvent(QEvent *event)
{
    QGLWidget::enterEvent(event);
    timer->start();
    setFocus();
    grabKeyboard();
}

void ParticleGLWidget::leaveEvent(QEvent *event)
{
    QGLWidget::leaveEvent(event);
    timer->stop();
    releaseKeyboard();
}

void ParticleGLWidget::keyPressEvent(QKeyEvent* event) {
    QRect r = this->rect();
    float color[3];
    float temp = r.width() / 11.0f;

    switch(event->key()) {
    case Qt::Key_A : color[0] = 1.0; color[1] = 0.0; color[2] = 0.0; m_Sim.FireRocket(temp, color); break;
    case Qt::Key_S : color[0] = 0.0; color[1] = 0.5; color[2] = 0.5; m_Sim.FireRocket(temp * 2, color); break;
    case Qt::Key_D : color[0] = 0.5; color[1] = 0.5; color[2] = 0.0; m_Sim.FireRocket(temp * 3, color); break;
    case Qt::Key_F : color[0] = 0.0; color[1] = 0.0; color[2] = 1.0; m_Sim.FireRocket(temp * 4, color); break;
    case Qt::Key_G : color[0] = 0.0; color[1] = 1.0; color[2] = 0.0; m_Sim.FireRocket(temp * 5, color); break;
    case Qt::Key_H : color[0] = 0.5; color[1] = 0.0; color[2] = 0.0; m_Sim.FireRocket(temp * 6, color); break;
    case Qt::Key_J : color[0] = 1.0; color[1] = 0.0; color[2] = 1.0; m_Sim.FireRocket(temp * 7, color); break;
    case Qt::Key_K : color[0] = 0.0; color[1] = 0.5; color[2] = 0.0; m_Sim.FireRocket(temp * 8, color); break;
    case Qt::Key_L : color[0] = 0.5; color[1] = 0.0; color[2] = 0.5; m_Sim.FireRocket(temp * 9, color); break;
    case Qt::Key_Semicolon : color[0] = 0.0; color[1] = 0.0; color[2] = 0.5; m_Sim.FireRocket(temp * 10, color); break;
    }

}

void ParticleGLWidget::on_timer_timeout()
{
    m_Sim.EulerStep();
    this->glDraw();
}
