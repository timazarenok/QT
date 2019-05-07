#ifndef DATABASE_H
#define DATABASE_H

#define DEBUG
#include <QObject>
#include <QSqlDatabase>
#include "path.h"
#include <QDebug>
#include <QSqlQuery>

class database : public QObject
{
    Q_OBJECT
public:
    explicit database(QObject *parent = nullptr);
    bool openDatabase();
    void createTables();
    void insertIntoTables();
    void iterateAll();
private:
    QSqlDatabase db;

signals:

public slots:
};

#endif // DATABASE_H
