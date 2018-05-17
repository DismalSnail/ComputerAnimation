
//////////////////////////////////////////////////////////////////////////
// glwidget.cpp -- Source file for useful methods of the openGL window in QT and it handls the events in the toolbar.
//
// Tiantian Liu
// 11/11/2011
// University of Pennsylvania

#include <QtGui/QMouseEvent>
#include <QTimer>
#include "glwidget.h"
#include "QDebug"
#include "GL/glut.h"
#include <iostream>

GLWidget::GLWidget(QWidget *parent) : QGLWidget(parent) {
    setMouseTracking(true);

    m_viewer.SetSkeleton(m_player.GetSkeleton());
    m_altKey = false;
    m_mouseButton  =0;
    deltaFrame = 0;
    mode = STP;

    // timer
    timer = new QTimer(this);
    timer->setInterval(40);
    timer->setSingleShot(false);
    timer->setObjectName(QString::fromUtf8("timer"));
    timer->stop();

    //connect(timer, SIGNAL(timeout()), this, SLOT(on_timer_timeout()));

    toolBar = new QToolBar(this);
    toolBar->setObjectName(QString::fromUtf8("toolBar"));

    // Slider
    slider = new QSlider(Qt::Horizontal, this);
    slider->setObjectName(QString::fromUtf8("slider"));
    slider->setFixedWidth(200);
    slider->setMinimum(0);
    slider->setMaximum(0);
    slider->setValue(0);

    // Label
    label = new QLabel(this);
    label->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    label->setFixedWidth(140);
    label->setText(QString("%1 / %2 Frames   ").arg(0).arg(0));

    // comboBox
    comboBoxSwitch_Motion = new QComboBox(this);
    comboBoxSwitch_Motion->setObjectName(QString::fromUtf8("comboBoxSwitch_Motion"));
    comboBoxSwitch_Motion->addItem("Animation 1");
    comboBoxSwitch_Motion->addItem("Animation 2");
    comboBoxSwitch_Motion->addItem("Blended Animation");

    // Open Button
    actionOpen = new QAction(this);
    actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
    actionOpen->setIcon(QPixmap(QString::fromUtf8(":/images/images/Open.png")));
    actionOpen->setToolTip("Click to open a BVH file for animation 1.");
    actionOpen->setStatusTip("Click to open a BVH file for animation 1.");

    // Save Button
    actionSave = new QAction(this);
    actionSave->setObjectName(QString::fromUtf8("actionSave"));
    actionSave->setIcon(QPixmap(QString::fromUtf8(":/images/images/Save.png")));
    actionSave->setToolTip("You can not save an empty file.");
    actionSave->setStatusTip("You can not save an empty file.");
    actionSave->setEnabled(false);

    // PlayBack Button
    actionPlay_Back = new QAction(this);
    actionPlay_Back->setObjectName(QString::fromUtf8("actionPlay_Back"));
    actionPlay_Back->setIcon(QPixmap(QString::fromUtf8(":/images/images/PlayBack.png")));
    actionPlay_Back->setToolTip("Click to play backwards.");
    actionPlay_Back->setStatusTip("Click to play backwards.");

    // StepBack Button
    actionStep_Back = new QAction(this);
    actionStep_Back->setObjectName(QString::fromUtf8("actionStep_Back"));
    actionStep_Back->setIcon(QPixmap(QString::fromUtf8(":/images/images/StepBack.png")));
    actionStep_Back->setToolTip("Click to step back by a frame.");
    actionStep_Back->setStatusTip("Click to step back by a frame.");

    // Pause Button
    actionPause = new QAction(this);
    actionPause->setObjectName(QString::fromUtf8("actionPause"));
    actionPause->setCheckable(true);
    actionPause->setIcon(QPixmap(QString::fromUtf8(":/images/images/Pause.png")));
    actionPause->setToolTip("Click to pause.");
    actionPause->setStatusTip("Click to pause.");
    actionPause->setChecked(true);

    // StepForward Button
    actionStep_Forward = new QAction(this);
    actionStep_Forward->setObjectName(QString::fromUtf8("actionStep_Forward"));
    actionStep_Forward->setIcon(QPixmap(QString::fromUtf8(":/images/images/StepForward.png")));
    actionStep_Forward->setToolTip("Click to step forward by a frame.");
    actionStep_Forward->setStatusTip("Click to step forward by a frame.");

    // PlayBack Button
    actionPlay = new QAction(this);
    actionPlay->setObjectName(QString::fromUtf8("actionPlay"));
    actionPlay->setIcon(QPixmap(QString::fromUtf8(":/images/images/Play.png")));
    actionPlay->setToolTip("Click to play.");
    actionPlay->setStatusTip("Click to play.");

    //IK Button
    actionIK = new QAction(this);
    actionIK->setObjectName(QString::fromUtf8("actionIK"));
    actionIK->setCheckable(true);
    actionIK->setIcon(QPixmap(QString::fromUtf8(":/images/images/IK.png")));
    actionIK->setToolTip("The current animation is empty.");
    actionIK->setStatusTip("The current animation is empty.");
    actionIK->setEnabled(false);

    // coordinate Button
    actionCoord = new QAction(this);
    actionCoord->setObjectName(QString::fromUtf8("actionCoord"));
    actionCoord->setCheckable(true);
    actionCoord->setChecked(true);
    actionCoord->setIcon(QPixmap(QString::fromUtf8(":/images/images/Line.png")));
    actionCoord->setToolTip("Show/Hide Coordinates.");
    actionCoord->setStatusTip("Show/Hide Coordinates.");

    // Skeleton Button
    actionSkeleton = new QAction(this);
    actionSkeleton->setObjectName(QString::fromUtf8("actionSkeleton"));
    actionSkeleton->setIcon(QPixmap(QString::fromUtf8(":/images/images/skeleton.png")));
    actionSkeleton->setToolTip("The current animation is empty.");
    actionSkeleton->setStatusTip("The current animation is empty.");
    actionSkeleton->setEnabled(false);

    // Apply Button
    actionApply = new QAction(this);
    actionApply->setObjectName(QString::fromUtf8("actionApply"));
    actionApply->setIcon(QPixmap(QString::fromUtf8(":/images/images/Correct.png")));
    actionApply->setToolTip("The current animation is empty.");
    actionApply->setStatusTip("The current animation is empty.");
    actionApply->setEnabled(false);

    // Blend Button
    actionBlend = new QAction(this);
    actionBlend->setObjectName(QString::fromUtf8("actionBlend"));
    actionBlend->setIcon(QPixmap(QString::fromUtf8(":/images/images/Blend.png")));
    actionBlend->setToolTip("Please load the BVH files for animation 1 and 2 first.");
    actionBlend->setStatusTip("Please load the BVH files for animation 1 and 2 first.");
    actionBlend->setEnabled(false);

    // Reset Camera Button
    actionResetCamera = new QAction(this);
    actionResetCamera->setObjectName(QString::fromUtf8("actionResetCamera"));
    actionResetCamera->setIcon(QPixmap(QString::fromUtf8(":/images/images/Camera.png")));
    actionResetCamera->setToolTip("Click to Reset Camera.");
    actionResetCamera->setStatusTip("Click to Reset Camera.");

    toolBar->addAction(actionOpen);
    toolBar->addAction(actionSave);
    toolBar->addSeparator();
    toolBar->addAction(actionPlay_Back);
    toolBar->addAction(actionStep_Back);
    toolBar->addAction(actionPause);
    toolBar->addAction(actionStep_Forward);
    toolBar->addAction(actionPlay);
    toolBar->addWidget(label);
    toolBar->addWidget(slider);
    toolBar->addSeparator();
    toolBar->addWidget(comboBoxSwitch_Motion);
    toolBar->addSeparator();
    toolBar->addAction(actionIK);
    toolBar->addSeparator();
    toolBar->addAction(actionApply);
    toolBar->addSeparator();
    toolBar->addAction(actionBlend);
    toolBar->addAction(actionSkeleton);
    toolBar->addSeparator();
    toolBar->addAction(actionCoord);
    toolBar->addAction(actionResetCamera);

    toolBar->setAutoFillBackground(true);

    QMetaObject::connectSlotsByName(this);
}

