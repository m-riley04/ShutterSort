/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/

import QtQuick 6.5
import QtQuick.Controls 6.5
import ShutterSort

Rectangle {
    id: rectangle
    width: Constants.width
    height: Constants.height

    color: Constants.backgroundColor

    Text {
        id: header
        y: 8
        width: 435
        height: 107
        text: qsTr("Shutter Sort")
        font.pointSize: 60
        anchors.horizontalCenterOffset: 1
        font.family: Constants.font.family
        anchors.topMargin: -199
        anchors.horizontalCenter: parent.horizontalCenter

        SequentialAnimation {
            id: animation

            ColorAnimation {
                id: colorAnimation1
                target: rectangle
                property: "color"
                to: "#2294c6"
                from: Constants.backgroundColor
            }

            ColorAnimation {
                id: colorAnimation2
                target: rectangle
                property: "color"
                to: Constants.backgroundColor
                from: "#2294c6"
            }
        }
    }

    Button {
        id: button
        x: 207
        y: 313
        width: 411
        height: 276
        text: qsTr("Sort by Value")
        font.pointSize: 40
    }

    Button {
        id: button1
        x: 207
        y: 651
        width: 411
        height: 276
        text: qsTr("Sort by Range(s)")
        font.pointSize: 40
    }
    states: [
        State {
            name: "clicked"

            PropertyChanges {
                target: header
                text: qsTr("Button Checked")
            }
        }
    ]
}
