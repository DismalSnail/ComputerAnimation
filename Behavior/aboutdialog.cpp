//////////////////////////////////////////////////////////////////////////
// aboutdialog.cpp -- source file for the about dialog
//
// Tiantian Liu
// 11/11/2009
// University of Pennsylvania

#include "aboutdialog.h"
#include "ui_aboutdialog.h"

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);
}

AboutDialog::~AboutDialog()
{
    delete ui;
}
