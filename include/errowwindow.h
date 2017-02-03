#ifndef ERROWWINDOW_H
#define ERROWWINDOW_H

#include <QDialog>

namespace Ui {
class ErrowWindow;
}

class ErrowWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ErrowWindow(QWidget *parent = 0);
    ~ErrowWindow();

private:
    Ui::ErrowWindow *ui;
};

#endif // ERROWWINDOW_H
