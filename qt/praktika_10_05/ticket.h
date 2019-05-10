#ifndef TICKET_H
#define TICKET_H
#include <QVector>
#include "question.h"
#include <initializer_list>
#include <QDebug>

class Ticket
{
public:
    Ticket();
    Ticket(std::initializer_list<Question> a);
    QVector<Question> questions;
    void print_ticket_debug();
};

#endif // TICKET_H
