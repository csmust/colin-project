#-------------------------------------------------
#
# Project created by QtCreator 2023-04-08T19:36:32
#
#-------------------------------------------------

QT       += core gui
CONFIG   += c++11
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
#QMAKE_CXXFLAGS += -Werror=return-type
#QMAKE_CXXFLAGS_RELEASE = $$QMAKE_CFLAGS_RELEASE_WITH_DEBUGINFO
#QMAKE_LFLAGS_RELEASE = $$QMAKE_LFLAGS_RELEASE_WITH_DEBUGINFO
include(./netapi/netapi.pri)
INCLUDEPATH +=./netapi/

include(./md5/md5.pri)
INCLUDEPATH +=./md5/

TARGET = NetDisk
TEMPLATE = app


SOURCES += main.cpp\
    logindialog.cpp \
        maindialog.cpp \
    ckernel.cpp \
    mytablewidgetitem.cpp

HEADERS  += maindialog.h \
    ckernel.h \
    common.h \
    logindialog.h \
    mytablewidgetitem.h

FORMS    += maindialog.ui \
    logindialog.ui

RESOURCES += \
    resource.qrc
