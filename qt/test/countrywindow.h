#ifndef COUNTRYWINDOW_H
#define COUNTRYWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>
#include "database.h"
#include <QLineEdit>

namespace Ui {
class CountryWindow;
}

class CountryWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CountryWindow(QWidget *parent = nullptr);
    QSqlTableModel* table;

    ~CountryWindow();
signals:

public slots:
    void slotAddCountry();

private:
    Ui::CountryWindow *ui;
    void setTableModel();
    void setTableView();
};

#endif // COUNTRYWINDOW_H
