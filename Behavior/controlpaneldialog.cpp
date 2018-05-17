#include "controlpaneldialog.h"
#include "ui_controlpaneldialog.h"
#include <QDebug>

ControlPanelDialog::ControlPanelDialog(BehaviorGlWidget * main, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ControlPanelDialog)
{
    ui->setupUi(this);
    this->mainWindow = main;

    connect(this, SIGNAL(rejected()), this, SLOT(ControlPanelDialog_rejected()));
    this->setWindowFlags(Qt::Window);

    this->initialize();
    this->updatePanel();
}

ControlPanelDialog::~ControlPanelDialog()
{
    delete ui;
}

void ControlPanelDialog::initialize()
{
    m_Number = 1;
    mainWindow->sim.CreateAgents(m_Number);
    mainWindow->sim.type = ARRIVAL;
    m_Mass = CAgent::Mass;
    m_Inertia = CAgent::Inertia;
    m_MaxForce = CAgent::MaxForce;
    m_MaxTorque = CAgent::MaxTorque;
    m_MaxW = CAgent::MaxAngVel;
    m_MaxVel = CAgent::MaxVelocity;
    m_KAlign = CAgent::KAlign;
    m_KArrival = CAgent::KArrival;
    m_KAvoid = CAgent::KAvoid;
    m_KCohesion = CAgent::KCohesion;
    m_KDeparture = CAgent::KDeparture;
    m_KNeighborhood = CAgent::RNeighborhood;
    m_KNoise = CAgent::KNoise;
    m_KV0 = CAgent::Kv0;
    m_KP1 = CAgent::Kp1;
    m_KV1 = CAgent::Kv1;
    m_KSeparate = CAgent::KSeparate;
    m_KWander = CAgent::KWander;
    m_TAvoid = CAgent::TAvoid;
}

void ControlPanelDialog::updatePanel()
{
    ui->agentNumberSpinBox->setValue(m_Number);
    ui->massSpinBox->setValue(m_Mass);
    ui->inertiaSpinBox->setValue(m_Inertia);
    ui->maxForceSpinBox->setValue(m_MaxForce);
    ui->maxTorqueSpinBox->setValue(m_MaxTorque);
    ui->maxWSpinBox->setValue(m_MaxW);
    ui->maxVelocitySpinBox->setValue(m_MaxVel);
    ui->allginSpinBox->setValue(m_KAlign);
    ui->arrivalSpinBox->setValue(m_KArrival);
    ui->kAvoidSpinBox->setValue(m_KAvoid);
    ui->cohesSpinBox->setValue(m_KCohesion);
    ui->departureSpinBox->setValue(m_KDeparture);
    ui->rNeighborSpinBox->setValue(m_KNeighborhood);
    ui->noiseSpinBox->setValue(m_KNoise);
    ui->velocityKvSpinBox->setValue(m_KV0);
    ui->headingSpinBox->setValue(m_KV1);
    ui->kpSpinBox->setValue(m_KP1);
    ui->separateSpinBox->setValue(m_KSeparate);
    ui->wanderSpinBox->setValue(m_KWander);
    ui->tAvoidSpinBox->setValue(m_TAvoid);
}

void ControlPanelDialog::ControlPanelDialog_rejected()
{
    mainWindow->actionShowControlPanel->setChecked(false);
    mainWindow->actionShowControlPanel->setToolTip("Click to Show Control Panel.");
    mainWindow-> actionShowControlPanel->setStatusTip("Click to Show Control Panel.");
}

void ControlPanelDialog::enterEvent(QEvent * event)
{
    QDialog::enterEvent(event);
    mainWindow->timer->start();
    //this->setWindowOpacity(1.0);
}

void ControlPanelDialog::leaveEvent(QEvent * event)
{
    QDialog::leaveEvent(event);
    mainWindow->timer->stop();
    //this->setWindowOpacity(0.8);
}

void ControlPanelDialog::on_seekRadioButton_clicked()
{
    mainWindow->sim.type = SEEK;
}

void ControlPanelDialog::on_fleeRadioButton_clicked()
{
    mainWindow->sim.type = FLEE;
}

void ControlPanelDialog::on_wanderRadioButton_clicked()
{
    mainWindow->sim.type = WANDER;
}

void ControlPanelDialog::on_arrivalRadioButton_clicked()
{
    mainWindow->sim.type = ARRIVAL;
}

void ControlPanelDialog::on_departureRadioButton_clicked()
{
    mainWindow->sim.type = DEPARTURE;
}

void ControlPanelDialog::on_avoidRadioButton_clicked()
{
    mainWindow->sim.env.GenerateObstacles(4);
    mainWindow->sim.type = AVOID;
}

void ControlPanelDialog::on_separationRadioButton_clicked()
{
    mainWindow->sim.type = SEPARATION;
}

void ControlPanelDialog::on_flockingRadioButton_clicked()
{
    mainWindow->sim.type = FLOCKING;
}

void ControlPanelDialog::on_alignmentRadioButton_clicked()
{
    mainWindow->sim.type = ALIGNMENT;
}

void ControlPanelDialog::on_readerRadioButton_clicked()
{
    mainWindow->sim.type = LEADER;
}

void ControlPanelDialog::on_cohesionRadioButton_clicked()
{
    mainWindow->sim.type = COHESION;
}

void ControlPanelDialog::on_debugMode_stateChanged(int arg1)
{
    if (!arg1)
        CAgent::debug = false;
    else
        CAgent::debug = true;
}

