#include "zxingtest.h"
#include "ui_zxingtest.h"
#include <QFileDialog>
#include "QZXing.h"
#include <QString>
#include <QImage>
#include <QDebug>

ZXingTest::ZXingTest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ZXingTest)
{
    ui->setupUi(this);

    init_connect();
}

ZXingTest::~ZXingTest()
{
    delete ui;
}

void ZXingTest::slot_select_image()
{
    QFileDialog *p_file_dialog = new QFileDialog( this );
    p_file_dialog->setFileMode(QFileDialog::AnyFile);
    p_file_dialog->setNameFilter(tr("Images (*.png *.xpm *.jpg)"));

    if( QDialog::Accepted == p_file_dialog->exec() ) {
        QStringList strList_image_path = p_file_dialog->selectedFiles();
        QString str_image_path = strList_image_path.length()>= 1?strList_image_path[0]:"";
        showQRCode( str_image_path );

        qDebug()<<"ZXingTest::slot_select_image"<<str_image_path;
    }

    if( p_file_dialog ) {
        delete p_file_dialog;
        p_file_dialog = NULL;
    }
}

void ZXingTest::init_connect()
{
    connect( ui->id_btn_select, SIGNAL(clicked()), this, SLOT( slot_select_image() ) );
}

void ZXingTest::showQRCode(const QString &file)
{
    if (!file.isEmpty())
    {
        QPixmap pixmap(file);
        ui->id_qr_image->setPixmap(QPixmap(file));
        ui->id_image_path->setText(file);

        // 二维码解码
        QZXing *pDecoder = new QZXing(QZXing::DecoderFormat_MAXICODE);
        QImage image = pixmap.toImage();
        QString strQRCode = pDecoder->decodeImage( image );

        if (!strQRCode.isEmpty())
        {
            //ui->id_text_info->setTextColor(QColor(230, 230, 230));
            ui->id_text_info->setText(strQRCode);
        }
        else
        {
            ui->id_text_info->setTextColor(Qt::red);
            ui->id_text_info->setText(QString::fromLocal8Bit("识别二维码信息失败！"));
        }
    }
}
