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

            TextInput {
                id: text_image_path
                width: 200
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

            TextField {
                id: text_image_content
                width: 300
                height: 200
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
            /*imageViewer.source = file_dialog.fileUrl[0]
            var imageFile = new String( file_dialog.fileUrl[0] )
            imagePath.text = imageFile.slice(8)

            var str_image_content = zxing_qml.get_image_content(  file_dialog.fileUrl[0] )
            text_image_content.text = str_image_content;*/
        }
    }
}