void ControlPanelDialog::on_agentNumberSpinBox_editingFinished()
{
    int num = ui->agentNumberSpinBox->value();
    if (!num)
    {
        ui->AgentProperties->setEnabled(false);
        ui->BehaviorSettings->setEnabled(false);
        ui->ControlSettings->setEnabled(false);
        ui->Behaviors->setEnabled(false);
    }
    else
    {
        ui->AgentProperties->setEnabled(true);
        ui->BehaviorSettings->setEnabled(true);
        ui->ControlSettings->setEnabled(true);
        ui->Behaviors->setEnabled(true);
    }
    mainWindow->sim.CreateAgents(num);
}

void ControlPanelDialog::on_maxVelocitySpinBox_editingFinished()
{
    m_MaxVel = ui->maxVelocitySpinBox->value();
    //CAgent::MaxVelocity = m_MaxVel;
}

void ControlPanelDialog::on_maxForceSpinBox_editingFinished()
{
    m_MaxForce = ui->maxForceSpinBox->value();
    //CAgent::MaxForce = m_MaxForce;
}

void ControlPanelDialog::on_maxTorqueSpinBox_editingFinished()
{
    m_MaxTorque = ui->maxTorqueSpinBox->value();
    //CAgent::MaxTorque = m_MaxTorque;
}

void ControlPanelDialog::on_massSpinBox_editingFinished()
{
    m_Mass = ui->massSpinBox->value();
    //CAgent::Mass = m_Mass;
}

void ControlPanelDialog::on_inertiaSpinBox_editingFinished()
{
    m_Inertia = ui->inertiaSpinBox->value();
    //CAgent::Inertia = m_Inertia;
}

void ControlPanelDialog::on_maxWSpinBox_editingFinished()
{
    m_MaxW = ui->maxWSpinBox->value();
    //CAgent::MaxAngVel = m_MaxW;
}

void ControlPanelDialog::on_velocityKvSpinBox_editingFinished()
{
    m_KV0 = ui->velocityKvSpinBox->value();
    //CAgent::Kv0 = m_KV0;
}

void ControlPanelDialog::on_headingSpinBox_editingFinished()
{
    m_KV1 = ui->headingSpinBox->value();
    //CAgent::Kv1 = m_KV1;
}

void ControlPanelDialog::on_kpSpinBox_editingFinished()
{
    m_KP1 = ui->kpSpinBox->value();
    //CAgent::Kp1 = m_KP1;
}

void ControlPanelDialog::on_arrivalSpinBox_editingFinished()
{
    m_KArrival = ui->arrivalSpinBox->value();
    //CAgent::KArrival = m_KArrival;
}

void ControlPanelDialog::on_noiseSpinBox_editingFinished()
{
    m_KNoise = ui->noiseSpinBox->value();
    //CAgent::KNoise = m_KNoise;
}

void ControlPanelDialog::on_kAvoidSpinBox_editingFinished()
{
    m_KAvoid = ui->kAvoidSpinBox->value();
    //CAgent::KAvoid = m_KAvoid;
}

void ControlPanelDialog::on_allginSpinBox_editingFinished()
{
    m_KAlign = ui->allginSpinBox->value();
    //CAgent::KAlign = m_KAlign;
}

void ControlPanelDialog::on_cohesSpinBox_editingFinished()
{
    m_KCohesion = ui->cohesSpinBox->value();
    //CAgent::KCohesion = m_KCohesion;
}

void ControlPanelDialog::on_departureSpinBox_editingFinished()
{
    m_KDeparture = ui->departureSpinBox->value();
    //CAgent::KDeparture = m_KDeparture;
}

void ControlPanelDialog::on_wanderSpinBox_editingFinished()
{
    m_KWander = ui->wanderSpinBox->value();
    //CAgent::KWander = m_KWander;
}

void ControlPanelDialog::on_tAvoidSpinBox_editingFinished()
{
    m_TAvoid = ui->tAvoidSpinBox->value();
    //CAgent::TAvoid = m_TAvoid;
}

void ControlPanelDialog::on_separateSpinBox_editingFinished()
{
    m_KSeparate = ui->separateSpinBox->value();
    //CAgent::KSeparate = m_KSeparate;
}

void ControlPanelDialog::on_rNeighborSpinBox_editingFinished()
{
    m_KNeighborhood = ui->rNeighborSpinBox->value();
    //CAgent::RNeighborhood = m_KNeighborhood;
}

void ControlPanelDialog::on_applyButton_clicked()
{
    CAgent::MaxVelocity = m_MaxVel;
    CAgent::MaxForce = m_MaxForce;
    CAgent::MaxTorque = m_MaxTorque;
    CAgent::Mass = m_Mass;
    CAgent::Inertia = m_Inertia;
    CAgent::MaxAngVel = m_MaxW;
    CAgent::Kv0 = m_KV0;
    CAgent::Kv1 = m_KV1;
    CAgent::Kp1 = m_KP1;
    CAgent::KArrival = m_KArrival;
    CAgent::KNoise = m_KNoise;
    CAgent::KAvoid = m_KAvoid;
    CAgent::KAlign = m_KAlign;
    CAgent::KCohesion = m_KCohesion;
    CAgent::KDeparture = m_KDeparture;
    CAgent::KWander = m_KWander;
    CAgent::TAvoid = m_TAvoid;
    CAgent::KSeparate = m_KSeparate;
    CAgent::RNeighborhood = m_KNeighborhood;
}
