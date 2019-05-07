#include "countrywindow.h"
#include "ui_countrywindow.h"

CountryWindow::CountryWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CountryWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &CountryWindow::slotAddCountry);
}

CountryWindow::~CountryWindow()
{
    delete ui;
}

void CountryWindow::slotAddCountry()
{
    if(Database::insertIntoTableCountries(QList<QVariant>{ui->lineEdit->text()}))
    {
        QMessageBox::information(this, "info window", "u are succesfully added");
    }
    else {
        QMessageBox::information(this, "error", "error");
    }
}
