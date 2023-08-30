#-------------------------------------------------
#
# Project created by QtCreator 2023-04-08T19:36:32
#
#-------------------------------------------------

QT       += core gui
CONFIG   += c++11
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

include(./netapi/netapi.pri)
INCLUDEPATH +=./netapi/

include(./md5/md5.pri)
INCLUDEPATH +=./md5/

TARGET = NetDisk
TEMPLATE = app


SOURCES += main.cpp\
    logindialog.cpp \
        maindialog.cpp \
    ckernel.cpp

HEADERS  += maindialog.h \
    ckernel.h \
    logindialog.h

FORMS    += maindialog.ui \
    logindialog.ui

RESOURCES += \
    resource.qrc
