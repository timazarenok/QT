#include "addquestionwindow.h"
#include "ui_addquestionwindow.h"


addQuestionWindow::addQuestionWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::addQuestionWindow)
{
    ui->setupUi(this);
    model = new comboBoxmodel;
    ui->comboBox->setModel(model);
}

addQuestionWindow::~addQuestionWindow()
{
    delete ui;
}
