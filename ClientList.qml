import QtQuick 2.10
import QtQuick.Controls 2.10

Item {
    id: root

    ListView {
        id: listView
        width: parent.width/2
        height: contentHeight
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.top: parent.top
        anchors.topMargin: 10
        model: telnetManager.clientListModel
        spacing: 10
        delegate: ClientDelegate {
            width: listView.width
            height: 50
        }
    }
}
