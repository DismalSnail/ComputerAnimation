/********************************************************************************
** Form generated from reading UI file 'interpolationdialog.ui'
**
** Created: Fri Nov 11 00:22:36 2011
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERPOLATIONDIALOG_H
#define UI_INTERPOLATIONDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_InterpolationDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QSpinBox *spinBox_FrameNum;
    QSpinBox *spinBox_Anim1;
    QSpinBox *spinBox_Anim2;
    QComboBox *comboBox_type;

    void setupUi(QDialog *InterpolationDialog)
    {
        if (InterpolationDialog->objectName().isEmpty())
            InterpolationDialog->setObjectName(QString::fromUtf8("InterpolationDialog"));
        InterpolationDialog->resize(228, 169);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(228);
        sizePolicy.setVerticalStretch(169);
        sizePolicy.setHeightForWidth(InterpolationDialog->sizePolicy().hasHeightForWidth());
        InterpolationDialog->setSizePolicy(sizePolicy);
        InterpolationDialog->setMinimumSize(QSize(228, 169));
        InterpolationDialog->setMaximumSize(QSize(228, 169));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/Blend.png"), QSize(), QIcon::Normal, QIcon::Off);
        InterpolationDialog->setWindowIcon(icon);
        buttonBox = new QDialogButtonBox(InterpolationDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(0, 130, 221, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(InterpolationDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 121, 21));
        label_2 = new QLabel(InterpolationDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 40, 131, 21));
        label_3 = new QLabel(InterpolationDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 70, 141, 20));
        label_4 = new QLabel(InterpolationDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 100, 21, 21));
        label_5 = new QLabel(InterpolationDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(80, 100, 71, 21));
        spinBox_FrameNum = new QSpinBox(InterpolationDialog);
        spinBox_FrameNum->setObjectName(QString::fromUtf8("spinBox_FrameNum"));
        spinBox_FrameNum->setGeometry(QRect(30, 100, 42, 22));
        spinBox_FrameNum->setMaximum(999);
        spinBox_Anim1 = new QSpinBox(InterpolationDialog);
        spinBox_Anim1->setObjectName(QString::fromUtf8("spinBox_Anim1"));
        spinBox_Anim1->setGeometry(QRect(150, 40, 71, 22));
        spinBox_Anim2 = new QSpinBox(InterpolationDialog);
        spinBox_Anim2->setObjectName(QString::fromUtf8("spinBox_Anim2"));
        spinBox_Anim2->setGeometry(QRect(150, 70, 71, 22));
        comboBox_type = new QComboBox(InterpolationDialog);
        comboBox_type->setObjectName(QString::fromUtf8("comboBox_type"));
        comboBox_type->setGeometry(QRect(150, 100, 69, 22));

        retranslateUi(InterpolationDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), InterpolationDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), InterpolationDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(InterpolationDialog);
    } // setupUi

    void retranslateUi(QDialog *InterpolationDialog)
    {
        InterpolationDialog->setWindowTitle(QApplication::translate("InterpolationDialog", "Blend", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("InterpolationDialog", "Interpolation", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("InterpolationDialog", "From Animation 1 Frame: ", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("InterpolationDialog", "To     Animation 2 Frame: ", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("InterpolationDialog", "For", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("InterpolationDialog", "frames using", 0, QApplication::UnicodeUTF8));
        comboBox_type->clear();
        comboBox_type->insertItems(0, QStringList()
         << QApplication::translate("InterpolationDialog", "Cubic", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("InterpolationDialog", "SLERP", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("InterpolationDialog", "SQUAD", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class InterpolationDialog: public Ui_InterpolationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERPOLATIONDIALOG_H
