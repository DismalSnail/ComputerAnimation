//////////////////////////////////////////////////////////////////////////
// skeletondialog.cpp -- Source file for the tree view of skeleton
//
// Tiantian Liu
// 11/11/2011
// University of Pennsylvania


#include "skeletondialog.h"
#include "ui_skeletondialog.h"
#include <QModelIndex>
#include <QPushButton>
#include <QStack>
#include <QDebug>

SkeletonDialog::SkeletonDialog(GLWidget *glw, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SkeletonDialog)
{
    ui->setupUi(this);
    this->glw = glw;
    m_skeleton = glw->m_player.GetSkeleton();
    Joint *root = m_skeleton->GetRootJoint();
    int s = m_skeleton->GetSelectedJoint();
    if (s < 0)
        selection = root;
    else
        selection = m_skeleton->GetJointByID(s);
    SetJointData(selection);
    model = new QStandardItemModel();
    QStandardItem *rootNode = model->invisibleRootItem();
    BuildTree(root, rootNode);
    this->ui->treeView->setModel(model);
    this->ui->treeView->expandAll();
    this->ui->treeView->setFocus();
    this->ui->treeView->selectionModel();
    this->ui->buttonOK->setAutoDefault(false);
    this->ui->buttonCancel->setAutoDefault(false);
    this->ui->buttonApply->setAutoDefault(false);

    QItemSelectionModel * selectionModel = this->ui->treeView->selectionModel();
    selectionModel->setParent(this);
    selectionModel->setObjectName(QString::fromUtf8("selectionModel"));
    connect(selectionModel, SIGNAL(selectionChanged (const QItemSelection &, const QItemSelection &)),
                 this, SLOT(on_selectionModel_selectionChanged(const QItemSelection &, const QItemSelection &)));
}

SkeletonDialog::~SkeletonDialog()
{
    delete ui;
}

QStandardItem * SkeletonDialog::BuildTree(Joint * pJoint, QStandardItem * parent)
{
    QStandardItem *self = new QStandardItem(pJoint->GetName().c_str());
    self->setData(pJoint->GetID());

    parent->appendRow(self);

    unsigned int totalChildren = pJoint->GetChildCount();
    for (unsigned int i = 0; i < totalChildren; i++)
    {
        BuildTree(pJoint->GetChildAt(i), self);
    }

    return self;
}

void SkeletonDialog::on_selectionModel_selectionChanged(const QItemSelection &, const QItemSelection &)
{
    //get the text of the selected item
    const QModelIndex index = this->ui->treeView->selectionModel()->currentIndex();
    QString selectedText = index.data(Qt::DisplayRole).toString();
    //find out the hierarchy level of the selected item
    int hierarchyLevel=1;
    QStack<int> num;
    num.clear();
    QModelIndex seekRoot = index;
    while(seekRoot.parent() != QModelIndex())
    {
        QModelIndex tmp = seekRoot.parent();
        int sibling = 0;
        for (sibling = 0;tmp.child(sibling, 0) != seekRoot; sibling++);
        hierarchyLevel++;
        seekRoot = tmp;
        num.push(sibling);
    }
    selection = m_skeleton->GetRootJoint();
    for (int i = 1; i < hierarchyLevel; i++)
    {
        int childNum = num.pop();
        selection = selection->GetChildAt(childNum);
    }
    SetJointData(selection);
}

void SkeletonDialog::SetJointData(Joint * pJoint)
{
    m_skeleton->SetSelectedJoint(pJoint->GetID());
    this->glw->glDraw();

    vec3 rotation;
    vec3 translation;
    pJoint->GetLocalRotation().ToEulerAnglesZXY(rotation);
    rotation *= Rad2Deg;
    translation = pJoint->GetLocalTranslation();

    this->ui->labelJointName->setText(QString(pJoint->GetName().c_str()));
    this->ui->doubleSpinBoxRx->setValue(rotation[VX]);
    this->ui->doubleSpinBoxRy->setValue(rotation[VY]);
    this->ui->doubleSpinBoxRz->setValue(rotation[VZ]);
    this->ui->doubleSpinBoxTx->setValue(translation[VX]);
    this->ui->doubleSpinBoxTy->setValue(translation[VY]);
    this->ui->doubleSpinBoxTz->setValue(translation[VZ]);

    if (pJoint->GetID() == 0)
    {
        this->ui->doubleSpinBoxTx->setEnabled(true);
        this->ui->doubleSpinBoxTy->setEnabled(true);
        this->ui->doubleSpinBoxTz->setEnabled(true);
    }
    else
    {
        this->ui->doubleSpinBoxTx->setEnabled(false);
        this->ui->doubleSpinBoxTy->setEnabled(false);
        this->ui->doubleSpinBoxTz->setEnabled(false);
    }
}
void SkeletonDialog::on_buttonOK_clicked()
{
    glw->m_player.SaveFrame();
}