void GLWidget::initializeGL() {

    glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Background
    glClearDepth(1.0f);									// Depth Buffer Setup
    glEnable(GL_LIGHTING);								// Enable Lighting
    glEnable(GL_LIGHT0);								// First Light Source
    glEnable(GL_NORMALIZE);								// Normalize Surface Normal Vector
    glEnable(GL_BLEND);									// Blend Color
    glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
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

void GLWidget::resizeGL(int w, int h) {

    if (h == 0)
        h = 1; // prevent a divide by zero error;

    glViewport(0,0,w,h);						// Reset The Current Viewport

    glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
    glLoadIdentity();									// Reset The Projection Matrix
    // Calculate The Aspect Ratio Of The Window
    m_camera.Perspective();

    glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
    glLoadIdentity();
}

void GLWidget::paintGL() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    m_camera.LookAt();
    glDisable(GL_LIGHTING);
    m_camera.DrawFloor();
    glEnable(GL_LIGHTING);

    m_viewer.Display();
}

void GLWidget::enterEvent(QEvent *event)
{
    QGLWidget::enterEvent(event);
    timer->start();
    setFocus();
    grabKeyboard();
}

void GLWidget::leaveEvent(QEvent *event)
{
    QGLWidget::leaveEvent(event);
    timer->stop();
    releaseKeyboard();
}

