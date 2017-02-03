#ifndef ERRORWINDOW_H
#define ERRORWINDOW_H

#include <QDialog>
#include <QAbstractSocket>

namespace Ui {
class ErrorWindow;
}

class ErrorWindow : public QDialog
{
    Q_OBJECT

signals:
    void error(QAbstractSocket::SocketError);

public slots:
        void onError(QAbstractSocket::SocketError error);
        void onError(QString *errorMsg);

public:
    explicit ErrorWindow(QWidget *parent = 0);
    ~ErrorWindow();

private:
    Ui::ErrorWindow *ui;
};

#endif // ERRORWINDOW_H
