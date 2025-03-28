import QtQuick 6.4
import QtQuick.Controls 6.4

Window {
    id: myWindow
    width: 450
    height: 300
    visible: true
    title: qsTr("Hello Андрей!")
    property int myduration: 1000 // скорость

    Item {
        id: item1
        width: 300
        height: 150

        Rectangle {
            id: img
            color: "yellow"
            x: 10
            y: 0
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

    // Цикл перемещения прямоугольника img
    SequentialAnimation{
        running: true
        loops: Animation.Infinite

        // вниз вправо
        PropertyAnimation {
            target: img
            properties: "x,y"
            from: 0
            to: myWindow.height - img.height
            duration: myduration
            easing.type: Easing.OutExpo
        }
        // вверх влево
        PropertyAnimation {
            target: img
            properties: "x,y"
            from: myWindow.height - img.height
            to: 0
            duration: myduration
            easing.type: Easing.OutExpo
        }
        // только вниз
        PropertyAnimation {
            target: img
            properties: "y"
            from: 0
            to: myWindow.height - img.height
            duration: myduration
            easing.type: Easing.OutExpo
        }
        // только вверх
        PropertyAnimation {
            target: img
            properties: "y"
            from: myWindow.height - img.height
            to: 0
            duration: myduration
            easing.type: Easing.OutExpo
        }

    }
}
