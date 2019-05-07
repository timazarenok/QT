/********************************************************************************
** Form generated from reading UI file 'sizewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIZEWINDOW_H
#define UI_SIZEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SizeWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SizeWindow)
    {
        if (SizeWindow->objectName().isEmpty())
            SizeWindow->setObjectName(QString::fromUtf8("SizeWindow"));
        SizeWindow->resize(678, 259);
        centralwidget = new QWidget(SizeWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(260, 70, 131, 31));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(270, 110, 93, 28));
        SizeWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SizeWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 678, 26));
        SizeWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(SizeWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        SizeWindow->setStatusBar(statusbar);

        retranslateUi(SizeWindow);

        QMetaObject::connectSlotsByName(SizeWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SizeWindow)
    {
        SizeWindow->setWindowTitle(QApplication::translate("SizeWindow", "MainWindow", nullptr));
        pushButton->setText(QApplication::translate("SizeWindow", "add Size", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SizeWindow: public Ui_SizeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIZEWINDOW_H
