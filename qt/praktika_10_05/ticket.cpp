#include "ticket.h"

Ticket::Ticket()
{

}

Ticket::Ticket(std::initializer_list<Question> a)
{
    for (auto i = a.begin(); i != a.end(); ++i) {
        questions.push_back(*i);
    }
}

void Ticket::print_ticket_debug()
{
    qDebug() << "----------";
    for(auto i = questions.begin(); i != questions.end(); ++i)
    {
        qDebug() << i->cont;
    }
    qDebug() << "----------";
}
