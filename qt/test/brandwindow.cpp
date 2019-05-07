#include "brandwindow.h"
#include "ui_brandwindow.h"


BrandWindow::BrandWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BrandWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &BrandWindow::slotAddBrand);
}

BrandWindow::~BrandWindow()
{
    delete ui;
}

void BrandWindow::slotAddBrand()
{
    if(Database::insertIntoTableBrand(QList<QVariant>{ui->lineEdit->text()}))
    {
           QMessageBox::information(this, "info window", "u are succesfully added");
    }
    else {
        QMessageBox::information(this, "error", "error");
    }
}
