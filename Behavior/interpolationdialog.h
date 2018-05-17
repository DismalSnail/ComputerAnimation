//////////////////////////////////////////////////////////////////////////
// interpolationdialog.h -- Header file for QT dialog that display the blend window.
//
// Tiantian Liu
// 11/11/2011
// University of Pennsylvania

#ifndef INTERPOLATIONDIALOG_H
#define INTERPOLATIONDIALOG_H

#include <QDialog>
#include "glwidget.h"

namespace Ui {
    class InterpolationDialog;
}

class GLWidget;

class InterpolationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InterpolationDialog(GLWidget *glw, QWidget *parent = 0);
    ~InterpolationDialog();
	static int defaultFrameLength;

private slots:
    void on_buttonBox_accepted();
    void on_comboBox_type_currentIndexChanged(int index);

private:
    Ui::InterpolationDialog *ui;
    GLWidget * glWindow;
    unsigned int frameCount0;
    unsigned int frameCount1;
    unsigned int type;
};

#endif // INTERPOLATIONDIALOG_H
