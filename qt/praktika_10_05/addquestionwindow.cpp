#include "addquestionwindow.h"
#include "ui_addquestionwindow.h"


addQuestionWindow::addQuestionWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::addQuestionWindow)
{
    ui->setupUi(this);
    model = new comboBoxmodel;
    ui->comboBox->setModel(model);
    setTableModel();
    setTableView();
    connect(ui->pushButton, &QPushButton::clicked, this, &addQuestionWindow::slotAddQuestion);
}

addQuestionWindow::~addQuestionWindow()
{
    delete ui;
}

void addQuestionWindow::setTableModel()
{
    table = new QSqlTableModel;
    table->setTable("Questions");
    table->setHeaderData(1, Qt::Horizontal, QVariant("Questions"));
    table->select();
}

void addQuestionWindow::setTableView()
{
    ui->QuestionstableView->setModel(table);
    ui->QuestionstableView->setColumnHidden(0, true);
}

void addQuestionWindow::slotAddQuestion()
{
    if(!DataBase::insertIntoQuestions(QVariantList{QVariant(ui->ContentlineEdit->text()),
                                     QVariant(ui->difficult_line_edit->text()),
                                     ui->comboBox->currentData()}))
    {
         QMessageBox::information(this, "error", "error");
    }
    else{
        QMessageBox::information(this, "info window", "u are succesfully added");
        ui->ContentlineEdit->setText("");
        ui->difficult_line_edit->setText("");
        table->select();
    }

}
