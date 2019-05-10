#include "ticketcomplection.h"

ticketComplection::ticketComplection()
{

}
QVector<Question> ticketComplection::getQuestion()
{
    QVector<Question> cont;
    QSqlQuery query;
    query.prepare("select content, difficulty_id from Questions where subject_id = :subject_id");
    query.bindValue(":subject_id", subjectId);
    query.exec();
    while(query.next())
    {
        cont.push_back(Question(query.value(0).toString() , query.value(1).toInt()));
    }
    return cont;
}

void ticketComplection::shuffle_all()
{
    std::random_device rd;
    std::mt19937 g(rd());
    for (auto i = questions.begin(); i != questions.end(); ++i) {
        std::shuffle(i->begin(), i->end(), g);
    }
}

void ticketComplection::complectTickets()
{
    int size = get_max_ticket();
    for (int i = 0; i != size; ++i) {
        tickets.push_back(Ticket{questions[0][i], questions[1][i], questions[2][i], questions[3][i]});
    }
}

void ticketComplection::complectQuestions()
{
    questions.push_back(QVector<Question>(0));
    questions.push_back(QVector<Question>(0));
    questions.push_back(QVector<Question>(0));
    questions.push_back(QVector<Question>(0));
    QVector<Question> temp = getQuestion();
    for (auto i = temp.begin(); i != temp.end();++i) {
        questions[i->diff].push_back(*i);
    }
}

void ticketComplection::set_subjectId(int id)
{
    subjectId = id;
}

void ticketComplection::run()
{
    getContent();
    complectQuestions();
    shuffle_all();
    complectTickets();
}

int ticketComplection::get_max_ticket()
{
    qDebug() << "1!!!!!!!!";
    QSqlQuery query(MIN_QUERIES);
    query.next();
    return query.value(0).toInt();
}
void ticketComplection::getContent()
{
     cont =  getQuestion();
     for(auto i = cont.begin(); i != cont.end(); ++i)
     {
         qDebug() << i->cont;
    }
}
