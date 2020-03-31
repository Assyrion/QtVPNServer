#include "telnetmanager.h"
#include <QHostAddress>
#include <QMetaType>
#include <QProcess>

TelnetManager::TelnetManager(QObject *parent)
    : QObject(parent),
      m_telnetSocket(this),
      m_telnetParser(this)
{
    qRegisterMetaType<ClientListModel*>();

    connect(&m_telnetSocket, &QTelnet::newData, &m_telnetParser,  &TelnetParser::handleNewData);
    connect(&m_telnetParser, &TelnetParser::newClient, this, [this](const Client& c) {
            m_clientListModel.addNewClient(c);
            emit clientListModelChanged();
    });

    connect(&m_telnetSocket, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(onStateChanged(QAbstractSocket::SocketState)) );

    m_telnetSocket.connectToHost("127.0.0.1", 7505);

//    //TEST

//    Client c1("192.168.1.2", "lolilol");
//    Client c2("192.168.1.3", "fafafaf");

//    m_clientListModel.addNewClient(c1);
//    m_clientListModel.addNewClient(c2);
}

TelnetManager::~TelnetManager()
{
    m_telnetSocket.disconnectFromHost();
}

void TelnetManager::startVPNServer()
{
    QProcess p;
    p.start("systemctl start openvpn@server");
    p.waitForFinished();

    m_telnetSocket.connectToHost("127.0.0.1", 7505);
}

void TelnetManager::stopVPNServer()
{
    QProcess p;
    p.start("systemctl stop openvpn@server");
    p.waitForFinished();
}

void TelnetManager::onStateChanged(QAbstractSocket::SocketState s)
{
    switch( s )
    {
    case QAbstractSocket::UnconnectedState:
//		setStatusText( tr("Desconectado"), true );
//		ui->btConnect->setText( tr("Conectar") );
        break;
    case QAbstractSocket::HostLookupState:
//		setStatusText( tr("Resolviendo DNS %1").arg(telnet.peerName()), true );
//		ui->btConnect->setText( tr("Cancelar") );
        break;
    case QAbstractSocket::ConnectingState:
//		setStatusText( tr("Conectando a %1").arg(telnet.peerInfo()), true );
//		ui->btConnect->setText( tr("Cancelar") );
        break;
    case QAbstractSocket::ConnectedState:
//		setStatusText( tr("Conectado a %1").arg(telnet.peerInfo()), true );
//		ui->btConnect->setText( tr("Desconectar") );
        break;
    case QAbstractSocket::BoundState:
//		setStatusText( tr("Enlazado"), true );
//		ui->btConnect->setText( tr("- - - -") );
        break;
    case QAbstractSocket::ListeningState:
//		setStatusText( tr("Escuchando"), true );
//		ui->btConnect->setText( tr("- - - -") );
        break;
    case QAbstractSocket::ClosingState:
//		setStatusText( tr("Cerrando"), true );
//		ui->btConnect->setText( tr("Forzar cierre") );
        break;
    }
    qDebug() << "status " << s;

}

void TelnetManager::handleNewData(const char *buff, int len)
{

}
