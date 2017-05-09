#include <QApplication>
#include <QQmlApplicationEngine>
#include "zxingqmltest.h"
#include <QQuickView>
#include <QDesktopWidget>
#include <QQmlContext>

//1. add headers
#include <QtPlugin>
#include <QtQml>



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;


    engine.rootContext()->setContextProperty( "zxing_qml", new ZXingQmlTest );

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

