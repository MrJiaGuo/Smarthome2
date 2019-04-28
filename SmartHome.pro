#-------------------------------------------------
#
# Project created by QtCreator 2019-04-26T14:53:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SmartHome
TEMPLATE = app


SOURCES += main.cpp\
        smarthomemainwindow.cpp \
    api_v4l2.cpp \
    camera.cpp \
    adcbeep.cpp \
    adcqthread.cpp \
    common.c \
    sr04qthread.cpp \
    login.cpp \
    irqthread.cpp

HEADERS  += smarthomemainwindow.h \
    api_v4l2.h \
    camera.h \
    adcbeep.h \
    adcqthread.h \
    inc/common.h \
    sr04qthread.h \
    login.h \
    irqthread.h

FORMS    += smarthomemainwindow.ui \
    camera.ui \
    adcbeep.ui \
    login.ui
