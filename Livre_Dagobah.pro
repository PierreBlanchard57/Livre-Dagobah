#-------------------------------------------------
#
# Project created by QtCreator 2025-12-24T15:16:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Livre_Dagobah
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    page.cpp \
    titlepage.cpp \
    endpage.cpp \
    luketrainpage.cpp

HEADERS  += mainwindow.h \
    page.h \
    titlepage.h \
    endpage.h \
    luketrainpage.h

FORMS    += mainwindow.ui \
    titlepage.ui \
    endpage.ui \
    luketrainpage.ui
