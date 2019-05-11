#ifndef ADDQUESTIONWINDOW_H
#define ADDQUESTIONWINDOW_H

#include <QMainWindow>
#include "database.h"
#include "comboboxmodel.h"
#include <QVariantList>
#include <QMessageBox>


namespace Ui {
class addQuestionWindow;
}

class addQuestionWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit addQuestionWindow(QWidget *parent = nullptr);
    ~addQuestionWindow();
private:
    comboBoxmodel* model;
    QSqlTableModel* table;
    void setTableModel();
    void setTableView();
public slots:
    void slotAddQuestion();

private:
    Ui::addQuestionWindow *ui;
};

#endif // ADDQUESTIONWINDOW_H
