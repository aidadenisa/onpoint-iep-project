#-------------------------------------------------
#
# Project created by QtCreator 2017-10-11T16:44:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = server
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    bcm2835_stub.cpp \
    pin.cpp \
    pwm.cpp \
    serial.cpp \
    spi.cpp

HEADERS  += mainwindow.h \
    bcm2835.h \
    pin.h \
    pwm.h \
    serial.h \
    spi.h

FORMS    += mainwindow.ui
