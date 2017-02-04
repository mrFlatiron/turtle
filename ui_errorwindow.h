/********************************************************************************
** Form generated from reading UI file 'errorwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ERRORWINDOW_H
#define UI_ERRORWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ErrorWindow
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *errorLabel;
    QTextBrowser *errorMessage;
    QPushButton *okButton;

    void setupUi(QDialog *ErrorWindow)
    {
        if (ErrorWindow->objectName().isEmpty())
            ErrorWindow->setObjectName(QStringLiteral("ErrorWindow"));
        ErrorWindow->resize(308, 300);
        layoutWidget = new QWidget(ErrorWindow);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 40, 258, 256));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        errorLabel = new QLabel(layoutWidget);
        errorLabel->setObjectName(QStringLiteral("errorLabel"));

        gridLayout->addWidget(errorLabel, 0, 0, 1, 1);

        errorMessage = new QTextBrowser(layoutWidget);
        errorMessage->setObjectName(QStringLiteral("errorMessage"));

        gridLayout->addWidget(errorMessage, 1, 0, 1, 2);

        okButton = new QPushButton(layoutWidget);
        okButton->setObjectName(QStringLiteral("okButton"));

        gridLayout->addWidget(okButton, 2, 1, 1, 1);


        retranslateUi(ErrorWindow);
        QObject::connect(okButton, SIGNAL(clicked()), ErrorWindow, SLOT(accept()));

        QMetaObject::connectSlotsByName(ErrorWindow);
    } // setupUi

    void retranslateUi(QDialog *ErrorWindow)
    {
        ErrorWindow->setWindowTitle(QApplication::translate("ErrorWindow", "Dialog", 0));
        errorLabel->setText(QApplication::translate("ErrorWindow", "Error Message:", 0));
        okButton->setText(QApplication::translate("ErrorWindow", "OK", 0));
    } // retranslateUi

};

namespace Ui {
    class ErrorWindow: public Ui_ErrorWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ERRORWINDOW_H
