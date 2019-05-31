#include "brandwindow.h"
#include "ui_brandwindow.h"


BrandWindow::BrandWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BrandWindow)
{
    ui->setupUi(this);
    setTableModel();
    setTableView();
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
    table->select();
}

void BrandWindow::setTableModel()
{
    table = new QSqlTableModel;
    table->setTable("Brand");
    table->setHeaderData(1, Qt::Horizontal, QVariant("Brand"));
    table->select();
}

void BrandWindow::setTableView()
{
    ui->tableView->setModel(table);
    ui->tableView->setColumnHidden(0, true);
}