void SkeletonDialog::on_buttonCancel_clicked()
{
    glw->m_player.SaveFrame();
}

void SkeletonDialog::on_buttonApply_clicked()
{

}

void SkeletonDialog::on_doubleSpinBoxRx_editingFinished()
{
    double m_Rx = this->ui->doubleSpinBoxRx->value();
    double m_Ry = this->ui->doubleSpinBoxRy->value();
    double m_Rz = this->ui->doubleSpinBoxRz->value();
    vec3 angles(m_Rx, m_Ry, m_Rz);
    angles *= Deg2Rad;
    mat3 rot;
    rot.FromEulerAnglesZXY(angles);
    selection->SetLocalRotation(rot);
    selection->UpdateTransformation(true);
    glw->glDraw();
}

void SkeletonDialog::on_doubleSpinBoxRy_editingFinished()
{
    double m_Rx = this->ui->doubleSpinBoxRx->value();
    double m_Ry = this->ui->doubleSpinBoxRy->value();
    double m_Rz = this->ui->doubleSpinBoxRz->value();
    vec3 angles(m_Rx, m_Ry, m_Rz);
    angles *= Deg2Rad;
    mat3 rot;
    rot.FromEulerAnglesZXY(angles);
    selection->SetLocalRotation(rot);
    selection->UpdateTransformation(true);
    glw->glDraw();
}

void SkeletonDialog::on_doubleSpinBoxRz_editingFinished()
{
    double m_Rx = this->ui->doubleSpinBoxRx->value();
    double m_Ry = this->ui->doubleSpinBoxRy->value();
    double m_Rz = this->ui->doubleSpinBoxRz->value();
    vec3 angles(m_Rx, m_Ry, m_Rz);
    angles *= Deg2Rad;
    mat3 rot;
    rot.FromEulerAnglesZXY(angles);
    selection->SetLocalRotation(rot);
    selection->UpdateTransformation(true);
    glw->glDraw();
}

void SkeletonDialog::on_doubleSpinBoxTx_editingFinished()
{
    double m_Tx = this->ui->doubleSpinBoxTx->value();
    double m_Ty = this->ui->doubleSpinBoxTy->value();
    double m_Tz = this->ui->doubleSpinBoxTz->value();
    vec3 trans(m_Tx, m_Ty, m_Tz);
    selection->SetLocalTranslation(trans);
    selection->UpdateTransformation(true);
    glw->glDraw();
}

void SkeletonDialog::on_doubleSpinBoxTy_editingFinished()
{
    double m_Tx = this->ui->doubleSpinBoxTx->value();
    double m_Ty = this->ui->doubleSpinBoxTy->value();
    double m_Tz = this->ui->doubleSpinBoxTz->value();
    vec3 trans(m_Tx, m_Ty, m_Tz);
    selection->SetLocalTranslation(trans);
    selection->UpdateTransformation(true);
    glw->glDraw();
}

void SkeletonDialog::on_doubleSpinBoxTz_editingFinished()
{
    double m_Tx = this->ui->doubleSpinBoxTx->value();
    double m_Ty = this->ui->doubleSpinBoxTy->value();
    double m_Tz = this->ui->doubleSpinBoxTz->value();
    vec3 trans(m_Tx, m_Ty, m_Tz);
    selection->SetLocalTranslation(trans);
    selection->UpdateTransformation(true);
    glw->glDraw();
}
