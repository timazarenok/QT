#include "testrenationaltable.h"
#include "ui_testrenationaltable.h"

TestRenationalTable::TestRenationalTable(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TestRenationalTable)
{
    ui->setupUi(this);
}

TestRenationalTable::~TestRenationalTable()
{
    delete ui;
}
