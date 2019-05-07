#include "sizewindow.h"
#include "ui_sizewindow.h"

SizeWindow::SizeWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SizeWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &SizeWindow::slotAddSize);
}

SizeWindow::~SizeWindow()
{
    delete ui;
}

void SizeWindow::slotAddSize()
{
    if(Database::insertIntoTableSizes(QList<QVariant>{ui->lineEdit->text()}))
    {
        QMessageBox::information(this, "u are succesfully added", "info window");
    }
    else {
        QMessageBox::information(this, "error", "error");
    }
}
