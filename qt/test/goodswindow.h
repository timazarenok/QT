#ifndef GOODSWINDOW_H
#define GOODSWINDOW_H

#include <QMainWindow>
#include "database.h"
#include "sqlcomboboxmodel.h"

namespace Ui {
class GoodsWindow;
}

class GoodsWindow : public QMainWindow
{
    Q_OBJECT
private:
    SqlComboBoxModel* m;
public:
    explicit GoodsWindow(QWidget *parent = nullptr);
    ~GoodsWindow();

private:
    Ui::GoodsWindow *ui;
};

#endif // GOODSWINDOW_H
