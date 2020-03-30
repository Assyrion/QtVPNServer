#include "telnetparser.h"
#include <QRegularExpression>

TelnetParser::TelnetParser(QObject *parent) : QObject(parent)
{

}

void TelnetParser::handleNewData(const char *buff, int len)
{
    QByteArray b(buff, len);
    QString strData(b);

    strData = strData.simplified();

//    QString test = ">CLIENT:ESTABLISHED,21 >CLIENT:ENV,n_clients=1 >CLIENT:ENV,time_unix=1585526818 >CLIENT:ENV,time_ascii=Mon Mar 30 02:06:58 2020 >CLIENT:ENV,ifconfig_pool_netmask=255.255.255.0 >CLIENT:ENV,ifconfig_pool_remote_ip=10.8.0.2 >CLIENT:ENV,trusted_port=52814 >CLIENT:ENV,trusted_ip=192.168.1.1 >CLIENT:ENV,common_name=antoine >CLIENT:ENV,IV_AUTO_SESS=1 >CLIENT:ENV,IV_PROTO=2 >CLIENT:ENV,IV_TCPNL=1 >CLIENT:ENV,IV_NCP=2 >CLIENT:ENV,IV_PLAT=win >CLIENT:ENV,IV_VER=3.git::f225fcd0 >CLIENT:ENV,IV_GUI_VER=OCmacOS_3.1.3-713 >CLIENT:ENV,untrusted_port=52814 >CLIENT:ENV,untrusted_ip=192.168.1.1 >CLIENT:ENV,tls_serial_hex_0=2f:2d:63:72:f8:1c:ca:fa:fd:7e:37:45:d5:93:5b:99 >CLIENT:ENV,tls_serial_0=62709386227873492317893703277974084505 >CLIENT:ENV,tls_digest_sha256_0=ed:49:d1:d7:30:e9:3e:6d:b1:02:3c:c1:e2:bb:aa:cf:5c:a9:d8:2c:80:a6:73:bd:4d:8f:69:bf:7b:93:8a:53 >CLIENT:ENV,tls_digest_0=f6:bb:87:8f:c9:02:78:f0:01:18:e1:a6:0c:3f:5a:e5:56:1e:03:a9 >CLIENT:ENV,tls_id_0=CN=antoine >CLIENT:ENV,X509_0_CN=antoine >";

    QRegularExpression regexp("^>CLIENT:ESTABLISHED.*ifconfig_pool_remote_ip=(?<ip>[\\d|\\.]+).*common_name=(?<name>\\w+).*$");
    QRegularExpressionMatch match = regexp.match(strData);
    if (match.hasMatch())
    {
        auto ip = match.captured("ip");
        auto name = match.captured("name");
        Client c(ip, name);

        emit newClient(c);
    }
}
