#ifndef ZXINGQMLTEST_H
#define ZXINGQMLTEST_H

#include <QObject>

class ZXingQmlTest : public QObject
{
    Q_OBJECT

public:
    explicit ZXingQmlTest(QObject *parent = 0);
    Q_INVOKABLE QString get_image_content( const QString &file );
private:
    void showQRCode(const QString &file);
};

#endif // ZXINGQMLTEST_H
