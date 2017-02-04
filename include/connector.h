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
    bool errorEmited;

signals:
    void incomingMessage(QString *msg);
    void error(QAbstractSocket::SocketError);
    void error(QString* errorMsg);
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
    QString errorToText(QAbstractSocket::SocketError error_);
};

#endif // CONNECTOR_H
