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
#include <QFile>
#include <QStandardPaths>
#include "util.h"
#include "queries.h"



class database : public QObject
{
    Q_OBJECT
private:
    static bool queryRun(QSqlQuery& query, const char* table_name);
public:
    explicit database(QObject *parent = nullptr);
    QSqlDatabase db;
    bool openDataBase();
    bool restoreDataBase();
    void closeDataBase();
    void createTables();
    void insertIntoTables();
    static bool insertIntoTableHuman(const QVariantList& data);
    static bool insertIntoTableSex(const QVariantList& data);

signals:

public slots:
};

#endif // DATABASE_H
