import QtQuick 2.5
import QtQuick.Window 2.12
import QtQuick.Controls 2.2
import io.qt.examples.backend 1.0

Window {
    id: root
    visible: true
    width: 640
    height: 480
    title: qsTr("Greatest Common Divisor")

    BackEnd {
        id: backend
    }

    SpinBox {
        x: 158
        y: 141
        width: 168
        height: 38
        font.pointSize: 20
        value: 1
        onValueModified: backend.number1 = value
    }

    SpinBox {
        x: 158
        y: 221
        width: 168
        height: 38
        font.pointSize: 20
        value: 1
        onValueModified: backend.number2 = value
    }

    Button {
        id: button
        x: 355; y: 221
        width: 67; height: 30

        text: "Click"
        onClicked: {
            backend.setGcd();
            rectangle.value = backend.gcd
        }
    }


    Rectangle {
        id: rectangle
        x: 171; y: 354
        width: 142; height: 60
        color: "#dfd3d3"
        property int value: 0

        Text {
            id: element
            x: 15
            y: 8
            width: 111
            height: 44

            text: rectangle.value.toString()
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 37


        }
    }

}
