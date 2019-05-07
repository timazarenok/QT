#include "database.h"

database::database(QObject *parent) : QObject(parent)
{
    openDatabase();
    createTables();
}

bool database::openDatabase()
{
#ifdef DEBUG
    qDebug() << "openDataBase";
#endif

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("server");
    db.setDatabaseName(DATABASE_PATH);
    return db.open();
}

void database::createTables()
{
   QSqlQuery query;
   query.exec("create table t1("
              "id INTEGER PRIMARY KEY AUTOINCREMENT,"
              "m_name TEXT"
              ")");
   query.exec("insert into t1("
              "m_name"
              ")"
              "values('Grom'),"
              "('Rostovtsev'),"
              "('Valik')");
}

void database::iterateAll()
{
    QSqlQuery query;
    query.exec("select id, m_name from t1");
               while(query.next())
                {
                   qDebug() << query.value(1).toString();
                }
}




