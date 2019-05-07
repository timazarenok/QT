/********************************************************************************
** Form generated from reading UI file 'brandwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BRANDWINDOW_H
#define UI_BRANDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BrandWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *BrandWindow)
    {
        if (BrandWindow->objectName().isEmpty())
            BrandWindow->setObjectName(QString::fromUtf8("BrandWindow"));
        BrandWindow->resize(652, 270);
        centralwidget = new QWidget(BrandWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(270, 90, 121, 31));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(280, 130, 93, 28));
        BrandWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(BrandWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 652, 26));
        BrandWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(BrandWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        BrandWindow->setStatusBar(statusbar);

        retranslateUi(BrandWindow);

        QMetaObject::connectSlotsByName(BrandWindow);
    } // setupUi

    void retranslateUi(QMainWindow *BrandWindow)
    {
        BrandWindow->setWindowTitle(QApplication::translate("BrandWindow", "MainWindow", nullptr));
        pushButton->setText(QApplication::translate("BrandWindow", "add Brand", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BrandWindow: public Ui_BrandWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BRANDWINDOW_H
