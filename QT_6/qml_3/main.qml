import QtQuick
import QtQuick.Controls 2.15

Window {
    width: 300
    height: 200
    visible: true
    title: qsTr("Hello ПАДЛА!")

    Text {
        id: displayText
        anchors.centerIn: parent
        text: "<b>nnnnnnnn\n</b>"
        font.pixelSize: 36
        color: "red"
    }

    Text {
        text: "<p><b>>>>>></b></p>"
        font.pixelSize: 26
        color: "blue"
    }

}
