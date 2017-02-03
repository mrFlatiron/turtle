#include "include/connector.h"
#include <QFile>


Connector::Connector(const QString &new_ip) : QObject(0),
  socket(this)
{
  connect(&socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(onError(QAbstractSocket::SocketError)));
  connect(&socket, SIGNAL(readyRead()), this, SLOT(onRead()));
  buf[0] = 0;
  ip = new_ip;
  service = SERVER_SERVICE;
  errorEmited = false;
}

int Connector::connectToServer (const QString &username)
{
  socket.connectToHost(ip, service);
  socket.waitForConnected(2000);
  sendMessage(username);
  emit connectionEstablished();
}
int Connector::sendMessage(const QString &msg)
{
  Encoder encoder;

  if (msg.trimmed().isEmpty())
    return 0;
  QString *errorMsg = new QString;

  short len = encoder.encode(msg, buf, MAX_MESSAGE_LENGTH, *errorMsg);
  if (len < 0)
    {
      socket.disconnectFromHost();
      errorEmited = true;
      emit error(errorMsg);
      return len;
    }
  short written = socket.write(buf, len);
  if (written != len && written != -1)
    {
      *errorMsg = QString("Dont know how to handle partial write");
      socket.disconnectFromHost();
      errorEmited = true;
      emit error(errorMsg);
      return PARTIAL_WRITE;
    }
  delete errorMsg;
  return written;
}

void Connector::setIp(const QString &new_ip)
{
  ip = new_ip;
}

void Connector::onError(QAbstractSocket::SocketError error_)
{
  if (errorEmited)
    return;
  errorEmited = true;
  emit error(error_);
}

void Connector::onRead()
{
  Encoder encoder;
  if (socket.read(buf, MAX_MESSAGE_LENGTH) < 0)
    return;
  QString *decoded_msg = new QString;
  int error_ = encoder.decode(*decoded_msg, buf);
  if (error_)
    {
      errorEmited = true;
      emit error(decoded_msg);
      return;
    }
  emit incomingMessage(decoded_msg);
}

