#include "errorwindow.h"
#include "const.h"
#include "ui_errorwindow.h"

ErrorWindow::ErrorWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ErrorWindow)
{
    ui->setupUi(this);
}


void ErrorWindow::onError(QAbstractSocket::SocketError error_)
{
    QString errorMsg = QString::number(error_);
    ui->errorMessage->setText(errorMsg);
    ui->okButton->setDefault(true);
    setModal(true);
    exec();
    emit error(error_);
}
void ErrorWindow::onError(int error)
{
    QString errorMsg = QString::number(error);
    ui->errorMessage->setText(errorMsg);
    ui->okButton->setDefault(true);
    setModal(true);
    exec();
}

ErrorWindow::~ErrorWindow()
{
    delete ui;
}
