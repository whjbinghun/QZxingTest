#include "zxingqmltest.h"
#include "QZXing.h"
#include <QPixmap>

ZXingQmlTest::ZXingQmlTest(QObject *parent)
    : QObject(parent)
{

}

QString ZXingQmlTest::get_image_content(const QString &file)
{
    QStringList str_list = file.split( "file:///" );
    if( str_list.length() != 2 ) return "";

    QString strQRCode = str_list[1];
    if (!strQRCode.isEmpty())
    {
        QPixmap pixmap( strQRCode );
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
