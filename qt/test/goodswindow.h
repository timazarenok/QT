#ifndef GOODSWINDOW_H
#define GOODSWINDOW_H

#include <QMainWindow>
#include "database.h"
#include "sqlcomboboxmodel.h"
#include "sqlcomboboxmodelcountry.h"
#include <QMessageBox>

namespace Ui {
class GoodsWindow;
}

class GoodsWindow : public QMainWindow
{
    Q_OBJECT
private:
    SqlComboBoxModel* m;
    SqlComboBoxModelCountry* c;
public:
    explicit GoodsWindow(QWidget *parent = nullptr);
    ~GoodsWindow();
    QSqlTableModel* table;
signals:

public slots:
    void slotAddGoods();

private:
    Ui::GoodsWindow *ui;
    void setTableModel();
    void setTableView();
};

#endif // GOODSWINDOW_H
