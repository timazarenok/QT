#ifndef SIZEWINDOW_H
#define SIZEWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>
#include "database.h"
#include <QLineEdit>


namespace Ui {
class SizeWindow;
}

class SizeWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SizeWindow(QWidget *parent = nullptr);
    ~SizeWindow();
    QSqlTableModel* table;

signals:

public slots:
    void slotAddSize();

private:
    Ui::SizeWindow *ui;
    void setTableModel();
    void setTableView();
};

#endif // SIZEWINDOW_H
