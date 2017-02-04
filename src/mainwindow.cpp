#include "include/mainwindow.h"
#include "include/connector.h"
#include "include/errorwindow.h"
#include "include/const.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Turtle Chat");
    ui->connectButton->setDefault(true);
    ui->chatOutput->setDisabled(true);
    ui->sendButton->setDisabled(true);
    connect(&connector, SIGNAL(incomingMessage(QString*)), this, SLOT(recvMessage(QString*)));
    connect(&connector, SIGNAL(connectionEstablished()), this, SLOT(startChat()));
    connect(&connector, SIGNAL(error(QAbstractSocket::SocketError)), &eWindow, SLOT(onError(QAbstractSocket::SocketError)));
    connect(&connector, SIGNAL(error(QString*)), &eWindow, SLOT(onError(QString*)));
    connect(&eWindow, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(onError(QAbstractSocket::SocketError)));
    connect(ui->messageBox, SIGNAL(returnPressed()), this, SLOT(sendMessage()));
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::connectToServer()
{
  QString ip;
  ip = ui->connectEdit->text();
  connector.setIp(ip);

  if (connector.connectToServer (ui->nickEdit->text()))
    {
      toInitState();
      return;
    }
      ;

  ui->connectButton->setDisabled(true);

}

void MainWindow::startChat()
{
  ui->nickEdit->setDisabled(true);
    ui->connectButton->setDisabled(true);
    ui->connectEdit->setText("Connected!");
    ui->connectEdit->setDisabled(true);
    ui->sendButton->setEnabled(true);
    ui->chatOutput->setEnabled(true);
    ui->messageBox->setEnabled(true);
}

void MainWindow::sendMessage()
{
    connector.sendMessage(ui->messageBox->text());
    ui->messageBox->clear();
}

void MainWindow::recvMessage(QString *msg)
{
    ui->chatOutput->append(*msg);
    delete msg;
}

void MainWindow::onError(QAbstractSocket::SocketError error_)
{
  toInitState();
}

void MainWindow::onError(QString *errorMsg)
{
  toInitState();
}

void MainWindow::toInitState()
{
    ui->nickEdit->setEnabled(true);
    ui->connectEdit->setEnabled(true);
    ui->connectEdit->setText(connector.ip);
    ui->connectButton->setEnabled(true);
    ui->chatOutput->setDisabled(true);
    ui->sendButton->setDisabled(true);
    ui->messageBox->setDisabled(true);
    connector.errorEmited = false;
}
