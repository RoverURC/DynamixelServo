#-------------------------------------------------
#
# Project created by QtCreator 2014-03-19T22:44:31
#
#-------------------------------------------------

QT       += core gui

TARGET = DynamixelServo
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dynamixelservo.cpp

HEADERS  += mainwindow.h \
    dynamixelservo.h

FORMS    += mainwindow.ui

include(/home/pi/ExtSerialPort/qextserialport.pri)
CONFIG += extserialport

