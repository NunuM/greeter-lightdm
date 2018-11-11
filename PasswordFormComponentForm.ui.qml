import QtQuick 2.0
import QtQuick.Controls 2.1
import QtQuick.Controls.Material 2.1

Pane{
    width: passwordInputComponent.widgetWidth
    height: passwordInputComponent.widgetHeight

    TextField {
        id: passwordInputForm
        objectName: "passwordInputForm"
        width: parent.width
        anchors.centerIn: parent
        placeholderText: qsTr("Password")
        echoMode: TextInput.Password
        signal setPassword(string password)

        Connections {
            onAccepted: passwordInputForm.setPassword(passwordInputForm.text)
        }
    }
}
