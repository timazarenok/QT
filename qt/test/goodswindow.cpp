#include "goodswindow.h"
#include "ui_goodswindow.h"

GoodsWindow::GoodsWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GoodsWindow)
{
    ui->setupUi(this);
    m = new SqlComboBoxModel;
    c = new SqlComboBoxModelCountry;
    ui->comboBoxBrand->setModel(m);
    ui->comboBox_origin->setModel(c);
    setTableModel();
    setTableView();
    connect(ui->pushButton, &QPushButton::clicked, this, &GoodsWindow::slotAddGoods);

}

GoodsWindow::~GoodsWindow()
{
    delete ui;
}

void GoodsWindow::slotAddGoods()
{
    if(Database::insertIntoTableGoods(QList<QVariant>{ui->lineEdit->text(),
                                                      ui->comboBoxBrand->currentData(),
                                                      ui->comboBox_origin->currentData(),
                                                      ui->lineEditPrice->text()}))
    {
        QMessageBox::information(this, "info window", "u are succesfully added");
    }
    else {
        QMessageBox::information(this, "error", "error");
    }
    table->select();
}

void GoodsWindow::setTableModel()
{
    table = new QSqlTableModel;
    table->setTable("Goods");
    table->setHeaderData(1, Qt::Horizontal, QVariant("Goods"));
    table->select();
}
void GoodsWindow::setTableView()
{
    ui->tableView->setModel(table);
    ui->tableView->setColumnHidden(0, true);
}
