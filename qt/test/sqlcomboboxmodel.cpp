#include "sqlcomboboxmodel.h"

SqlComboBoxModel::SqlComboBoxModel(QObject *parent) : QAbstractListModel(parent)
{
    QSqlQuery query;
    query.exec(SELECT_ALL_BRANDS);
    while(query.next()){
        m_content.push_back(DataPair(query.value(0), query.value(1)));
    }
}

QVariant SqlComboBoxModel::data(const QModelIndex &index, int role) const
{
    const DataPair& data = m_content.at( index.row() );
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

int SqlComboBoxModel::rowCount(const QModelIndex &parent) const
{
    return m_content.count();
}

void SqlComboBoxModel::setQuery(QVariant str)
{
    modelQuery = str;
    qDebug() << modelQuery.toString();
}
