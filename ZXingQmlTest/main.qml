import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import QtQuick.Controls 1.4

Window {
    visible: true
    width: 500
    height: 500

    Column {
        anchors.top: parent.top
        anchors.topMargin: 10
        anchors.left: parent.left
        anchors.leftMargin: 15
        anchors.right: parent.right
        anchors.rightMargin: 15
        spacing: 20
        Image {
            id: imageViewer
            anchors.horizontalCenter: parent.horizontalCenter
            width: 140
            height: 140
            source: ""
        }

        Row {
            spacing: 20
            Button {
                id: btn_import_image
                text: "导入图片"
                width: 80
                height: 30

                onClicked: {
                    file_dialog.visible = true
                }
            }

            Text {
                id: text_image_path
                //anchors.left: btn_import_image.left
                width: 100
                height: 30
            }
        }

        Row {
            spacing: 20
            Label {
                id: label_image_content
                text: "图片内容"
                width: 40
                height: 30
            }

            Text {
                id: text_image_content
                width: 300
                height: 200
                wrapMode: Text.WordWrap
            }
        }

    }

    FileDialog {
        id: file_dialog
        title: "请导入二维码图片"
        visible: false
        nameFilters: ["Image Files(*jpg *png)", "Bitmap File(*.bmp)","*(*.*)"]
        selectedNameFilter: "Image Files(*.jpg *.png *bmp)"
        selectMultiple: false
        onAccepted: {
            imageViewer.source = file_dialog.fileUrls[0]
            var imageFile = new String( file_dialog.fileUrls[0] )
            text_image_path.text = imageFile.slice(8)

            var str_image_content = zxing_qml.get_image_content(  file_dialog.fileUrls[0] )
            text_image_content.text = str_image_content;
        }
    }
}

