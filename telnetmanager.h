#ifndef TELNETMANAGER_H
#define TELNETMANAGER_H

#include <QObject>
#include "QTelnet.h"
#include "telnetparser.h"
#include "clientlistmodel.h"

class TelnetManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(ClientListModel* clientListModel READ clientListModel NOTIFY clientListModelChanged)
public:
    explicit TelnetManager(QObject *parent = nullptr);
    ~TelnetManager();

    ClientListModel* clientListModel() { return &m_clientListModel; }

private:
    QTelnet m_telnetSocket;
    TelnetParser m_telnetParser;
    ClientListModel m_clientListModel;

private slots:
    void onStateChanged(QAbstractSocket::SocketState s);
    void handleNewData(const char *buff, int len);

signals:
    void clientListModelChanged();
};

Q_DECLARE_METATYPE(ClientListModel*)

#endif // TELNETMANAGER_H
