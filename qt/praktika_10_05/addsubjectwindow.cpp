#include "addsubjectwindow.h"
#include "ui_addsubjectwindow.h"

addSubjectWindow::addSubjectWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::addSubjectWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &addSubjectWindow::slotaddSubject);
}

addSubjectWindow::~addSubjectWindow()
{
    delete ui;
}

void addSubjectWindow::slotaddSubject()
{
    if(!DataBase::insertIntoSubject(ui->lineEdit->text()) || ui->lineEdit->text() == "")
        {
             QMessageBox::information(this, "error", "error");
        }
        else{
            QMessageBox::information(this, "info window", "u are succesfully added");
        }

}
