#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <QTcpSocket>
#include <QString>
#include <QObject>
#include "const.h"
#include "encoder.h"


class Connector : public QObject
{

    Q_OBJECT

private:
    QTcpSocket socket;
    QString ip;
    int service;
    char buf[MAX_MESSAGE_LENGTH];

signals:
    void incomingMessage(QString *msg);
    void error(QAbstractSocket::SocketError);
    void error(int);
    void connectionEstablished();

public slots:
    void onError(QAbstractSocket::SocketError);
    void onRead();

public:
    friend class MainWindow;
    Connector (const QString& new_ip = "localhost");
    void setIp(const QString& new_ip);
    int connectToServer(const QString& username);
    int sendMessage(const QString& msg);
};

#endif // CONNECTOR_H
