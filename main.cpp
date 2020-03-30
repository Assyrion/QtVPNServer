#include <QGuiApplication>
#include <QQmlContext>
#include <QQmlApplicationEngine>

#include "telnetmanager.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    TelnetManager telnetManager;
    auto context = engine.rootContext();
    context->setContextProperty("telnetManager", &telnetManager);

//    QTelnet telnet;

//    connect( &telnet, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(onStateChanged(QAbstractSocket::SocketState)) );
//    QObject::connect(&telnet, &QTelnet::newData, &telnetParser,  &TelnetParser::handleNewData);

    return app.exec();
}
