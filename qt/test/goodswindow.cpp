#include "goodswindow.h"
#include "ui_goodswindow.h"

GoodsWindow::GoodsWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GoodsWindow)
{
    ui->setupUi(this);
    m = new SqlComboBoxModel;
    ui->comboBox->setModel(m);
}

GoodsWindow::~GoodsWindow()
{
    delete ui;
}
