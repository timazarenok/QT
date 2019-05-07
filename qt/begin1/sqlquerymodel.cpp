#include "sqlquerymodel.h"
#include "ui_sqlquerymodel.h"

sqlQueryModel::sqlQueryModel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::sqlQueryModel)
{
    ui->setupUi(this);
    this->setupModel("Human", QStringList() << trUtf8("id")
                     << trUtf8("Name")
                     << trUtf8("Sex")
                     );
    this->createUI();
}

sqlQueryModel::~sqlQueryModel()
{
    delete ui;
}

void sqlQueryModel::setupModel(const QString &tableName, const QStringList &headers)
{
    model = new QSqlTableModel(this);
    model->setTable(tableName);
    for(int i =0; i < model->columnCount(); ++i)
    {
        model->setHeaderData(i, Qt::Horizontal, headers[i]);
    }
    model->setSort(0, Qt::AscendingOrder);
}

void sqlQueryModel::createUI()
{
    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(0, true);
    model->select();
}
