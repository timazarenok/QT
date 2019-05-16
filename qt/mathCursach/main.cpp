#include "Mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow b(3, 3);
    b.show();
    return a.exec();
}
