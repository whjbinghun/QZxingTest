#include "zxingqmltest.h"
#include "QZXing.h"
#include <QPixmap>

ZXingQmlTest::ZXingQmlTest(QObject *parent)
    : QObject(parent)
{

}

QString ZXingQmlTest::get_image_content(const QString &file)
{
    QString strQRCode = "";
    if (!file.isEmpty())
    {
        QPixmap pixmap( file );
        // 二维码解码
        QZXing *pDecoder = new QZXing(QZXing::DecoderFormat_MAXICODE);
        QImage image = pixmap.toImage();
        strQRCode = pDecoder->decodeImage( image );
    }

    return strQRCode;
}

void ZXingQmlTest::showQRCode(const QString &file)
{

}
