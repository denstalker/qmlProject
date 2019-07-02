import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3



Window {
    id: appWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello")


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
        width: parent.width
        currentIndex: tabBar.currentIndex
        Item {
            id: homeTab
            RangeSlider {
                id: rangeSlider
                y: 416
                anchors.horizontalCenter: parent.horizontalCenter
                orientation: Qt.Horizontal
                first.value: 0.25
                second.value: 0.75
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
    D{i:2;anchors_x:22;anchors_y:92}D{i:3;anchors_x:206}D{i:1;anchors_height:242;anchors_width:382;anchors_x:82;anchors_y:142}
D{i:4;anchors_x:326;anchors_y:82}D{i:11;anchors_height:270;anchors_width:280;anchors_x:46;anchors_y:200}
}
 ##^##*/
