#include "addsubjectwindow.h"
#include "ui_addsubjectwindow.h"

addSubjectWindow::addSubjectWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::addSubjectWindow)
{
    ui->setupUi(this);
    setTableModel();
    setTableView();
    connect(ui->pushButton, &QPushButton::clicked, this, &addSubjectWindow::slotaddSubject);
}

addSubjectWindow::~addSubjectWindow()
{
    delete ui;
}

void addSubjectWindow::slotaddSubject()
{
    if(!DataBase::insertIntoSubject(ui->lineEdit->text()))
        {
             QMessageBox::information(this, "error", "error");
        }
        else{
            QMessageBox::information(this, "info window", "u are succesfully added");
            model->select();
            ui->lineEdit->setText("");
        }

}


void addSubjectWindow::setTableModel()
{
    model = new QSqlTableModel;
    model->setTable("Subjects");
    model->setHeaderData(1, Qt::Horizontal, QVariant("Subjects"));
    model->select();
}

void addSubjectWindow::setTableView()
{
    ui->subjectTableView->setModel(model);
    ui->subjectTableView->setColumnHidden(0, true);
}
