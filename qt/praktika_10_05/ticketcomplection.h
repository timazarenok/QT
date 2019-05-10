#ifndef TICKETCOMPLECTION_H
#define TICKETCOMPLECTION_H

#include <QVector>
#include "question.h"
#include "database.h"
#include <random>
#include <algorithm>
#include "ticket.h"
#include <iterator>

class ticketComplection
{
public:
    ticketComplection();
    void addTicket();
    void set_subjectId(int id);
    QVector<Question> cont;
    QVector<Ticket> tickets;
    void run();
    int get_max_ticket();
private:
    int subjectId;
    QVector<Question> getQuestion();
    QVector<QVector<Question>> questions;
    void getContent();
    void complectQuestions();
    void shuffle_all();
    void complectTickets();
};

#endif // TICKETCOMPLECTION_H
