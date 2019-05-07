#include "database.h"

database::database(QObject *parent) : QObject(parent)
{
   if(!QFile(DATABASE_PATH).exists())
   {
       restoreDataBase();
   }
   else
   {
     openDataBase();
   }
}

bool database::openDataBase()
{
#ifdef DEBUG
    qDebug() << "openDataBase";
#endif

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("server");
    db.setDatabaseName(DATABASE_PATH);
    return db.open();
}

bool database::restoreDataBase()
{
#ifdef DEBUG
    qDebug() << "restoreDatabase();";
#endif
    openDataBase();
    createTables();
    insertIntoTables();
}

void database::createTables()
{
    QSqlQuery query;
    query.exec(Human);
    query.exec(Sex);
}

void database::insertIntoTables()
{
    insertIntoTableSex(QList<QVariant>{QVariant("Male")});
    insertIntoTableSex(QList<QVariant>{QVariant("Female")});
    insertIntoTableHuman(QList<QVariant>{QVariant("Valik"), QVariant(1)});
    insertIntoTableHuman(QList<QVariant>{QVariant("Grom"), QVariant(2)});
}

bool database::insertIntoTableHuman(const QVariantList& data)
{
    QSqlQuery query;
    query.prepare("INSERT INTO Human("
                  "h_name,"
                  "h_sex"
                  ")"
                  "values(:h_name, :h_sex)");
    query.bindValue(":h_name", data[0].toString());
    query.bindValue(":h_sex", data[1].toInt());
    return queryRun(query, "Human");
}

bool database::insertIntoTableSex(const QVariantList &data)
{
    QSqlQuery query;
    query.prepare("INSERT INTO Sex("
                  "s_name"
                  ")"
                  "values(:s_name)");
    query.bindValue(":s_name", data[0].toString());
    return queryRun(query, "Sex");
}

bool database::queryRun(QSqlQuery& query, const char* table_name)
{
        if(!query.exec())
        {
            qDebug() << "error in " << table_name;
            qDebug() << query.lastError().text();
            return false;
        }
        qDebug() << "ok";
        return true;
}
