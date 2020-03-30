#include "clientlistmodel.h"
#include <QDebug>

ClientListModel::ClientListModel(QObject *parent)
    : QAbstractListModel(parent)
{

}

QHash<int, QByteArray> ClientListModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[IpRole] = "client_ip";
    roles[NameRole] = "client_name";
    return roles;
}

QVariant ClientListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() < rowCount(index))
    {
        switch(role)
        {
        case IpRole:
            return m_clientList[index.row()].ip();
            break;

        case NameRole:
            return m_clientList[index.row()].name();
            break;
        }
    }
    return QVariant();
}

int ClientListModel::rowCount(const QModelIndex &p) const
{
    Q_UNUSED(p)
    return m_clientList.size();
}


void ClientListModel::addNewClient(const Client &c)
{
    int i = m_clientList.size();

    qDebug() << "insert : " << m_clientList.size() << c.ip() << c.name();

    beginInsertRows(QModelIndex(), i, i);
    m_clientList.append(c);
    endInsertRows();
}
