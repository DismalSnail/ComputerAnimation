#include "BehaviorGlWidget.h"

BehaviorGlWidget::BehaviorGlWidget(QWidget *parent) : QGLWidget(parent) {
    setMouseTracking(true);

    m_altKey = false;
    m_mouseButton  =0;
    sim.env.groundSize = 2000.0f;
    goal = vec2(0.0f,0.0f);
    control = new ControlPanelDialog(this, this);
    onPlay = true;

    // timer
    timer = new QTimer(this);
    timer->setInterval(40);
    timer->setSingleShot(false);
    timer->setObjectName(QString::fromUtf8("timer"));
    timer->stop();

    toolBar = new QToolBar(this);
    toolBar->setObjectName(QString::fromUtf8("toolBar"));

    // Reset Camera Button
    actionShowControlPanel = new QAction(this);
    actionShowControlPanel->setObjectName(QString::fromUtf8("actionShowControlPanel"));
    actionShowControlPanel->setIcon(QPixmap(QString::fromUtf8(":/images/images/Control.png")));
    actionShowControlPanel->setToolTip("Click to Show Control Panel.");
    actionShowControlPanel->setStatusTip("Click to Show Control Panel.");
    actionShowControlPanel->setCheckable(true);
    actionShowControlPanel->setChecked(false);

    // Reset Camera Button
    actionResetCamera = new QAction(this);
    actionResetCamera->setObjectName(QString::fromUtf8("actionResetCamera"));
    actionResetCamera->setIcon(QPixmap(QString::fromUtf8(":/images/images/Camera.png")));
    actionResetCamera->setToolTip("Click to Reset Camera.");
    actionResetCamera->setStatusTip("Click to Reset Camera.");

    // Play or Pause Button
    actionPlay = new QAction(this);
    actionPlay->setObjectName(QString::fromUtf8("actionPlay"));
    actionPlay->setIcon(QPixmap(QString::fromUtf8(":/images/images/Pause.png")));
    actionPlay->setToolTip("Click to Pause.");
    actionPlay->setStatusTip("Click to Pause.");
    actionPlay->setCheckable(true);
    actionPlay->setChecked(false);

    toolBar->addAction(actionShowControlPanel);
    toolBar->addSeparator();
    toolBar->addAction(actionPlay);
    toolBar->addSeparator();
    toolBar->addAction(actionResetCamera);

    toolBar->setAutoFillBackground(true);

    QMetaObject::connectSlotsByName(this);
}

void BehaviorGlWidget::initializeGL() {
    glShadeModel(GL_SMOOTH);						// Enable Smooth Shading
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Background
    glClearDepth(1.0f);							// Depth Buffer Setup
    glEnable(GL_LIGHTING);						// Enable Lighting
    glEnable(GL_LIGHT0);						// First Light Source
    glEnable(GL_NORMALIZE);						// Normalize Surface Normal Vector
    glEnable(GL_BLEND);							// Blend Color
    glEnable(GL_DEPTH_TEST);						// Enables Depth Testing
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations

    //////////////////////////////////////////////////////////////////
    // Do any initialization of the rendering context here, such as
    // setting background colors, setting up lighting, or performing
    // preliminary calculations.
    float lightPosition[4] = {200.0f, 200.0f, 200.0f, 0.0};
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

    float lightColor[4] = {1.0f, 1.0f, 1.0f, 1.0f};
    float ambientColor[4] = {0.3f, 0.3f, 0.3f, 1.0f};
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientColor);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightColor);
}

void BehaviorGlWidget::resizeGL(int cx, int cy) {

    if (cy==0)										// Prevent A Divide By Zero By
    {
        cy=1;										// Making Height Equal One
    }

    glViewport(0,0,cx,cy);						// Reset The Current Viewport

    glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
    glLoadIdentity();									// Reset The Projection Matrix
    // Calculate The Aspect Ratio Of The Window
    m_BehaviorCamera.Perspective();

    glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
    glLoadIdentity();									// Reset The Modelview Matrix
}

void BehaviorGlWidget::paintGL() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    m_BehaviorCamera.LookAt();
    glDisable(GL_LIGHTING);
    m_BehaviorCamera.DrawFloor();
    glColor3f(1.0, 0.0, 0.0);
    glPushMatrix();
    glTranslated(goal[0], 0, goal[1]);
    glutSolidSphere(20.0, 12, 12);
    glPopMatrix();
    glEnable(GL_LIGHTING);
    sim.Display();
}

void BehaviorGlWidget::enterEvent(QEvent *event)
{
    QGLWidget::enterEvent(event);
    AgentDisplay::CreateDrawList();
    timer->start();
    setFocus();
    grabKeyboard();
}

void BehaviorGlWidget::leaveEvent(QEvent *event)
{
    QGLWidget::leaveEvent(event);
    timer->stop();
    releaseKeyboard();
}

