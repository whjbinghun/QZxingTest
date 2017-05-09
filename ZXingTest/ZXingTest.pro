#-------------------------------------------------
#
# Project created by QtCreator 2017-05-08T15:17:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ZXingTest
TEMPLATE = app



SOURCES += main.cpp\
        zxingtest.cpp

HEADERS  += zxingtest.h \
    QZXing.h \
    QZXing_global.h

FORMS    += zxingtest.ui

macx: LIBS += -L$$PWD/Frameworks/ -lQZXing.1.0.0

INCLUDEPATH += $$PWD/Frameworks
DEPENDPATH += $$PWD/Frameworks
