#ifndef BRANDWINDOW_H
#define BRANDWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "sqlcomboboxmodel.h"
#include "database.h"

namespace Ui {
class BrandWindow;
}

class BrandWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit BrandWindow(QWidget *parent = nullptr);
    ~BrandWindow();
signals:

 public slots:
    void slotAddBrand();

private:
    Ui::BrandWindow *ui;
};

#endif // BRANDWINDOW_H
