/********************************************************************************
** Form generated from reading UI file 'controlpaneldialog.ui'
**
** Created: Thu Dec 1 14:07:31 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLPANELDIALOG_H
#define UI_CONTROLPANELDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ControlPanelDialog
{
public:
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *GerneralControl;
    QLabel *label;
    QSpinBox *agentNumberSpinBox;
    QCheckBox *debugMode;
    QGroupBox *AgentProperties;
    QLabel *label_2;
    QSpinBox *maxVelocitySpinBox;
    QSpinBox *maxForceSpinBox;
    QLabel *label_3;
    QSpinBox *maxTorqueSpinBox;
    QLabel *label_4;
    QSpinBox *massSpinBox;
    QSpinBox *maxWSpinBox;
    QLabel *label_5;
    QLabel *label_6;
    QSpinBox *inertiaSpinBox;
    QLabel *label_7;
    QGroupBox *ControlSettings;
    QLabel *label_14;
    QSpinBox *headingSpinBox;
    QLabel *label_15;
    QSpinBox *kpSpinBox;
    QLabel *label_19;
    QDoubleSpinBox *velocityKvSpinBox;
    QGroupBox *BehaviorSettings;
    QLabel *label_26;
    QSpinBox *noiseSpinBox;
    QLabel *label_27;
    QSpinBox *kAvoidSpinBox;
    QLabel *label_28;
    QSpinBox *departureSpinBox;
    QSpinBox *tAvoidSpinBox;
    QLabel *label_29;
    QLabel *label_30;
    QSpinBox *wanderSpinBox;
    QLabel *label_31;
    QLabel *label_32;
    QSpinBox *allginSpinBox;
    QLabel *label_33;
    QSpinBox *separateSpinBox;
    QLabel *label_34;
    QSpinBox *rNeighborSpinBox;
    QLabel *label_35;
    QDoubleSpinBox *arrivalSpinBox;
    QDoubleSpinBox *cohesSpinBox;
    QGroupBox *Behaviors;
    QRadioButton *seekRadioButton;
    QRadioButton *arrivalRadioButton;
    QRadioButton *wanderRadioButton;
    QRadioButton *fleeRadioButton;
    QRadioButton *departureRadioButton;
    QRadioButton *avoidRadioButton;
    QRadioButton *alignmentRadioButton;
    QRadioButton *separationRadioButton;
    QRadioButton *flockingRadioButton;
    QRadioButton *readerRadioButton;
    QRadioButton *cohesionRadioButton;
    QLabel *label_8;
    QLabel *label_10;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;
    QFrame *line_5;
    QGroupBox *groupBox;
    QPushButton *applyButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *ControlPanelDialog)
    {
        if (ControlPanelDialog->objectName().isEmpty())
            ControlPanelDialog->setObjectName(QString::fromUtf8("ControlPanelDialog"));
        ControlPanelDialog->setWindowModality(Qt::NonModal);
        ControlPanelDialog->resize(442, 720);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/Control.png"), QSize(), QIcon::Normal, QIcon::Off);
        ControlPanelDialog->setWindowIcon(icon);
        ControlPanelDialog->setWindowOpacity(1);
        verticalLayout = new QVBoxLayout(ControlPanelDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        scrollArea = new QScrollArea(ControlPanelDialog);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setFrameShadow(QFrame::Raised);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 424, 702));
        verticalLayout_3 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        GerneralControl = new QGroupBox(scrollAreaWidgetContents);
        GerneralControl->setObjectName(QString::fromUtf8("GerneralControl"));
        GerneralControl->setMinimumSize(QSize(401, 51));
        GerneralControl->setMaximumSize(QSize(401, 51));
        GerneralControl->setAutoFillBackground(false);
        GerneralControl->setFlat(false);
        GerneralControl->setCheckable(false);
        label = new QLabel(GerneralControl);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 69, 21));
        agentNumberSpinBox = new QSpinBox(GerneralControl);
        agentNumberSpinBox->setObjectName(QString::fromUtf8("agentNumberSpinBox"));
        agentNumberSpinBox->setGeometry(QRect(110, 20, 71, 20));
        agentNumberSpinBox->setMaximum(20);
        debugMode = new QCheckBox(GerneralControl);
        debugMode->setObjectName(QString::fromUtf8("debugMode"));
        debugMode->setGeometry(QRect(220, 20, 79, 17));

        verticalLayout_2->addWidget(GerneralControl);

        AgentProperties = new QGroupBox(scrollAreaWidgetContents);
        AgentProperties->setObjectName(QString::fromUtf8("AgentProperties"));
        AgentProperties->setMinimumSize(QSize(401, 111));
        AgentProperties->setMaximumSize(QSize(401, 111));
        AgentProperties->setAutoFillBackground(false);
        AgentProperties->setFlat(false);
        AgentProperties->setCheckable(false);
        label_2 = new QLabel(AgentProperties);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 20, 69, 21));
        maxVelocitySpinBox = new QSpinBox(AgentProperties);
        maxVelocitySpinBox->setObjectName(QString::fromUtf8("maxVelocitySpinBox"));
        maxVelocitySpinBox->setGeometry(QRect(110, 20, 71, 20));
        maxVelocitySpinBox->setMaximum(10000);
        maxForceSpinBox = new QSpinBox(AgentProperties);
        maxForceSpinBox->setObjectName(QString::fromUtf8("maxForceSpinBox"));
        maxForceSpinBox->setGeometry(QRect(110, 50, 71, 20));
        maxForceSpinBox->setMaximum(10000);
        label_3 = new QLabel(AgentProperties);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 50, 69, 21));
        maxTorqueSpinBox = new QSpinBox(AgentProperties);
        maxTorqueSpinBox->setObjectName(QString::fromUtf8("maxTorqueSpinBox"));
        maxTorqueSpinBox->setGeometry(QRect(110, 80, 71, 20));
        maxTorqueSpinBox->setMaximum(10000);
        label_4 = new QLabel(AgentProperties);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 80, 69, 21));
        massSpinBox = new QSpinBox(AgentProperties);
        massSpinBox->setObjectName(QString::fromUtf8("massSpinBox"));
        massSpinBox->setGeometry(QRect(310, 20, 71, 20));
        massSpinBox->setMinimum(1);
        massSpinBox->setMaximum(10000);
        massSpinBox->setValue(1);
        maxWSpinBox = new QSpinBox(AgentProperties);
        maxWSpinBox->setObjectName(QString::fromUtf8("maxWSpinBox"));
        maxWSpinBox->setGeometry(QRect(310, 80, 71, 20));
        maxWSpinBox->setMinimum(0);
        maxWSpinBox->setMaximum(10000);
        maxWSpinBox->setValue(10);
        label_5 = new QLabel(AgentProperties);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(220, 20, 69, 21));
        label_6 = new QLabel(AgentProperties);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(220, 80, 69, 21));
        inertiaSpinBox = new QSpinBox(AgentProperties);
        inertiaSpinBox->setObjectName(QString::fromUtf8("inertiaSpinBox"));
        inertiaSpinBox->setGeometry(QRect(310, 50, 71, 20));
        inertiaSpinBox->setMinimum(1);
        inertiaSpinBox->setMaximum(10000);
        inertiaSpinBox->setValue(1);
        label_7 = new QLabel(AgentProperties);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(220, 50, 69, 21));

        verticalLayout_2->addWidget(AgentProperties);

        ControlSettings = new QGroupBox(scrollAreaWidgetContents);
        ControlSettings->setObjectName(QString::fromUtf8("ControlSettings"));
        ControlSettings->setMinimumSize(QSize(401, 81));
        ControlSettings->setMaximumSize(QSize(401, 81));
        ControlSettings->setAutoFillBackground(false);
        ControlSettings->setFlat(false);
        ControlSettings->setCheckable(false);
        label_14 = new QLabel(ControlSettings);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(20, 20, 69, 21));
        headingSpinBox = new QSpinBox(ControlSettings);
        headingSpinBox->setObjectName(QString::fromUtf8("headingSpinBox"));
        headingSpinBox->setGeometry(QRect(110, 50, 71, 20));
        headingSpinBox->setMaximum(10000);
        label_15 = new QLabel(ControlSettings);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(20, 50, 69, 21));
        kpSpinBox = new QSpinBox(ControlSettings);
        kpSpinBox->setObjectName(QString::fromUtf8("kpSpinBox"));
        kpSpinBox->setGeometry(QRect(310, 50, 71, 20));
        kpSpinBox->setMaximum(10000);
        label_19 = new QLabel(ControlSettings);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(220, 50, 69, 21));
        velocityKvSpinBox = new QDoubleSpinBox(ControlSettings);
        velocityKvSpinBox->setObjectName(QString::fromUtf8("velocityKvSpinBox"));
        velocityKvSpinBox->setGeometry(QRect(110, 20, 71, 22));
        velocityKvSpinBox->setMaximum(10000);
        velocityKvSpinBox->setSingleStep(0.01);

        verticalLayout_2->addWidget(ControlSettings);

        BehaviorSettings = new QGroupBox(scrollAreaWidgetContents);
        BehaviorSettings->setObjectName(QString::fromUtf8("BehaviorSettings"));
        BehaviorSettings->setMinimumSize(QSize(401, 171));
        BehaviorSettings->setMaximumSize(QSize(401, 171));
        BehaviorSettings->setAutoFillBackground(false);
        BehaviorSettings->setFlat(false);
        BehaviorSettings->setCheckable(false);
        label_26 = new QLabel(BehaviorSettings);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(20, 20, 69, 21));
        noiseSpinBox = new QSpinBox(BehaviorSettings);
        noiseSpinBox->setObjectName(QString::fromUtf8("noiseSpinBox"));
        noiseSpinBox->setGeometry(QRect(110, 50, 71, 20));
        noiseSpinBox->setMaximum(10000);
        label_27 = new QLabel(BehaviorSettings);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(20, 50, 69, 21));
        kAvoidSpinBox = new QSpinBox(BehaviorSettings);
        kAvoidSpinBox->setObjectName(QString::fromUtf8("kAvoidSpinBox"));
        kAvoidSpinBox->setGeometry(QRect(110, 80, 71, 20));
        kAvoidSpinBox->setMaximum(10000);
        label_28 = new QLabel(BehaviorSettings);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(20, 80, 69, 21));
        departureSpinBox = new QSpinBox(BehaviorSettings);
        departureSpinBox->setObjectName(QString::fromUtf8("departureSpinBox"));
        departureSpinBox->setGeometry(QRect(310, 20, 71, 20));
        departureSpinBox->setMaximum(10000);
        tAvoidSpinBox = new QSpinBox(BehaviorSettings);
        tAvoidSpinBox->setObjectName(QString::fromUtf8("tAvoidSpinBox"));
        tAvoidSpinBox->setGeometry(QRect(310, 80, 71, 20));
        tAvoidSpinBox->setMaximum(10000);
        label_29 = new QLabel(BehaviorSettings);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(220, 20, 69, 21));
        label_30 = new QLabel(BehaviorSettings);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(220, 80, 69, 21));
        wanderSpinBox = new QSpinBox(BehaviorSettings);
        wanderSpinBox->setObjectName(QString::fromUtf8("wanderSpinBox"));
        wanderSpinBox->setGeometry(QRect(310, 50, 71, 20));
        wanderSpinBox->setMaximum(10000);
        label_31 = new QLabel(BehaviorSettings);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setGeometry(QRect(220, 50, 69, 21));
        label_32 = new QLabel(BehaviorSettings);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setGeometry(QRect(220, 140, 69, 21));
        allginSpinBox = new QSpinBox(BehaviorSettings);
        allginSpinBox->setObjectName(QString::fromUtf8("allginSpinBox"));
        allginSpinBox->setGeometry(QRect(110, 110, 71, 20));
        allginSpinBox->setMaximum(10000);
        label_33 = new QLabel(BehaviorSettings);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setGeometry(QRect(20, 110, 69, 21));
        separateSpinBox = new QSpinBox(BehaviorSettings);
        separateSpinBox->setObjectName(QString::fromUtf8("separateSpinBox"));
        separateSpinBox->setGeometry(QRect(310, 110, 71, 20));
        separateSpinBox->setMaximum(10000);
        label_34 = new QLabel(BehaviorSettings);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setGeometry(QRect(20, 140, 69, 21));
        rNeighborSpinBox = new QSpinBox(BehaviorSettings);
        rNeighborSpinBox->setObjectName(QString::fromUtf8("rNeighborSpinBox"));
        rNeighborSpinBox->setGeometry(QRect(310, 140, 71, 20));
        rNeighborSpinBox->setMaximum(10000);
        label_35 = new QLabel(BehaviorSettings);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setGeometry(QRect(220, 110, 69, 21));
        arrivalSpinBox = new QDoubleSpinBox(BehaviorSettings);
        arrivalSpinBox->setObjectName(QString::fromUtf8("arrivalSpinBox"));
        arrivalSpinBox->setGeometry(QRect(111, 20, 71, 22));
        arrivalSpinBox->setMaximum(10000);
        arrivalSpinBox->setSingleStep(0.01);
        cohesSpinBox = new QDoubleSpinBox(BehaviorSettings);
        cohesSpinBox->setObjectName(QString::fromUtf8("cohesSpinBox"));
        cohesSpinBox->setGeometry(QRect(110, 140, 71, 22));
        cohesSpinBox->setMaximum(10000);
        cohesSpinBox->setSingleStep(0.01);

        verticalLayout_2->addWidget(BehaviorSettings);

        Behaviors = new QGroupBox(scrollAreaWidgetContents);
        Behaviors->setObjectName(QString::fromUtf8("Behaviors"));
        Behaviors->setMinimumSize(QSize(401, 180));
        Behaviors->setMaximumSize(QSize(401, 180));
        Behaviors->setAutoFillBackground(false);
        Behaviors->setFlat(false);
        Behaviors->setCheckable(false);
        seekRadioButton = new QRadioButton(Behaviors);
        seekRadioButton->setObjectName(QString::fromUtf8("seekRadioButton"));
        seekRadioButton->setGeometry(QRect(10, 40, 82, 17));
        arrivalRadioButton = new QRadioButton(Behaviors);
        arrivalRadioButton->setObjectName(QString::fromUtf8("arrivalRadioButton"));
        arrivalRadioButton->setGeometry(QRect(10, 70, 82, 17));
        arrivalRadioButton->setChecked(true);
        wanderRadioButton = new QRadioButton(Behaviors);
        wanderRadioButton->setObjectName(QString::fromUtf8("wanderRadioButton"));
        wanderRadioButton->setGeometry(QRect(290, 40, 82, 17));
        fleeRadioButton = new QRadioButton(Behaviors);
        fleeRadioButton->setObjectName(QString::fromUtf8("fleeRadioButton"));
        fleeRadioButton->setGeometry(QRect(150, 40, 82, 17));
        departureRadioButton = new QRadioButton(Behaviors);
        departureRadioButton->setObjectName(QString::fromUtf8("departureRadioButton"));
        departureRadioButton->setGeometry(QRect(150, 70, 82, 17));
        avoidRadioButton = new QRadioButton(Behaviors);
        avoidRadioButton->setObjectName(QString::fromUtf8("avoidRadioButton"));
        avoidRadioButton->setGeometry(QRect(290, 70, 82, 17));
        alignmentRadioButton = new QRadioButton(Behaviors);
        alignmentRadioButton->setObjectName(QString::fromUtf8("alignmentRadioButton"));
        alignmentRadioButton->setGeometry(QRect(290, 120, 82, 17));
        separationRadioButton = new QRadioButton(Behaviors);
        separationRadioButton->setObjectName(QString::fromUtf8("separationRadioButton"));
        separationRadioButton->setGeometry(QRect(10, 120, 82, 17));
        flockingRadioButton = new QRadioButton(Behaviors);
        flockingRadioButton->setObjectName(QString::fromUtf8("flockingRadioButton"));
        flockingRadioButton->setGeometry(QRect(150, 120, 82, 17));
        readerRadioButton = new QRadioButton(Behaviors);
        readerRadioButton->setObjectName(QString::fromUtf8("readerRadioButton"));
        readerRadioButton->setGeometry(QRect(10, 150, 82, 17));
        cohesionRadioButton = new QRadioButton(Behaviors);
        cohesionRadioButton->setObjectName(QString::fromUtf8("cohesionRadioButton"));
        cohesionRadioButton->setGeometry(QRect(150, 150, 82, 17));
        label_8 = new QLabel(Behaviors);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(130, 20, 111, 20));
        label_8->setAlignment(Qt::AlignCenter);
        label_10 = new QLabel(Behaviors);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(140, 100, 91, 20));
        label_10->setAlignment(Qt::AlignCenter);
        line_2 = new QFrame(Behaviors);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(240, 20, 151, 21));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(Behaviors);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(10, 20, 121, 21));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(Behaviors);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(240, 100, 151, 21));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        line_5 = new QFrame(Behaviors);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setGeometry(QRect(10, 100, 121, 21));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(Behaviors);

        groupBox = new QGroupBox(scrollAreaWidgetContents);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(401, 40));
        groupBox->setMaximumSize(QSize(401, 40));
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        applyButton = new QPushButton(groupBox);
        applyButton->setObjectName(QString::fromUtf8("applyButton"));
        applyButton->setGeometry(QRect(10, 10, 75, 23));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(310, 10, 75, 23));

        verticalLayout_2->addWidget(groupBox);


        verticalLayout_3->addLayout(verticalLayout_2);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);


        retranslateUi(ControlPanelDialog);
        QObject::connect(pushButton_2, SIGNAL(clicked()), ControlPanelDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ControlPanelDialog);
    } // setupUi

    void retranslateUi(QDialog *ControlPanelDialog)
    {
        ControlPanelDialog->setWindowTitle(QApplication::translate("ControlPanelDialog", "Behavior Model Control Panel", 0, QApplication::UnicodeUTF8));
        GerneralControl->setTitle(QApplication::translate("ControlPanelDialog", "Gerneral Control", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ControlPanelDialog", "Agent Number", 0, QApplication::UnicodeUTF8));
        debugMode->setText(QApplication::translate("ControlPanelDialog", "Debug View", 0, QApplication::UnicodeUTF8));
        AgentProperties->setTitle(QApplication::translate("ControlPanelDialog", "Agent Properties", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ControlPanelDialog", "Max Velocity", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ControlPanelDialog", "Max Force", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ControlPanelDialog", "Max Torque", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("ControlPanelDialog", "Mass", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("ControlPanelDialog", "Max W", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("ControlPanelDialog", "Inertia", 0, QApplication::UnicodeUTF8));
        ControlSettings->setTitle(QApplication::translate("ControlPanelDialog", "Control Settings", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("ControlPanelDialog", "Velocity Kv", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("ControlPanelDialog", "Heading Kv", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("ControlPanelDialog", "Kp", 0, QApplication::UnicodeUTF8));
        BehaviorSettings->setTitle(QApplication::translate("ControlPanelDialog", "Behavior Settings", 0, QApplication::UnicodeUTF8));
        label_26->setText(QApplication::translate("ControlPanelDialog", "Arrival", 0, QApplication::UnicodeUTF8));
        label_27->setText(QApplication::translate("ControlPanelDialog", "Noise", 0, QApplication::UnicodeUTF8));
        label_28->setText(QApplication::translate("ControlPanelDialog", "KAvoid", 0, QApplication::UnicodeUTF8));
        label_29->setText(QApplication::translate("ControlPanelDialog", "Departure", 0, QApplication::UnicodeUTF8));
        label_30->setText(QApplication::translate("ControlPanelDialog", "TAvoid", 0, QApplication::UnicodeUTF8));
        label_31->setText(QApplication::translate("ControlPanelDialog", "Wander", 0, QApplication::UnicodeUTF8));
        label_32->setText(QApplication::translate("ControlPanelDialog", "RNeighbor", 0, QApplication::UnicodeUTF8));
        label_33->setText(QApplication::translate("ControlPanelDialog", "Align", 0, QApplication::UnicodeUTF8));
        label_34->setText(QApplication::translate("ControlPanelDialog", "Cohesion", 0, QApplication::UnicodeUTF8));
        label_35->setText(QApplication::translate("ControlPanelDialog", "Separate", 0, QApplication::UnicodeUTF8));
        Behaviors->setTitle(QApplication::translate("ControlPanelDialog", "Behaviors", 0, QApplication::UnicodeUTF8));
        seekRadioButton->setText(QApplication::translate("ControlPanelDialog", "Seek", 0, QApplication::UnicodeUTF8));
        arrivalRadioButton->setText(QApplication::translate("ControlPanelDialog", "Arrival", 0, QApplication::UnicodeUTF8));
        wanderRadioButton->setText(QApplication::translate("ControlPanelDialog", "Wander", 0, QApplication::UnicodeUTF8));
        fleeRadioButton->setText(QApplication::translate("ControlPanelDialog", "Flee", 0, QApplication::UnicodeUTF8));
        departureRadioButton->setText(QApplication::translate("ControlPanelDialog", "Departure", 0, QApplication::UnicodeUTF8));
        avoidRadioButton->setText(QApplication::translate("ControlPanelDialog", "Avoid", 0, QApplication::UnicodeUTF8));
        alignmentRadioButton->setText(QApplication::translate("ControlPanelDialog", "Alignment", 0, QApplication::UnicodeUTF8));
        separationRadioButton->setText(QApplication::translate("ControlPanelDialog", "Separation", 0, QApplication::UnicodeUTF8));
        flockingRadioButton->setText(QApplication::translate("ControlPanelDialog", "Flocking", 0, QApplication::UnicodeUTF8));
        readerRadioButton->setText(QApplication::translate("ControlPanelDialog", "Leader", 0, QApplication::UnicodeUTF8));
        cohesionRadioButton->setText(QApplication::translate("ControlPanelDialog", "Cohesion", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("ControlPanelDialog", "Individual Behaviors", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("ControlPanelDialog", "Group Behaviors", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        applyButton->setText(QApplication::translate("ControlPanelDialog", "Apply", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("ControlPanelDialog", "Hide", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ControlPanelDialog: public Ui_ControlPanelDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLPANELDIALOG_H
