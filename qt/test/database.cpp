#include "database.h"

Database::Database(QObject *parent) : QObject(parent)
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

void Database::createTables()
{
    QSqlQuery query;
    query.exec(COUNTRIES_TABLE);
    query.exec(BRAND_TABLE);
    query.exec(GOODS_TABLE);
    query.exec(STORAGE_TABLE);
    query.exec(SIZES_TABLE);
}

void Database::insertIntoTables()
{

}

bool Database::openDataBase()
{
#ifdef DEBUG
    qDebug() << "openDataBase";
#endif

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("server");
    db.setDatabaseName(DATABASE_PATH);
    return db.open();
}
bool Database::restoreDataBase()
{
#ifdef DEBUG
    qDebug() << "restoreDatabase();";
#endif
    openDataBase();
    createTables();
    insertIntoTables();
}
bool Database::insertIntoTableCountries(const QVariantList& data)
{
    QSqlQuery query;
       query.prepare("insert into Countries("
                     "c_name"
                     ")"
                     "values(:c_name)");
       query.bindValue(":c_name",    data[0].toString());
       return queryRun(query, "country");
}

bool Database::insertIntoTableBrand(const QVariantList& data)
{
    QSqlQuery query;
    query.prepare("insert into Brand("
                  "brand_name"
                  ")"
                  "values(:brand_name)");
    query.bindValue(":brand_name", data[0].toString());
    return queryRun(query, "brand");
}

bool Database::insertIntoTableGoods(const QVariantList& data)
{
    QSqlQuery query;
    query.prepare("insert into Goods("
                  "g_name,"
                  "g_brand,"
                  "origin,"
                  "price"
                  ")"
                  "values(:g_name, :g_brand, :origin, :price)");
    query.bindValue(":g_name", data[0].toString());
    query.bindValue(":g_brand", data[1].toString());
    query.bindValue(":origin", data[2].toInt());
    query.bindValue(":price", data[3].toReal());
    return queryRun(query, "goods");
}

bool Database::insertIntoTableSizes(const QVariantList& data)
{
    QSqlQuery query;
    query.prepare("insert into Sizes("
                  "g_size"
                  ")"
                  "values(:g_size)");
    query.bindValue(":g_size", data[0].toString());
    return queryRun(query, "sizes");
}

bool Database::insertIntoTableStorage(const QVariantList& data)
{
    QSqlQuery query;
    query.prepare("insert into Storage("
                  "goods,"
                  "g_size"
                  ")"
                  "values(:goods, :g_size)");
    query.bindValue(":goods", data[0].toInt());
    query.bindValue(":g_size", data[1].toInt());
    return queryRun(query, "storage");
}

bool Database::queryRun(QSqlQuery& query, const char* table_name)
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

void Database::closeDataBase()
{

}

