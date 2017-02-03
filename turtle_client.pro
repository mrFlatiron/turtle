#-------------------------------------------------
#
# Project created by QtCreator 2017-01-25T13:01:33
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Ver4
TEMPLATE = app


SOURCES += src/main.cpp\
        src/mainwindow.cpp \
    src/connector.cpp \
    src/errorwindow.cpp \
    src/encoder.cpp

HEADERS  += include/mainwindow.h \
    include/connector.h \
    include/errorwindow.h \
    include/const.h \
    include/encoder.h

FORMS    += ui/mainwindow.ui \
    ui/errorwindow.ui
