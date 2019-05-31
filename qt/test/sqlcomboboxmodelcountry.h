#ifndef SQLCOMBOBOXMODELCOUNTRY_H
#define SQLCOMBOBOXMODELCOUNTRY_H

#include <QAbstractListModel>
#include <QObject>
#include <QSqlQuery>
#include <QPair>
#include "queries.h"
#include <QDebug>

class SqlComboBoxModelCountry : public QAbstractListModel
{
    Q_OBJECT
    QVariant modelQuery;

public:
    explicit SqlComboBoxModelCountry(QObject *parent = nullptr);
    using DataPair = QPair<QVariant, QVariant>;
    QList< DataPair > m_content;
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    void setQuery(QVariant str);
private:
};

#endif // SQLCOMBOBOXMODELCOUNTRY_H
