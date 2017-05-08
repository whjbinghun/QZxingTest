#ifndef ZXINGTEST_H
#define ZXINGTEST_H

#include <QWidget>

namespace Ui {
class ZXingTest;
}

class ZXingTest : public QWidget
{
    Q_OBJECT

public:
    explicit ZXingTest(QWidget *parent = 0);
    ~ZXingTest();

public slots:
    void slot_select_image();
private:
    void init_connect();

    void showQRCode( const QString &file );
private:
    Ui::ZXingTest *ui;
};

#endif // ZXINGTEST_H
