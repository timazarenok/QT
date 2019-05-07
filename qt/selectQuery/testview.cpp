#include "testview.h"
#include "ui_testview.h"

TESTVIEW::TESTVIEW(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TESTVIEW)
{
    ui->setupUi(this);
}

TESTVIEW::~TESTVIEW()
{
    delete ui;
}
