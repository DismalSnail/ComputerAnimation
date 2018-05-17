/********************************************************************************
** Form generated from reading UI file 'aboutdialog.ui'
**
** Created: Tue Sep 27 14:46:57 2011
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTDIALOG_H
#define UI_ABOUTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AboutDialog
{
public:
    QPushButton *pushButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QDialog *AboutDialog)
    {
        if (AboutDialog->objectName().isEmpty())
            AboutDialog->setObjectName(QString::fromUtf8("AboutDialog"));
        AboutDialog->setEnabled(true);
        AboutDialog->resize(379, 106);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AboutDialog->sizePolicy().hasHeightForWidth());
        AboutDialog->setSizePolicy(sizePolicy);
        AboutDialog->setMinimumSize(QSize(379, 106));
        AboutDialog->setMaximumSize(QSize(379, 106));
        AboutDialog->setMouseTracking(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/Icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        AboutDialog->setWindowIcon(icon);
        AboutDialog->setWindowOpacity(1);
        AboutDialog->setAutoFillBackground(false);
        pushButton = new QPushButton(AboutDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(290, 10, 81, 31));
        layoutWidget = new QWidget(AboutDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(100, 10, 181, 81));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(AboutDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 10, 71, 81));
        label_4->setTextFormat(Qt::RichText);
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/images/images/Icon.png")));
        label_4->setScaledContents(true);
        label_4->setWordWrap(false);

        retranslateUi(AboutDialog);
        QObject::connect(pushButton, SIGNAL(clicked()), AboutDialog, SLOT(accept()));

        QMetaObject::connectSlotsByName(AboutDialog);
    } // setupUi

    void retranslateUi(QDialog *AboutDialog)
    {
        AboutDialog->setWindowTitle(QApplication::translate("AboutDialog", "About", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        AboutDialog->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton->setText(QApplication::translate("AboutDialog", "OK", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AboutDialog", "CIS 462/562 Assignments Version 2.0", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("AboutDialog", "Copyright (C) 2011", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("AboutDialog", "University of Pennsylvania", 0, QApplication::UnicodeUTF8));
        label_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AboutDialog: public Ui_AboutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTDIALOG_H
