import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    color: "#333333"

    ClientList {
        id: clientList
        anchors.fill: parent
    }

    Switch {
        id: switchConnect
        anchors.top: parent.top
        anchors.topMargin: 20
        anchors.right: parent.right
        anchors.rightMargin: 20

        onPressed: {
            if(checked)
                telnetManager.stopVPNServer()
            else
                telnetManager.startVPNServer()
        }
    }
}
