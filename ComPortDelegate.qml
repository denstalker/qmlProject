import QtQuick 2.0


MouseArea
{
    anchors.fill: row
    onClicked: {
        console.log("click")

    }

    Column {
        id : row
        Text { text: '<b>Name:</b> ' + name }
        //                Text { text: '<b>Number:</b> ' + number }
    }

}




