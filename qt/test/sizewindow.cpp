#include "sizewindow.h"
#include "ui_sizewindow.h"

SizeWindow::SizeWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SizeWindow)
{
    ui->setupUi(this);
    setTableModel();
    setTableView();
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
        QMessageBox::information(this, "info window", "u are succesfully addedv");
    }
    else {
        QMessageBox::information(this, "error", "error");
    }
    table->select();
}


void SizeWindow::setTableModel()
{
    table = new QSqlTableModel;
    table->setTable("Sizes");
    table->setHeaderData(1, Qt::Horizontal, QVariant("Sizes"));
    table->select();
}
void SizeWindow::setTableView()
{
    ui->tableView->setModel(table);
    ui->tableView->setColumnHidden(0, true);
}

