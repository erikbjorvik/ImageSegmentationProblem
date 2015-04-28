#-------------------------------------------------
#
# Project created by QtCreator 2015-04-29T01:11:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = practical2_qt
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
INCLUDEPATH += "/usr/local/include"
LIBS += -L"/usr/local/lib/" -lglpk
