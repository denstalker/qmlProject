import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

import "functions.js" as MyFunctions
import com.denis.port 1.0




Window {
    id: appWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello")


    Port
    {

        id: port

        onNumberChanged:
        {
            console.log("Port") //Сигнал описаный в C++
            text1.text = number

        }
    }




    ListModel
    {
        id: comPortListModel
        ListElement
        {
            name: "COM1"
        }
        ListElement
        {
            name: "COM2"
        }
    }


    TabBar {
        id: tabBar
        anchors.fill: parent

        TabButton {
            id: tabButton
            width: 150
            height: 20
            text: qsTr("Управление")
            anchors.left: parent.left
            anchors.leftMargin: 2
            anchors.top: parent.top
            anchors.topMargin: 2


        }

        TabButton {
            id: tabButton1
            width: 150
            height: 20
            text: qsTr("Настройки")
            anchors.left: tabButton.right
            anchors.leftMargin: 2
            anchors.top: parent.top
            anchors.topMargin: 2
        }
    }
    StackLayout {
        anchors.fill: parent
        currentIndex: tabBar.currentIndex
        Item {
            id: homeTab
            RangeSlider {
                id: rangeSlider
                y: 416
                height: 40
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 20
                anchors.right: parent.right
                anchors.rightMargin: 40
                anchors.left: parent.left
                anchors.leftMargin: 40
                orientation: Qt.Horizontal
                first.value: 0.25
                second.value: 0.75
            }
            Text {
                id: text1
                width: 108
                height: 73
                text: qsTr("000")
                anchors.top: parent.top
                anchors.topMargin: 47
                anchors.left: parent.left
                anchors.leftMargin: 18
                font.pointSize: 36
            }

            Button {
                id: buttonReset
                text: qsTr("Сброс")
                anchors.top: parent.top
                anchors.topMargin: 64
                anchors.left: text1.right
                anchors.leftMargin: 6
                onClicked: port.number++
            }

        }

        Item {
            id: optionsTab
            Rectangle
            {

                width: 106
                height: 270
                anchors.top: parent.top
                anchors.topMargin: 38
                anchors.left: parent.left
                anchors.leftMargin: 8
                ListView
                {

                    id: viewId
                    width: 180; height: 200
                    anchors.fill: parent
                    model: comPortListModel
                    delegate: ComPortDelegate {}

                }
            }

        }


    }



}




























/*##^## Designer {
    D{i:1;anchors_height:242;anchors_width:382;anchors_x:82;anchors_y:142}D{i:3;anchors_x:206}
D{i:4;anchors_x:326;anchors_y:82}D{i:2;anchors_x:22;anchors_y:92}D{i:11;anchors_height:270;anchors_width:280;anchors_x:18;anchors_y:47}
D{i:12;anchors_x:108;anchors_y:64}D{i:8;anchors_width:640}
}
 ##^##*/
