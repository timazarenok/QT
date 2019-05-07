#include "relationaltablemodel.h"
#include "ui_relationaltablemodel.h"

RelationalTableModel::RelationalTableModel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RelationalTableModel)
{
    ui->setupUi(this);
    this->setupHumanModel("Human", QStringList() << trUtf8("id")
                          << trUtf8("Name")
                          << trUtf8("Sex")
                          );
    this->createUI();
}

RelationalTableModel::~RelationalTableModel()
{
    delete ui;
}

void RelationalTableModel::setupHumanModel(const QString &tableName, const QStringList &headers)
{
    modelHuman = new QSqlRelationalTableModel(this);
    modelHuman->setTable(tableName);
    modelHuman->setRelation(2, QSqlRelation("Sex", "s_id", "s_name"));
    for(int i = 0; i < modelHuman->columnCount(); ++i)
    {
        modelHuman->setHeaderData(i, Qt::Horizontal, headers[i]);
    }
    modelHuman->setSort(0, Qt::AscendingOrder);
    modelHuman->select();
}

void RelationalTableModel::createUI()
{
    ui->tableView->setModel(modelHuman);
    modelHuman->select();
}
