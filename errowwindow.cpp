#include "errowwindow.h"
#include "ui_errowwindow.h"

ErrowWindow::ErrowWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ErrowWindow)
{
    ui->setupUi(this);
}

ErrorWindow::ErrorWindow()

ErrowWindow::~ErrowWindow()
{
    delete ui;
}
