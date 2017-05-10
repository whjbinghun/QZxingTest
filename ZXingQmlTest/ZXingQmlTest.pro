TEMPLATE = app

QT += qml quick widgets
CONFIG += c++11

SOURCES += main.cpp \
    zxingqmltest.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH = $QTDIR/qml


# Default rules for deployment.
include(deployment.pri)

macx: LIBS += -L$$PWD/Frameworks/ -lQZXing.1.0.0
win32: LIBS += -L$$PWD/lib/ -lQZXing2

INCLUDEPATH += $$PWD/Frameworks
DEPENDPATH += $$PWD/Frameworks

HEADERS += \
    zxingqmltest.h \
    QZXing_global.h \
    QZXing.h
