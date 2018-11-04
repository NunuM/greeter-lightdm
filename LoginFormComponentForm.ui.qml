import QtQuick 2.0
import QtQuick.Controls 2.1
import QtQuick.Controls.Material 2.1

Pane{
    width: loginHolder.widgetWidth
    height: loginHolder.widgetHeight

    TextField {
        width: parent.width
        anchors.centerIn: parent
        placeholderText: qsTr("Password")
        echoMode: TextInput.Password
    }
}