void BehaviorGlWidget::mousePressEvent(QMouseEvent *event) {

    m_mouseButton = (int)event->button();
    if (!m_altKey && m_mouseButton == Qt::LeftButton)
    {
        this->ComputePostion(event->pos().x(), event->pos().y(), goal);
        sim.SetGoal(goal);
        this->glDraw();
    }
}

void BehaviorGlWidget::mouseReleaseEvent(QMouseEvent *){

    m_mouseButton = 0;
}

void BehaviorGlWidget::mouseMoveEvent(QMouseEvent *event) {
    QPoint point = event->pos();
    int dx, dy;

    if (m_altKey)
    {
        switch (m_mouseButton)
        {
        case Qt::LeftButton:
            // Rotate camera.

            if ( m_lastMouseX != -1 )
            {
                dy = point.y() - m_lastMouseY;
                dx = point.x() - m_lastMouseX;
                m_BehaviorCamera.RotateCenter(-dx, -dy);
                this->glDraw();
            }

            m_lastMouseX = point.x();
            m_lastMouseY = point.y();
            break;
        case Qt::RightButton:
            // Scale
            if ( m_lastMouseY != -1 )
            {
                m_BehaviorCamera.Zoom(((point.y() - m_lastMouseY) + (point.x() - m_lastMouseX)) / 2.0f);
                this->glDraw();
            }
            m_lastMouseY = point.y();
            m_lastMouseX = point.x();
            break;
        case Qt::MiddleButton:
            // Move camera
            if ( m_lastMouseX != -1 )
            {
                dx = (point.x() - m_lastMouseX);
                dy = (point.y() - m_lastMouseY);

                m_BehaviorCamera.MoveSWD(-dx, dy);

                this->glDraw();
            }
            m_lastMouseX = point.x();
            m_lastMouseY = point.y();
            break;
        default:
            m_lastMouseY = -1;
            m_lastMouseX = -1;
            break;
        }
    }
    else if (m_mouseButton == Qt::LeftButton)
    {
        this->ComputePostion(event->pos().x(), event->pos().y(), goal);
        sim.SetGoal(goal);
        this->glDraw();
    }
}

void BehaviorGlWidget::keyPressEvent(QKeyEvent* event) {

    switch(event->key()) {
    case Qt::Key_Alt:
        this->m_altKey = true;
        break;
    default:
        event->ignore();
        break;
    }
}

void BehaviorGlWidget::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Alt)
    {
        this->m_altKey = false;
        this->m_mouseButton = 0;
    }
}

void BehaviorGlWidget::on_actionShowControlPanel_triggered(bool checked)
{
    if (checked)
    {
        // Show Control Pannel
        control->show();

        actionShowControlPanel->setToolTip("Click to Hide Control Panel.");
        actionShowControlPanel->setStatusTip("Click to Hide Control Panel.");
    }
    else
    {
        // Hide Control Pannel
        control->hide();

        actionShowControlPanel->setToolTip("Click to Show Control Panel.");
        actionShowControlPanel->setStatusTip("Click to Show Control Panel.");
    }

}

void BehaviorGlWidget::on_actionResetCamera_triggered()
{
    m_BehaviorCamera.Reset();
    this->glDraw();
}

void BehaviorGlWidget::ComputePostion(int x, int y, vec2 &goal)
{
    vec3 P, N;
    float rx, ry, h, w, t;
    GLint viewport[4];
    glGetIntegerv(GL_VIEWPORT,viewport);
    rx = float(x * 2) / float(viewport[2]) - 1.0;
    ry = float(y * 2) / float(viewport[3]) - 1.0;
    h = m_BehaviorCamera.m_nearP * tan(m_BehaviorCamera.m_fovy / 360.0 * M_PI);
    w = h * float(viewport[2]) / float(viewport[3]);
    rx = rx * w;
    ry = -1.0 * ry * h;
    P = m_BehaviorCamera.m_eye + m_BehaviorCamera.m_frontVec + m_BehaviorCamera.m_rightVec * rx + m_BehaviorCamera.m_upVec * ry;
    P = P - m_BehaviorCamera.m_eye;
    P = P.Normalize();
    N = vec3(0.0, 1.0, 0.0);
    t = -1.0 * (m_BehaviorCamera.m_eye * N);
    t = t / (P * N);
    P = P * t + m_BehaviorCamera.m_eye;
    goal[0] = P[0];
    goal[1] = P[2];
}

void BehaviorGlWidget::on_actionPlay_triggered(bool checked)
{
    if (checked)
    {
        actionPlay->setToolTip("Click to Play.");
        actionPlay->setStatusTip("Click to Play.");
        onPlay = false;
    }
    else
    {
        actionPlay->setToolTip("Click to Pause.");
        actionPlay->setStatusTip("Click to Pause.");
        onPlay = true;
    }
}

void BehaviorGlWidget::on_timer_timeout()
{
    if (onPlay)
    {
        sim.SimulationStep(0.040f);
        this->glDraw();
    }
}

