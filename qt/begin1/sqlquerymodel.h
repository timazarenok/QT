#ifndef SQLQUERYMODEL_H
#define SQLQUERYMODEL_H

#include <QMainWindow>
#include <QSqlTableModel>

namespace Ui {
class sqlQueryModel;
}

class sqlQueryModel : public QMainWindow
{
    Q_OBJECT

public:
    explicit sqlQueryModel(QWidget *parent = nullptr);
    ~sqlQueryModel();

private:
    Ui::sqlQueryModel *ui;
    QSqlTableModel  *model;
    void setupModel(const QString &tableName, const QStringList &headers);
    void createUI();
};

#endif // SQLQUERYMODEL_H
