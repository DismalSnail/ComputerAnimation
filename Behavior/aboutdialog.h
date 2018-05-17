//////////////////////////////////////////////////////////////////////////
// aboutdialog.h -- Header file for the about dialog
//
// Tiantian Liu
// 11/11/2011
// University of Pennsylvania


#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QDialog>

namespace Ui {
    class AboutDialog;
}

class AboutDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AboutDialog(QWidget *parent = 0);
    ~AboutDialog();

private:
    Ui::AboutDialog *ui;
};

#endif // ABOUTDIALOG_H
