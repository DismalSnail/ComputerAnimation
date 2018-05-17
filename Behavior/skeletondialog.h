//////////////////////////////////////////////////////////////////////////
// skeletondialog.h -- Header file for the tree view of skeleton
//
// Tiantian Liu
// 11/11/2011
// University of Pennsylvania

#ifndef SKELETONDIALOG_H
#define SKELETONDIALOG_H

#include <QDialog>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QItemSelectionModel>
#include "glwidget.h"

class GLWidget;
class Joint;
class Skeleton;
class Player;

namespace Ui {
class SkeletonDialog;
}

class SkeletonDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SkeletonDialog(GLWidget *glw, QWidget *parent = 0);
    ~SkeletonDialog();

protected:
    QStandardItem * BuildTree(Joint * pJoint, QStandardItem * parent);
    void SetJointData(Joint *);

private slots:
    void on_selectionModel_selectionChanged ( const QItemSelection & selected, const QItemSelection & deselected);

    void on_doubleSpinBoxRx_editingFinished();
    void on_doubleSpinBoxRy_editingFinished();
    void on_doubleSpinBoxRz_editingFinished();
    void on_doubleSpinBoxTx_editingFinished();
    void on_doubleSpinBoxTy_editingFinished();
    void on_doubleSpinBoxTz_editingFinished();

    void on_buttonOK_clicked();

    void on_buttonCancel_clicked();


    void on_buttonApply_clicked();

private:
    Ui::SkeletonDialog *ui;
    GLWidget *glw;
    Skeleton *m_skeleton;
    QStandardItemModel *model;
    Joint *selection;
};

#endif // SKELETONDIALOG_H
