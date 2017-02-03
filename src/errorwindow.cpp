#include "include/errorwindow.h"
#include "include/const.h"
#include "ui_errorwindow.h"

ErrorWindow::ErrorWindow(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::ErrorWindow)
{
  ui->setupUi(this);
  ui->okButton->setDefault(true);
  setModal(true);
  setWindowTitle("Error!");
}


void ErrorWindow::onError(QAbstractSocket::SocketError error_)
{
  QString errorMsg = QString::number(error_);
  ui->errorMessage->setText(errorMsg);
  exec();
  emit error(error_);
}

void ErrorWindow::onError(QString* errorMsg)
{
  ui->errorMessage->setText(*errorMsg);
  exec();
  delete errorMsg;
  emit error(QAbstractSocket::QAbstractSocket::ConnectionRefusedError);
}

ErrorWindow::~ErrorWindow()
{
  delete ui;
}