void GLWidget::mousePressEvent(QMouseEvent *event) {

    m_mouseButton = (int)event->button();
}

void GLWidget::mouseReleaseEvent(QMouseEvent *){

    m_mouseButton = 0;
}

void GLWidget::mouseMoveEvent(QMouseEvent *event) {
    QPoint point = event->pos();
    int dx, dy;

    if (m_altKey)
    {
        switch (m_mouseButton)
        {
        case 1:
            // Rotate camera.
            if ( m_lastMouseX != -1 )
            {
                dy = point.y() - m_lastMouseY;
                dx = point.x() - m_lastMouseX;
                m_camera.RotateCenter(-dx, -dy);
                this->glDraw();
            }
            m_lastMouseX = point.x();
            m_lastMouseY = point.y();
            break;
        case 2:
            // Scale
            if ( m_lastMouseY != -1 )
            {
                m_camera.Zoom(((point.y() - m_lastMouseY) + (point.x() - m_lastMouseX)) / 2.0f);
                this->glDraw();
            }
            m_lastMouseY = point.y();
            m_lastMouseX = point.x();
            break;
        case 4:
            // Move camera
            if ( m_lastMouseX != -1 )
            {
                dx = (point.x() - m_lastMouseX);
                dy = (point.y() - m_lastMouseY);

                m_camera.MoveSWD(-dx, dy);

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
    if (m_shiftKey && m_viewer.GetMode() == eIKSelect)
    {
        switch (m_mouseButton)
        {
        case 1:
            ComputePos(point.x(), point.y());
            m_player.SolveIK();
            glDraw();
            break;
        default:
            break;
        }
    }
}

void GLWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    QPoint point = event->pos();
    if (m_player.IsValid())
    {
        PickObject(point.x(), point.y());
        Skeleton* pSkeleton = m_player.GetSkeleton();
        if (pSkeleton->GetSelectedJoint() >= 0 && m_viewer.GetMode() == eFKSelect)
        {
            SkeletonDialog skeletonDialog(this, this);
            skeletonDialog.setModal(true);
            skeletonDialog.exec();
        }

        glDraw();
    }
}

void GLWidget::keyPressEvent(QKeyEvent* event) {

    switch(event->key()) {
    case Qt::Key_Alt:
        this->m_altKey = true;
        break;
    case Qt::Key_Shift:
        this->m_shiftKey = true;
        break;
    default:
        event->ignore();
        break;
    }
}

void GLWidget::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Alt)
    {
        this->m_altKey = false;
        this->m_mouseButton = 0;
    }
    if (event->key() == Qt::Key_Shift)
    {
        this->m_shiftKey = false;
        this->m_mouseButton = 0;
    }
}

