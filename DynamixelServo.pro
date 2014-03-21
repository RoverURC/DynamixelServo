#-------------------------------------------------
#
# Project created by QtCreator 2014-03-19T22:44:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4) {
    QT       += widgets serialport
} else {
    include($$QTSERIALPORT_PROJECT_ROOT/src/serialport/qt4support/serialport.prf)
}

TARGET = DynamixelServo
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dynamixelservo.cpp

HEADERS  += mainwindow.h \
    dynamixelservo.h

FORMS    += mainwindow.ui
