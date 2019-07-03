import QtQuick 2.0


Rectangle
{
    width: viewId.width
    height: 30
    MouseArea
    {
        anchors.fill: row
        onClicked: {
            console.log("clickww")


        }



    }
    Row {
        id : row
        Text { text: name + iwd}
    }
}




