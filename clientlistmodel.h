#ifndef CLIENTLISTMODEL_H
#define CLIENTLISTMODEL_H

#include <QAbstractListModel>

class Client
{

public:
    Client() {}
    Client(QString ip, QString name)
        : m_ip(ip),
          m_name(name)
    {}

    QString ip() const { return m_ip; }
    QString name() const { return m_name; }

private:
    QString m_ip;
    QString m_name;
};

Q_DECLARE_METATYPE(Client)

class ClientListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum ClientRoles {
            IpRole = Qt::UserRole + 1,
            NameRole
        };

    ClientListModel(QObject *parent = 0);

    QHash<int, QByteArray> roleNames() const override;
//    bool insertRows(int position, int rows, const QModelIndex &index) override;
    QVariant data(const QModelIndex &index, int role) const override;
    int rowCount(const QModelIndex &p) const override;

    void addNewClient(const Client& c);

private:
    QList<Client> m_clientList;
};

#endif // CLIENTLISTMODEL_H
