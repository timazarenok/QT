#include "mainwindow.h"
#include <QApplication>
#include "database.h"
#include "sqlquerymodel.h"
#include "relationaltablemodel.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    database db;
//    MainWindow w;
//    w.show();
    RelationalTableModel rm;
    rm.show();
    return a.exec();
}
