#ifndef RELATIONALTABLEMODEL_H
#define RELATIONALTABLEMODEL_H

#include <QMainWindow>
#include <QSqlRelationalTableModel>
#include <QSqlRelationalDelegate>
#include <QSqlRelation>

namespace Ui {
class RelationalTableModel;
}

class RelationalTableModel : public QMainWindow
{
    Q_OBJECT

public:
    explicit RelationalTableModel(QWidget *parent = nullptr);
    ~RelationalTableModel();

private:
    Ui::RelationalTableModel *ui;
    QSqlRelationalTableModel *modelHuman;
    void setupHumanModel(const QString &tableName, const QStringList &headers);
    void createUI();
};

#endif // RELATIONALTABLEMODEL_H
