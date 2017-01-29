#-------------------------------------------------
#
# Project created by QtCreator 2017-01-25T13:01:33
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Ver4
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    connector.cpp \
    errorwindow.cpp \
    encoder.cpp

HEADERS  += mainwindow.h \
    connector.h \
    errorwindow.h \
    const.h \
    encoder.h

FORMS    += mainwindow.ui \
    errorwindow.ui
