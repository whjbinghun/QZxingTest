#include "zxingtest.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ZXingTest w;
    w.show();

    return a.exec();
}
