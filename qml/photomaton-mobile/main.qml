import QtQuick 2.1
import QtQuick.Controls 1.1
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.1
import org.rlamarche 1.0

Rectangle {
    id: root
    width: 1024; height: 600
    color: "black"
    visible: true

    Rectangle {
        id: cameraSelector
        color: "blue"
        height: row.height * 2
        width: parent.width
        anchors.top: parent.top

        ColumnLayout {
            width: parent.width
            height: parent.height

            Row {
                id: row
                anchors.centerIn: parent

                spacing: 5
                Button {
                    text: "Refresh"
                    onClicked: application.autodetect();
                }
                Label {
                    anchors.verticalCenter: parent.verticalCenter
                    text: "Detected cameras:"
                    color: "white"
                }

                ComboBox {
                    width: parent.parent.width / 2
                    model: application.cameraListModel
                    textRole: "display"
                    onActivated: {
                        cameraSelector.visible = false;
                        application.cameraSelected(index)
                    }
                }
            }
        }
    }

    Liveview {
        id: liveview
        width: parent.width
        height: parent.height - cameraSelector.height
        anchors.top: cameraSelector.bottom

        Connections {
            target: application
            onPreviewReady: liveview.updateImage(image)
        }
    }

    Connections {
        target: application
        onApplicationError: {
            var component = Qt.createComponent("error.qml");
            var errorMessage = component.createObject(root, { message: error });
        }
    }
}
