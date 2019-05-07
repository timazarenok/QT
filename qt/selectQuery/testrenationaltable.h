#ifndef TESTRENATIONALTABLE_H
#define TESTRENATIONALTABLE_H

#include <QMainWindow>

namespace Ui {
class TestRenationalTable;
}

class TestRenationalTable : public QMainWindow
{
    Q_OBJECT

public:
    explicit TestRenationalTable(QWidget *parent = nullptr);
    ~TestRenationalTable();

private:
    Ui::TestRenationalTable *ui;
};

#endif // TESTRENATIONALTABLE_H
