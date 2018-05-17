//////////////////////////////////////////////////////////////////////////
// interpolationdialog.cpp -- Source file for QT dialog that display the blend window.
//
// Tiantian Liu
// 11/11/2011
// University of Pennsylvania

#include "interpolationdialog.h"
#include "ui_interpolationdialog.h"
#include <QDebug>

int InterpolationDialog::defaultFrameLength = 10;

InterpolationDialog::InterpolationDialog(GLWidget * glw, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InterpolationDialog)
{
    ui->setupUi(this);
    glWindow = glw;

	type = 0;

    glWindow->m_player.BlendingReady(frameCount0, frameCount1);

    this->ui->spinBox_Anim1->setMinimum(1);
    this->ui->spinBox_Anim1->setMaximum(frameCount0 - 2);
    this->ui->spinBox_Anim2->setMinimum(1);
    this->ui->spinBox_Anim2->setMaximum(frameCount1 - 2);

    int i = this->glWindow->m_player.GetCurrentMotionIndex();
    this->glWindow->m_player.SetCurrentMotion(eMotion1);
    int frame1 = glWindow->m_player.GetCurrentMotion()->GetCurrentFrameCount();
    this->glWindow->m_player.SetCurrentMotion(eMotion2);
    int frame2 = glWindow->m_player.GetCurrentMotion()->GetCurrentFrameCount();
    this->glWindow->m_player.SetCurrentMotion(i);

    if (frame1 < 1)
        frame1 = 1;
    if (frame1 > frameCount0 - 2)
        frame1 = frameCount0 -2;
    if (frame2 < 1)
        frame2 = 1;
    if (frame2 > frameCount1 - 2)
        frame2 = frameCount1 -2;

    this->ui->spinBox_Anim1->setValue(frame1);
    this->ui->spinBox_Anim2->setValue(frame2);
	this->ui->spinBox_FrameNum->setValue(InterpolationDialog::defaultFrameLength);
}

InterpolationDialog::~InterpolationDialog()
{
    delete ui;
}

void InterpolationDialog::on_buttonBox_accepted()
{
    unsigned int startFrame = this->ui->spinBox_Anim1->value();
    unsigned int endFrame = this->ui->spinBox_Anim2->value();
    unsigned int interpFrame = this->ui->spinBox_FrameNum->value();
	InterpolationDialog::defaultFrameLength = interpFrame;

    glWindow->m_player.Blend(startFrame, endFrame, interpFrame, type);
    glWindow->m_player.SetCurrentMotion(eMotion3);
    glWindow->comboBoxSwitch_Motion->setCurrentIndex(2);
    glWindow->Update_Toolbar();
}

void InterpolationDialog::on_comboBox_type_currentIndexChanged(int index)
{
    type = index;
}
