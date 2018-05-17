//////////////////////////////////////////////////////////////////////////
// mainwindow.cpp -- Source file for the main window.
//
// Tiantian Liu
// 11/11/2011
// University of Pennsylvania

#include "mainwindow.h"
#include "ui_mainwindow.h"

// debug
#include <QDebug>
// /debug

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    tabwidget = new QTabWidget(this);
    tabwidget->setTabShape(QTabWidget::Rounded);
    setCentralWidget(tabwidget);

    glwidget = new GLWidget(tabwidget);
    graphwidget = new GraphWidget(tabwidget);
    particleWidget = new ParticleGLWidget(tabwidget);
    behaviorWidget = new BehaviorGlWidget(tabwidget);

    tabwidget->addTab(graphwidget, "Curve Editor");
    tabwidget->addTab(glwidget, "BVH Player");
    tabwidget->addTab(particleWidget, "Particle System");
    tabwidget->addTab(behaviorWidget, "Behavior Model");
    tabwidget->setCurrentWidget(behaviorWidget);
    //tabwidget->set
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAbout_triggered()
{
    AboutDialog aboutDialog;
    aboutDialog.setModal(true);
    aboutDialog.exec();
}

void MainWindow::on_actionTool_Bar_triggered(bool checked)
{
    if (checked)
    {
        this->graphwidget->toolBar->show();
        this->glwidget->toolBar->show();
        this->behaviorWidget->toolBar->show();
    }
    else
    {
        this->graphwidget->toolBar->hide();
        this->glwidget->toolBar->hide();
        this->behaviorWidget->toolBar->hide();
    }
}

void MainWindow::on_actionStatus_bar_triggered(bool checked)
{
    if (checked)
        ui->statusBar->show();
    else
        ui->statusBar->hide();
}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}
