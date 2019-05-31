#include "countrywindow.h"
#include "ui_countrywindow.h"

CountryWindow::CountryWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CountryWindow)
{
    ui->setupUi(this);
    setTableModel();
    setTableView();
    connect(ui->pushButton, &QPushButton::clicked, this, &CountryWindow::slotAddCountry);
}

void CountryWindow::setTableModel()
{
    table = new QSqlTableModel;
    table->setTable("Countries");
    table->setHeaderData(1, Qt::Horizontal, QVariant("Countries"));
    table->select();
}

void CountryWindow::setTableView()
{
    ui->tableView->setModel(table);
    ui->tableView->setColumnHidden(0, true);
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
    table->select();
}
