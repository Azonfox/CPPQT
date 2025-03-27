import QtQuick 6.4
import QtQuick.Controls 6.4

Window {
    width: 350
    height: 200
    visible: true
    title: qsTr("Hello Андрей!")

    Item {
        id: item1
        width: 300
        height: 150
        Rectangle {
            color: "yellow"
            x: 100
            y: 50
            width: 170
            height: 100
            border.color: "blue"
            border.width: 10
            radius: 25
            smooth: true
        }
    }

    Text {
        id: displayText
        anchors.centerIn: parent
        text: "<b>Текст красный</b>"
        font.pixelSize: 36
        color: "red"
    }

    Text {
        text: "<p><b>Верхняя строка</b></p>"
        font.pixelSize: 22
        color: "green"
    }

    Button {
      //  x: 233
      //  y: 164
        width: 100
        height: 30
        text: "Выход"
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.margins: 10
        onClicked: Qt.quit();
    }

}
