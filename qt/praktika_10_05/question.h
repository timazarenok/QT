#ifndef QUESTION_H
#define QUESTION_H

#include <QObject>
#include <QString>

class Question
{
public:
    Question();
    Question(QString content, int difficulty);
    QString cont;
    int diff;
};

#endif // QUESTION_H
