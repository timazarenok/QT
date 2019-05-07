#ifndef DATABASE_H
#define DATABASE_H

#define DEBUG
#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QDebug>
#include <QSqlError>
#include <QSqlRelation>
#include <QSqlRecord>
#include "util.h"
#include <QFile>
#include <QStandardPaths>
#include "queries.h"



class Database : public QObject
{
    Q_OBJECT
public:
    QSqlDatabase db;
    explicit Database(QObject *parent = nullptr);
    bool openDataBase();
    bool restoreDataBase();
    void closeDataBase();
    void createTables();
    void insertIntoTables();
    static bool insertIntoTableCountries(const QVariantList& data);
    static bool insertIntoTableBrand(const QVariantList& data);
    static bool insertIntoTableGoods(const QVariantList& data);
    static bool insertIntoTableStorage(const QVariantList& data);
    static bool insertIntoTableSizes(const QVariantList& data);
private:
    static bool queryRun(QSqlQuery& query, const char* table_name);
public:

signals:

public slots:

};



#endif // DATABASE_H
