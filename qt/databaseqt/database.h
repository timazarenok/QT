#ifndef DATABASE_H
#define DATABASE_H

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

class Database: public QObject
{
    Q_OBJECT
private:


public:
    QSqlDatabase db;
    explicit Database(QObject *parent = nullptr);
    void conect_to_database();
    bool openDataBase();
    bool restoreDataBase();
    void closeDataBase();
    bool createTable();
signals:

public slots:
};

#endif // DATABASE_H