void GLWidget::on_actionOpen_triggered()
{
    bool status = false;
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open BVH File"), "", tr("Files (*.bvh)"));
    ifstream inFile(fileName.toLocal8Bit().data());
    if (inFile.is_open())
    {
        status = m_player.LoadBVHFile(inFile);
    }
    inFile.close();

    if (status)
    {
        Update_Toolbar();
        m_player.UpdateFrame();
        this->glDraw();
    }
    else
    {
        // TODO: What if things are not going well...
    }

    unsigned int frame_count0, frame_count1;
    if (m_player.BlendingReady(frame_count0, frame_count1))
    {
        actionBlend->setEnabled(true);
        actionBlend->setToolTip("Click to blend animation 1 and 2.");
        actionBlend->setStatusTip("Click to blend animation 1 and 2.");
    }
    else
    {
        actionBlend->setToolTip("Please load the BVH files for animation 1 and 2 first.");
        actionBlend->setStatusTip("Please load the BVH files for animation 1 and 2 first.");
        actionBlend->setEnabled(false);
    }

    Motion* pMotion = this->m_player.GetCurrentMotion();
    if (pMotion && pMotion->GetFrameCount())
    {
        actionSkeleton->setToolTip("View Skeleton Data.");
        actionSkeleton->setStatusTip("View Skeleton Data.");
        actionSkeleton->setEnabled(true);

        actionSave->setToolTip("Click to save the BVH file.");
        actionSave->setStatusTip("Click to save the BVH file.");
        actionSave->setEnabled(true);

        actionIK->setToolTip("Enable/Disable IK.");
        actionIK->setStatusTip("Enable/Disable IK.");
        actionIK->setEnabled(true);

        actionApply->setToolTip("Apply changes to the current motion.");
        actionApply->setStatusTip("Apply changes to the current motion.");
        actionApply->setEnabled(true);
    }
    else
    {
        actionSkeleton->setToolTip("The current animation is empty.");
        actionSkeleton->setStatusTip("The current animation is empty.");
        actionSkeleton->setEnabled(false);

        actionSave->setToolTip("You can not save an empty file.");
        actionSave->setStatusTip("You can not save an empty file.");
        actionSave->setEnabled(false);

        actionIK->setToolTip("The current animation is empty.");
        actionIK->setStatusTip("The current animation is empty.");
        actionIK->setEnabled(false);

        actionApply->setToolTip("The current animation is empty.");
        actionApply->setStatusTip("The current animation is empty.");
        actionApply->setEnabled(false);
    }
}

void GLWidget::on_actionSave_triggered()
{
    bool status = false;
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save BVH File as..."), "", tr("Files (*.bvh)"));
    if (fileName != "")
    {
        ofstream outFile(fileName.toLocal8Bit().data());
        if (outFile.is_open())
        {
            status = m_player.SaveBVHFile(outFile);
        }
        outFile.close();
    }
    if (status == false)
    {
        // TODO: What if things are not going well...
    }
}

void GLWidget::on_actionPlay_Back_triggered()
{
    Motion *pMotion = this->m_player.GetCurrentMotion();

    if (pMotion && pMotion->GetFrameCount() != 0)
    {
        actionPause->setChecked(false);
        mode = PBW;
    }
}

