import QtQuick
import QtLocation
import QtPositioning
import QtQuick.Controls
import QtMultimedia 5.15
import QtMultimedia
import QtQuick.Dialogs

Rectangle {
    id:rectan
    width:470
    height: 80

    Button {
        width: 60
        height: 60
        visible: true
        id: testButton
        x:30
        y:10
        //radius: 20
        //background: "transparent"
        //text: qsTr("testButton")
        //icon.color: "transparent"
        icon.source: "qrc:/images/pla.svg"
        background: Rectangle {
            color: "#494447"
            border.width: 1.5
            border.color: "#494447"
            radius: 20

        }


    }
   
    Button {
        width: 60
        height: 60
        visible: true
        id: testButton_1
        x:100
        y:10
        //background: "transparent"
        //text: qsTr("testButton")
        icon.color: "transparent"
        icon.source: "qrc:/images/rrr.svg"
            background: Rectangle {
                color: "#494447"
                border.width: 1.5
                border.color: "#494447"
                radius: 20
            }

    }
    Button {
        width: 60
        height: 60
        visible: true
        id: testButton_2
        x:170
        y:10
        //background: "transparent"
        //text: qsTr("testButton")
        icon.color: "transparent"
        icon.source: "qrc:/images/locky.svg"
            background: Rectangle {
                color: "#494447"
                border.width: 1.5
                border.color: "#494447"
                radius: 20
            }

    }
    Button {
        width: 60
        height: 60
        visible: true
        id: testButton_3
        x:240
        y:10
        //background: "transparent"
        //text: qsTr("testButton")
        icon.color: "transparent"
        icon.source: "qrc:/images/dd.svg"
            background: Rectangle {
                color: "#494447"
                border.width: 1.5
                border.color: "#494447"
                radius: 20
            }

    }

    Button {
        width: 60
        height: 60
        visible: true
        id: testButton_4
        x:310
        y:10
        //background: "transparent"
        //text: qsTr("testButton")
        icon.color: "transparent"
        icon.source: "qrc:/images/home.png"
            background: Rectangle {
                color: "#494447"
                border.width: 1.5
                border.color: "#494447"
                radius: 20
            }



    }
    Button {
        width: 60
        height: 60
        visible: true
        id: testButton_5
        x:380
        y:10
        //background: "transparent"
        //text: qsTr("testButton")
        icon.color: "transparent"
        icon.source: "qrc:/images/off.svg"
            background: Rectangle {
                color: "#494447"
                border.width: 1.5
                border.color: "#494447"
                radius: 20
            }
    }


}
