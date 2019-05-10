#include "mainwindow.h"
#include <QApplication>
#include "database.h"
#include "ticketcomplection.h"
#include "ticket.h"
#include "addsubjectwindow.h"
#include "addquestionwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    DataBase db;
    ticketComplection tc;
    addSubjectWindow asw;
    asw.show();
    addQuestionWindow qw;
    qw.show();
    tc.set_subjectId(1);
    tc.run();
    auto result = tc.tickets;
    for (auto i = result.begin(); i != result.end(); ++i) {
        i->print_ticket_debug();
    }
    return a.exec();
}
