#include "mainwindow.h"
#include <QApplication>
#include "database.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Database db;
    MainWindow w;
    w.show();
    return a.exec();
}
