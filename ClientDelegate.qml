import QtQuick 2.0

Rectangle {
    id: root

    radius: width/2
    color: "#001920"

    Row {
        anchors.verticalCenter:
            parent.verticalCenter
        anchors.left: parent.left
        anchors.leftMargin: 10
        width: parent.width
        spacing: 25
        Text {
            font.family: "Calibri"
            font.pixelSize: 20
            text: client_ip
            color: "white"
        }
        Text {
            font.family: "Calibri"
            font.pixelSize: 20
            text: client_name
            color: "white"
        }
    }
}
