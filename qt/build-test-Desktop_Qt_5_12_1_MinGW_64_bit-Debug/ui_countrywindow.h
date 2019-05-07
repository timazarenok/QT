/********************************************************************************
** Form generated from reading UI file 'countrywindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COUNTRYWINDOW_H
#define UI_COUNTRYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CountryWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CountryWindow)
    {
        if (CountryWindow->objectName().isEmpty())
            CountryWindow->setObjectName(QString::fromUtf8("CountryWindow"));
        CountryWindow->resize(443, 174);
        centralwidget = new QWidget(CountryWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(140, 30, 131, 31));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(160, 80, 93, 28));
        CountryWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CountryWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 443, 26));
        CountryWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(CountryWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        CountryWindow->setStatusBar(statusbar);

        retranslateUi(CountryWindow);

        QMetaObject::connectSlotsByName(CountryWindow);
    } // setupUi

    void retranslateUi(QMainWindow *CountryWindow)
    {
        CountryWindow->setWindowTitle(QApplication::translate("CountryWindow", "MainWindow", nullptr));
        pushButton->setText(QApplication::translate("CountryWindow", "add country", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CountryWindow: public Ui_CountryWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COUNTRYWINDOW_H
