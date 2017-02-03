#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "errorwindow.h"
#include "connector.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void toInitState();
    ~MainWindow();


public slots:
    void recvMessage(QString* msg);
    void startChat();


private slots:
    void connectToServer();
    void sendMessage();
    void onError(QAbstractSocket::SocketError);
    void onError(QString *errorMsg);

private:
    Ui::MainWindow *ui;
    Connector connector;
    ErrorWindow eWindow;
};

#endif // MAINWINDOW_H