void GLWidget::on_actionStep_Back_triggered()
{
    Motion *pMotion = this->m_player.GetCurrentMotion();

    if (pMotion && pMotion->GetFrameCount() != 0)
    {
        actionPause->setChecked(true);
        mode = SBW;
        pMotion->Update(-1);
        Update_Toolbar();
        glDraw();
    }
}
void GLWidget::on_actionPause_triggered(bool checked)
{
    if (checked)
    {
        mode = STP;
    }
    else
    {
        on_actionPlay_triggered();
    }
}
void GLWidget::on_actionStep_Forward_triggered()
{
    Motion *pMotion = this->m_player.GetCurrentMotion();

    if (pMotion && pMotion->GetFrameCount() != 0)
    {
        actionPause->setChecked(true);
        mode = SFW;
        pMotion->Update(1);
        Update_Toolbar();
        glDraw();
    }
}
void GLWidget::on_actionPlay_triggered()
{
    Motion *pMotion = this->m_player.GetCurrentMotion();

    if (pMotion && pMotion->GetFrameCount() != 0)
    {
        actionPause->setChecked(false);
        mode = PFW;
    }
}
void GLWidget::Update_Toolbar()
{
    Motion* pMotion = this->m_player.GetCurrentMotion();
    if (pMotion && pMotion->GetFrameCount() > 0)
    {
        slider->setMaximum(pMotion->GetFrameCount());
        slider->setValue(pMotion->GetCurrentFrameCount());
        label->setText(QString("%1 / %2 Frames   ").arg(pMotion->GetCurrentFrameCount()).arg(pMotion->GetFrameCount()));
    }
    else
    {
        slider->setMaximum(0);
        slider->setValue(0);
        label->setText(QString("%1 / %2 Frames   ").arg(0).arg(0));
    }
}

void GLWidget::on_comboBoxSwitch_Motion_currentIndexChanged(int index)
{
    if (index == 0 || index == 1)
    {
        actionOpen->setEnabled(true);
        actionOpen->setToolTip("Click to save the BVH file.");
        actionOpen->setStatusTip("Click to save the BVH file.");
    }
    else
    {
        actionOpen->setEnabled(false);
        actionOpen->setToolTip("You can not assign BVH motion to the blended animation.");
        actionOpen->setStatusTip("You can not assign BVH motion to the blended animation.");
    }
    m_player.SetCurrentMotion(index+1);
    Update_Toolbar();
    m_player.UpdateFrame();
    glDraw();

    Motion* pMotion = this->m_player.GetCurrentMotion();
    if (pMotion && pMotion->GetFrameCount())
    {
        actionSkeleton->setToolTip("View Skeleton Data.");
        actionSkeleton->setStatusTip("View Skeleton Data.");
        actionSkeleton->setEnabled(true);

        actionSave->setToolTip("Click to save the BVH file.");
        actionSave->setStatusTip("Click to save the BVH file.");
        actionSave->setEnabled(true);

        actionIK->setToolTip("Enable/Disable IK.");
        actionIK->setStatusTip("Enable/Disable IK.");
        actionIK->setEnabled(true);

        actionApply->setToolTip("Apply changes to the current motion.");
        actionApply->setStatusTip("Apply changes to the current motion.");
        actionApply->setEnabled(true);
    }
    else
    {
        actionSkeleton->setToolTip("The current animation is empty.");
        actionSkeleton->setStatusTip("The current animation is empty.");
        actionSkeleton->setEnabled(false);

        actionSave->setToolTip("You can not save an empty file.");
        actionSave->setStatusTip("You can not save an empty file.");
        actionSave->setEnabled(false);

        actionIK->setToolTip("The current animation is empty.");
        actionIK->setStatusTip("The current animation is empty.");
        actionIK->setEnabled(false);

        actionApply->setToolTip("The current animation is empty.");
        actionApply->setStatusTip("The current animation is empty.");
        actionApply->setEnabled(false);
    }
}

void GLWidget::on_slider_valueChanged()
{
    int frame = slider->value();
    Motion* pMotion = this->m_player.GetCurrentMotion();
    if (pMotion == NULL || pMotion->GetFrameCount() == 0)
        return;
    int frameCount = int(pMotion->GetFrameCount());
    if (frame >= frameCount){
        frame = frameCount - 1;
    }
    pMotion->SetCurrentFrameCount(unsigned int(frame));
    m_player.UpdateFrame();
    glDraw();
    label->setText(QString("%1 / %2 Frames   ").arg(frame).arg(frameCount));
}

void GLWidget::on_actionCoord_triggered(bool checked)
{
    m_viewer.SetDrawCoord(checked);
    glDraw();
}

