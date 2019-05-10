#ifndef DATABASE_H
#define DATABASE_H

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
#include "question.h"
#include <QMessageBox>

class DataBase : public QObject
{
    Q_OBJECT
private:
       QSqlDatabase db;
       static bool queryRun(QSqlQuery& query, const char* table_name);
public:
    explicit DataBase(QObject *parent = nullptr);
    void createTables();
    void insertIntoTables();
    bool createConnection();
    void closeDatabase();
    static bool insertIntoSubject(const QString& data);
    static bool insertIntoQuestions(const QVariantList& data);

    signals:

public slots:
};

#endif // DATABASE_H
