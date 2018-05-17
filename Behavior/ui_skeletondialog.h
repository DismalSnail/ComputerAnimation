/********************************************************************************
** Form generated from reading UI file 'skeletondialog.ui'
**
** Created: Fri Nov 11 00:22:36 2011
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SKELETONDIALOG_H
#define UI_SKELETONDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTreeView>

QT_BEGIN_NAMESPACE

class Ui_SkeletonDialog
{
public:
    QTreeView *treeView;
    QLabel *label;
    QLabel *labelJointName;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBoxRx;
    QDoubleSpinBox *doubleSpinBoxRy;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBoxTx;
    QDoubleSpinBox *doubleSpinBoxRz;
    QLabel *label_5;
    QLabel *label_6;
    QDoubleSpinBox *doubleSpinBoxTy;
    QLabel *label_8;
    QLabel *label_9;
    QDoubleSpinBox *doubleSpinBoxTz;
    QPushButton *buttonOK;
    QPushButton *buttonCancel;
    QPushButton *buttonApply;

    void setupUi(QDialog *SkeletonDialog)
    {
        if (SkeletonDialog->objectName().isEmpty())
            SkeletonDialog->setObjectName(QString::fromUtf8("SkeletonDialog"));
        SkeletonDialog->resize(369, 490);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SkeletonDialog->sizePolicy().hasHeightForWidth());
        SkeletonDialog->setSizePolicy(sizePolicy);
        SkeletonDialog->setMinimumSize(QSize(369, 490));
        SkeletonDialog->setMaximumSize(QSize(369, 490));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/skeleton.png"), QSize(), QIcon::Normal, QIcon::Off);
        SkeletonDialog->setWindowIcon(icon);
        treeView = new QTreeView(SkeletonDialog);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        treeView->setGeometry(QRect(5, 11, 271, 471));
        treeView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        treeView->setDragEnabled(true);
        treeView->header()->setVisible(false);
        label = new QLabel(SkeletonDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(290, 10, 71, 21));
        labelJointName = new QLabel(SkeletonDialog);
        labelJointName->setObjectName(QString::fromUtf8("labelJointName"));
        labelJointName->setGeometry(QRect(290, 30, 71, 21));
        label_3 = new QLabel(SkeletonDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(290, 60, 71, 21));
        doubleSpinBoxRx = new QDoubleSpinBox(SkeletonDialog);
        doubleSpinBoxRx->setObjectName(QString::fromUtf8("doubleSpinBoxRx"));
        doubleSpinBoxRx->setGeometry(QRect(290, 80, 62, 22));
        doubleSpinBoxRx->setMinimum(-179.99);
        doubleSpinBoxRx->setMaximum(180);
        doubleSpinBoxRx->setSingleStep(0.01);
        doubleSpinBoxRy = new QDoubleSpinBox(SkeletonDialog);
        doubleSpinBoxRy->setObjectName(QString::fromUtf8("doubleSpinBoxRy"));
        doubleSpinBoxRy->setGeometry(QRect(290, 130, 62, 22));
        doubleSpinBoxRy->setMinimum(-179.99);
        doubleSpinBoxRy->setMaximum(180);
        doubleSpinBoxRy->setSingleStep(0.01);
        label_4 = new QLabel(SkeletonDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(290, 110, 71, 21));
        doubleSpinBoxTx = new QDoubleSpinBox(SkeletonDialog);
        doubleSpinBoxTx->setObjectName(QString::fromUtf8("doubleSpinBoxTx"));
        doubleSpinBoxTx->setGeometry(QRect(290, 230, 62, 22));
        doubleSpinBoxTx->setMinimum(-5000);
        doubleSpinBoxTx->setMaximum(5000);
        doubleSpinBoxTx->setSingleStep(0.01);
        doubleSpinBoxRz = new QDoubleSpinBox(SkeletonDialog);
        doubleSpinBoxRz->setObjectName(QString::fromUtf8("doubleSpinBoxRz"));
        doubleSpinBoxRz->setGeometry(QRect(290, 180, 62, 22));
        doubleSpinBoxRz->setMinimum(-179.99);
        doubleSpinBoxRz->setMaximum(180);
        doubleSpinBoxRz->setSingleStep(0.01);
        label_5 = new QLabel(SkeletonDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(290, 210, 71, 21));
        label_6 = new QLabel(SkeletonDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(290, 160, 71, 21));
        doubleSpinBoxTy = new QDoubleSpinBox(SkeletonDialog);
        doubleSpinBoxTy->setObjectName(QString::fromUtf8("doubleSpinBoxTy"));
        doubleSpinBoxTy->setGeometry(QRect(290, 280, 62, 22));
        doubleSpinBoxTy->setMinimum(-5000);
        doubleSpinBoxTy->setMaximum(5000);
        doubleSpinBoxTy->setSingleStep(0.01);
        label_8 = new QLabel(SkeletonDialog);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(290, 260, 71, 21));
        label_9 = new QLabel(SkeletonDialog);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(290, 310, 71, 21));
        doubleSpinBoxTz = new QDoubleSpinBox(SkeletonDialog);
        doubleSpinBoxTz->setObjectName(QString::fromUtf8("doubleSpinBoxTz"));
        doubleSpinBoxTz->setGeometry(QRect(290, 330, 62, 22));
        doubleSpinBoxTz->setMinimum(-5000);
        doubleSpinBoxTz->setMaximum(5000);
        doubleSpinBoxTz->setSingleStep(0.01);
        buttonOK = new QPushButton(SkeletonDialog);
        buttonOK->setObjectName(QString::fromUtf8("buttonOK"));
        buttonOK->setGeometry(QRect(280, 390, 75, 23));
        buttonCancel = new QPushButton(SkeletonDialog);
        buttonCancel->setObjectName(QString::fromUtf8("buttonCancel"));
        buttonCancel->setGeometry(QRect(280, 450, 75, 23));
        buttonApply = new QPushButton(SkeletonDialog);
        buttonApply->setObjectName(QString::fromUtf8("buttonApply"));
        buttonApply->setGeometry(QRect(280, 420, 75, 23));

        retranslateUi(SkeletonDialog);
        QObject::connect(buttonOK, SIGNAL(clicked()), SkeletonDialog, SLOT(accept()));
        QObject::connect(buttonCancel, SIGNAL(clicked()), SkeletonDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SkeletonDialog);
    } // setupUi

    void retranslateUi(QDialog *SkeletonDialog)
    {
        SkeletonDialog->setWindowTitle(QApplication::translate("SkeletonDialog", "Skeleton", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SkeletonDialog", "Joint Name:", 0, QApplication::UnicodeUTF8));
        labelJointName->setText(QApplication::translate("SkeletonDialog", "Hip", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("SkeletonDialog", "Rotation X", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("SkeletonDialog", "Rotation Y", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("SkeletonDialog", "Translation X", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("SkeletonDialog", "Rotation Z", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("SkeletonDialog", "Translation Y", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("SkeletonDialog", "Translation Z", 0, QApplication::UnicodeUTF8));
        buttonOK->setText(QApplication::translate("SkeletonDialog", "OK", 0, QApplication::UnicodeUTF8));
        buttonCancel->setText(QApplication::translate("SkeletonDialog", "Cancel", 0, QApplication::UnicodeUTF8));
        buttonApply->setText(QApplication::translate("SkeletonDialog", "Apply", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SkeletonDialog: public Ui_SkeletonDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SKELETONDIALOG_H
