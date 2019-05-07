#ifndef SQLCOMBOBOXMODEL_H
#define SQLCOMBOBOXMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include <QSqlQuery>
#include <QPair>
#include "queries.h"
#include <QDebug>

class SqlComboBoxModel: public QAbstractListModel
{
    Q_OBJECT
private:
    QVariant modelQuery;
    public:
    explicit SqlComboBoxModel( QObject *parent = nullptr);
    using DataPair = QPair<QVariant, QVariant>;
    QList< DataPair > m_content;
    virtual QVariant data( const QModelIndex & index, int role = Qt::DisplayRole ) const;
    virtual int rowCount( const QModelIndex & parent = QModelIndex() ) const;
    void setQuery(QVariant str);


};

#endif // SQLCOMBOBOXMODEL_H
