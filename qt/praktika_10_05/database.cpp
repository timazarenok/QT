#include "database.h"

DataBase::DataBase(QObject *parent) : QObject(parent)
{
    createConnection();
    createTables();
    insertIntoTables();
}

bool DataBase::createConnection()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("server");
    db.setDatabaseName(DATABASE_PATH);
    return db.open();
}

void DataBase::createTables()
{
    QSqlQuery query;
    query.exec(SUBJECTS);
    query.exec(QUESTIONS);
}

void DataBase::insertIntoTables()
{
    insertIntoSubject("Philosophy");
    insertIntoQuestions(QList<QVariant>{QVariant("Валик лох?"), QVariant(0), QVariant(1)});
    insertIntoQuestions(QList<QVariant>{QVariant("Воробей водила?"), QVariant(0), QVariant(1)});
    insertIntoQuestions(QList<QVariant>{QVariant("Вова классный?"), QVariant(0), QVariant(1)});
    insertIntoQuestions(QList<QVariant>{QVariant("Никита лох?"), QVariant(0), QVariant(1)});
    insertIntoQuestions(QList<QVariant>{QVariant("Гром гей?"), QVariant(1), QVariant(1)});
    insertIntoQuestions(QList<QVariant>{QVariant("Почему я не умер?"), QVariant(1), QVariant(1)});
    insertIntoQuestions(QList<QVariant>{QVariant("Почему Воробей молчит?"), QVariant(1), QVariant(1)});
    insertIntoQuestions(QList<QVariant>{QVariant("Он плачет?"), QVariant(1), QVariant(1)});
    insertIntoQuestions(QList<QVariant>{QVariant("Почему шеф Шеф?"), QVariant(2), QVariant(1)});
    insertIntoQuestions(QList<QVariant>{QVariant("Воробей ты тупой?"), QVariant(2), QVariant(1)});
    insertIntoQuestions(QList<QVariant>{QVariant("Что там по анкете на bluword?"), QVariant(2), QVariant(1)});
    insertIntoQuestions(QList<QVariant>{QVariant("Валик играет?"), QVariant(2), QVariant(1)});
    insertIntoQuestions(QList<QVariant>{QVariant("Петя фанат шефа?"), QVariant(3), QVariant(1)});
    insertIntoQuestions(QList<QVariant>{QVariant("Марина сдаст алгоритмизацию?"), QVariant(3), QVariant(1)});
    insertIntoQuestions(QList<QVariant>{QVariant("Кого отчислят первым?"), QVariant(3), QVariant(1)});
    insertIntoQuestions(QList<QVariant>{QVariant("Где Еж?"), QVariant(3), QVariant(1)});
}

void DataBase::closeDatabase()
{
    db.close();
}


bool DataBase::insertIntoSubject(const QString &data)
{
    QSqlQuery query;
    query.prepare("insert into Subjects("
                  "sub_name"
                  ")"
                  "values(:sub_name)");
    query.bindValue(":sub_name", data);
    return queryRun(query, "Subjects");
}

bool DataBase::insertIntoQuestions(const QVariantList &data)
{
    QSqlQuery query;
    query.prepare("insert into Questions("
                  "content,"
                  "difficulty_id,"
                  "subject_id"
                  ")"
                  "values(:content, :difficulty_id, :subject_id)");
    query.bindValue(":content", data[0].toString());
    query.bindValue(":difficulty_id", data[1].toInt());
    query.bindValue(":subject_id", data[2].toInt());
    return queryRun(query, "Questions");
}



bool DataBase::queryRun(QSqlQuery& query, const char* table_name)
{
        if(!query.exec())
        {
            qDebug() << "error in " << table_name;
            qDebug() << query.lastError().text();
            return false;
        }
       // qDebug() << "ok";
        return true;
}







