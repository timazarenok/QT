#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "countrywindow.h"
#include "brandwindow.h"
#include "sizewindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void slotStartCountryWindow();
    void slotStartBrandWindow();
    void slotsStartSizeWindow();

private:
    Ui::MainWindow *ui;
    CountryWindow *cw;
    BrandWindow *bw;
    SizeWindow *sw;
};

#endif // MAINWINDOW_H
