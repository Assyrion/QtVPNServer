#ifndef TELNETPARSER_H
#define TELNETPARSER_H

#include <QObject>
#include <QTelnet.h>
#include "clientlistmodel.h"

class TelnetParser : public QObject
{
    Q_OBJECT
public:
    explicit TelnetParser(QObject *parent = nullptr);

public slots:
    void handleNewData(const char *buff, int len);

signals:
    void newClient(const Client& c);
};

#endif // TELNETPARSER_H
