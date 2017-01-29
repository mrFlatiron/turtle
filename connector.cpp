#include "connector.h"
#include <QFile>


Connector::Connector(const QString &new_ip) : QObject(0),
    socket(this)
{
    connect(&socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(onError(QAbstractSocket::SocketError)));
    connect(&socket, SIGNAL(readyRead()), this, SLOT(onRead()));
    buf[0] = 0;
    ip = new_ip;
    service = SERVER_SERVICE;
}

int Connector::connectToServer (const QString &username)
{
    socket.connectToHost(ip, service);
    socket.waitForConnected(2000);
    if (sendMessage(username) > 0)
    {
        emit connectionEstablished();
        return 0;
    }
    return -1;
}
int Connector::sendMessage(const QString &msg)
{
    Encoder encoder;
    short len = encoder.encode(msg, buf, MAX_MESSAGE_LENGTH);
    if (len < 0)
    {
        socket.disconnectFromHost();
        emit error(len);
        return len;
    }
    short written = socket.write(buf, len);
    if (written != len && written != -1)
    {
        socket.disconnectFromHost();
        emit error(PARTIAL_WRITE);
        return PARTIAL_WRITE;
    }
    return written;
}

void Connector::setIp(const QString &new_ip)
{
 ip = new_ip;
}

void Connector::onError(QAbstractSocket::SocketError error_)
{
    emit error(error_);
}

void Connector::onRead()
{
    Encoder encoder;
    if (socket.read(buf, MAX_MESSAGE_LENGTH) < 0)
        return;
    QString *decoded_msg = new QString;
    int error_ = encoder.decode(*decoded_msg, buf);
    if (error_ < 0)
    {
        emit error(error_);
        return;
    }
    emit incomingMessage(decoded_msg);
}

