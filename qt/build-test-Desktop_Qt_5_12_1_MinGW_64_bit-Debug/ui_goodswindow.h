/********************************************************************************
** Form generated from reading UI file 'goodswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GOODSWINDOW_H
#define UI_GOODSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GoodsWindow
{
public:
    QWidget *centralwidget;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *GoodsWindow)
    {
        if (GoodsWindow->objectName().isEmpty())
            GoodsWindow->setObjectName(QString::fromUtf8("GoodsWindow"));
        GoodsWindow->resize(656, 330);
        centralwidget = new QWidget(GoodsWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(270, 100, 151, 31));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(290, 150, 93, 28));
        GoodsWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(GoodsWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 656, 26));
        GoodsWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(GoodsWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        GoodsWindow->setStatusBar(statusbar);

        retranslateUi(GoodsWindow);

        QMetaObject::connectSlotsByName(GoodsWindow);
    } // setupUi

    void retranslateUi(QMainWindow *GoodsWindow)
    {
        GoodsWindow->setWindowTitle(QApplication::translate("GoodsWindow", "MainWindow", nullptr));
        pushButton->setText(QApplication::translate("GoodsWindow", "addGoods", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GoodsWindow: public Ui_GoodsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GOODSWINDOW_H