void GLWidget::on_actionIK_triggered(bool checked)
{
    if (m_player.IsValid())
    {
        Skeleton* pSkeleton = m_player.GetSkeleton();
        m_viewer.SetMode(checked?eIKSelect:eFKSelect);
        pSkeleton->SetSelectedJoint(-1);
    }
    glDraw();
}

void GLWidget::on_actionApply_triggered()
{
    if (m_player.IsValid())
        m_player.SaveFrame();
}

void GLWidget::on_actionBlend_triggered()
{
    InterpolationDialog interpDialog(this, this);
    interpDialog.setModal(true);
    interpDialog.exec();
}

void GLWidget::on_actionSkeleton_triggered()
{
    SkeletonDialog skeletonDialog(this, this);
    skeletonDialog.setModal(true);
    skeletonDialog.exec();
}

void GLWidget::PickObject(int x, int y)
{
    GLuint selectBuf[512];
    GLint hits;
    GLint viewport[4];

    int selection;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glSelectBuffer(512, selectBuf);//Can't be in selection mode here
    glGetIntegerv(GL_VIEWPORT,viewport);
    glRenderMode(GL_SELECT);
    glInitNames() ;

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluPickMatrix((GLdouble) x, (GLdouble) (viewport[3] - y), 5.0, 5.0, viewport);
    m_camera.Perspective();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    m_camera.LookAt();
    m_viewer.SetGlPick(true);
    m_viewer.Display();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glFlush();

    hits = glRenderMode(GL_RENDER);

    selection = ProcessHits(hits, selectBuf);

    m_viewer.SetGlPick(false);

    m_player.GetSkeleton()->SetSelectedJoint(selection);
}

int GLWidget::ProcessHits(GLint hits, GLuint buffer[])
{
    GLuint names, *ptr, minZ, *ptrNames, numberOfNames, closestName;

    ptr = (GLuint *)buffer;

    if (!hits)
        return -1;

    minZ = 0xffffffff;
    for (int i = 0; i < hits; i++)
    {
        names = *ptr;
        ptr++;
        if (*ptr < minZ) {
            numberOfNames = names;
            minZ = *ptr;
            ptrNames = ptr+2;
        }
        ptr += names+2;
    }
    closestName = *ptrNames;
    return int(closestName);
}

void GLWidget::ComputePos(int x, int y)
{
    Skeleton* pSkeleton = m_player.GetSkeleton();
    vec3 Pos = pSkeleton->GetGoalPosition();
    vec3 LPos;
    LPos = Pos - m_camera.GetEye();
    vec3 LCoord;
    LCoord[2] = LPos * m_camera.GetFrontVector();

    GLint viewport[4];
    glGetIntegerv(GL_VIEWPORT,viewport);
    float talpha = tan(30.0f * Deg2Rad);
    float tbeta = talpha * float(viewport[2]) / float(viewport[3]);
    LCoord[0] = (x - float(viewport[2])/2.0f) / (float(viewport[2])/2.0f) * tbeta * LCoord[2];
    LCoord[1] = (float(viewport[3])/2.0f - y) / (float(viewport[3])/2.0f) * talpha * LCoord[2];

    LPos = m_camera.GetRightVector() * LCoord[0] + m_camera.GetUpVector() * LCoord[1] + m_camera.GetFrontVector() * LCoord[2];

    pSkeleton->SetGoalPosition(m_camera.GetEye() + LPos);
}

void GLWidget::on_actionResetCamera_triggered()
{
    m_camera.Reset();
    glDraw();
}

void GLWidget::on_timer_timeout()
{
    Motion *pMotion = this->m_player.GetCurrentMotion();

    if (pMotion && pMotion->GetFrameCount() != 0)
    {
        switch(mode)
        {
        case PBW:
            pMotion->Update(-1);
            Update_Toolbar();
            glDraw();
            break;
        case PFW:
            pMotion->Update(1);
            Update_Toolbar();
            glDraw();
            break;
        case SFW:
        case SBW:
        case STP:
        default:
            break;
        }
    }
}
