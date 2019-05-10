#ifndef COMBOBOXMODEL_H
#define COMBOBOXMODEL_H

#include <QAbstractListModel>
#include <QSqlQuery>

class comboBoxmodel : public QAbstractListModel
{
    Q_OBJECT

public:
    using DataPair =  QPair<QVariant, QVariant>;
    explicit comboBoxmodel(QObject *parent = nullptr);
    QVector<DataPair> container;

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
};

#endif // COMBOBOXMODEL_H
