#-------------------------------------------------
#
# Project created by QtCreator 2025-12-24T15:16:10
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Livre_Dagobah
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    page.cpp \
    titlepage.cpp \
    endpage.cpp \
    luketrainpage.cpp \
    lukeduelpage.cpp \
    qtebutton.cpp \
    yodaliftpage.cpp \
    effectmanager.cpp \
    r2d2mudpage.cpp \
    rockobject.cpp

HEADERS  += mainwindow.h \
    page.h \
    titlepage.h \
    endpage.h \
    luketrainpage.h \
    lukeduelpage.h \
    qtebutton.h \
    yodaliftpage.h \
    effectmanager.h \
    r2d2mudpage.h \
    rockobject.h

FORMS    += mainwindow.ui \
    titlepage.ui \
    endpage.ui \
    luketrainpage.ui \
    lukeduelpage.ui \
    yodaliftpage.ui \
    r2d2mudpage.ui

RESOURCES +=

DISTFILES +=

win32: LIBS += -lshell32

win32:CONFIG(release, debug|release): LIBS += -L'C:/Program Files/Immersion Corporation/IFC23/lib/' -lIFC23
else:win32:CONFIG(debug, debug|release): LIBS += -L'C:/Program Files/Immersion Corporation/IFC23/lib/' -lIFC23d

INCLUDEPATH += 'C:/Program Files/Immersion Corporation/IFC23/inc'
DEPENDPATH += 'C:/Program Files/Immersion Corporation/IFC23/inc'
