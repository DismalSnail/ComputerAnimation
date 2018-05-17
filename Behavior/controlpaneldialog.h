#ifndef CONTROLPANELDIALOG_H
#define CONTROLPANELDIALOG_H

#include <QDialog>
#include "BehaviorGlWidget.h"

class BehaviorGlWidget;

namespace Ui {
class ControlPanelDialog;
}

class ControlPanelDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ControlPanelDialog(BehaviorGlWidget * main, QWidget *parent = 0);
    ~ControlPanelDialog();

private slots:
    void ControlPanelDialog_rejected();

    void on_seekRadioButton_clicked();

    void on_fleeRadioButton_clicked();

    void on_wanderRadioButton_clicked();

    void on_arrivalRadioButton_clicked();

    void on_departureRadioButton_clicked();

    void on_avoidRadioButton_clicked();

    void on_separationRadioButton_clicked();

    void on_flockingRadioButton_clicked();

    void on_alignmentRadioButton_clicked();

    void on_readerRadioButton_clicked();

    void on_cohesionRadioButton_clicked();

    void on_debugMode_stateChanged(int arg1);

    void on_agentNumberSpinBox_editingFinished();

    void on_maxVelocitySpinBox_editingFinished();

    void on_maxForceSpinBox_editingFinished();

    void on_maxTorqueSpinBox_editingFinished();

    void on_massSpinBox_editingFinished();

    void on_inertiaSpinBox_editingFinished();

    void on_maxWSpinBox_editingFinished();

    void on_velocityKvSpinBox_editingFinished();

    void on_headingSpinBox_editingFinished();

    void on_kpSpinBox_editingFinished();

    void on_arrivalSpinBox_editingFinished();

    void on_noiseSpinBox_editingFinished();

    void on_kAvoidSpinBox_editingFinished();

    void on_allginSpinBox_editingFinished();

    void on_cohesSpinBox_editingFinished();

    void on_departureSpinBox_editingFinished();

    void on_wanderSpinBox_editingFinished();

    void on_tAvoidSpinBox_editingFinished();

    void on_separateSpinBox_editingFinished();

    void on_rNeighborSpinBox_editingFinished();

    void on_applyButton_clicked();

protected:
    void initialize();
    void updatePanel();
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);

private:
    Ui::ControlPanelDialog *ui;
    BehaviorGlWidget * mainWindow;

    int 	m_Number;
    float	m_KAlign;
    float	m_KArrival;
    float	m_KAvoid;
    float	m_KCohesion;
    float	m_KDeparture;
    float	m_KNeighborhood;
    float	m_KNoise;
    float	m_KV0;
    float	m_KP1;
    float	m_KV1;
    float	m_KSeparate;
    float	m_KWander;
    float	m_TAvoid;
    float	m_Mass;
    float	m_MaxForce;
    float	m_MaxTorque;
    float	m_MaxVel;
    float	m_MaxW;
    float	m_Inertia;
};

#endif // CONTROLPANELDIALOG_H
