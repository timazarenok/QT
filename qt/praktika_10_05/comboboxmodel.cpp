#include "comboboxmodel.h"

comboBoxmodel::comboBoxmodel(QObject *parent)
    : QAbstractListModel(parent)
{
    QSqlQuery query;
    query.exec("select id, sub_name from Subjects");
    while(query.next())
    {
        container.push_back(DataPair(query.value(0), query.value(1)));
    }
}

int comboBoxmodel::rowCount(const QModelIndex &parent) const
{
    return container.count();
}

QVariant comboBoxmodel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
    return QVariant();
    const DataPair& data = container.at(index.row());
    QVariant value;
    switch ( role )
    {
        case Qt::DisplayRole:
        {
            value = data.second;
        }
        break;

        case Qt::UserRole:
        {
            value = data.first;
        }
        break;

        default:
            break;
    }

    return value;
}

