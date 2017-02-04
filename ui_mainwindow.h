/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *nickLabel;
    QLineEdit *nickEdit;
    QHBoxLayout *horizontalLayout;
    QLabel *connectLabel;
    QLineEdit *connectEdit;
    QPushButton *connectButton;
    QTextBrowser *chatOutput;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *messageBox;
    QPushButton *sendButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(691, 430);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_3 = new QHBoxLayout(centralWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        nickLabel = new QLabel(centralWidget);
        nickLabel->setObjectName(QStringLiteral("nickLabel"));

        horizontalLayout_4->addWidget(nickLabel);

        nickEdit = new QLineEdit(centralWidget);
        nickEdit->setObjectName(QStringLiteral("nickEdit"));

        horizontalLayout_4->addWidget(nickEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        connectLabel = new QLabel(centralWidget);
        connectLabel->setObjectName(QStringLiteral("connectLabel"));

        horizontalLayout->addWidget(connectLabel);

        connectEdit = new QLineEdit(centralWidget);
        connectEdit->setObjectName(QStringLiteral("connectEdit"));
        connectEdit->setMaximumSize(QSize(16777215, 32));

        horizontalLayout->addWidget(connectEdit);

        connectButton = new QPushButton(centralWidget);
        connectButton->setObjectName(QStringLiteral("connectButton"));
        connectButton->setMaximumSize(QSize(16777215, 30));

        horizontalLayout->addWidget(connectButton);


        verticalLayout->addLayout(horizontalLayout);

        chatOutput = new QTextBrowser(centralWidget);
        chatOutput->setObjectName(QStringLiteral("chatOutput"));
        chatOutput->setMaximumSize(QSize(16777215, 700));

        verticalLayout->addWidget(chatOutput);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        messageBox = new QLineEdit(centralWidget);
        messageBox->setObjectName(QStringLiteral("messageBox"));

        horizontalLayout_2->addWidget(messageBox);

        sendButton = new QPushButton(centralWidget);
        sendButton->setObjectName(QStringLiteral("sendButton"));
        sendButton->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_2->addWidget(sendButton);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 691, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addSeparator();

        retranslateUi(MainWindow);
        QObject::connect(connectButton, SIGNAL(clicked()), MainWindow, SLOT(connectToServer()));
        QObject::connect(sendButton, SIGNAL(clicked()), MainWindow, SLOT(sendMessage()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        nickLabel->setText(QApplication::translate("MainWindow", "Username:", 0));
        nickEdit->setText(QApplication::translate("MainWindow", "NoName", 0));
        connectLabel->setText(QApplication::translate("MainWindow", "Server Ip:", 0));
        connectEdit->setText(QApplication::translate("MainWindow", "localhost", 0));
        connectButton->setText(QApplication::translate("MainWindow", "Connect", 0));
        sendButton->setText(QApplication::translate("MainWindow", "Send", 0));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
