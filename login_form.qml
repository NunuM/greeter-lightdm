import QtQuick 2.0

Item {
    id: password_form
    Rectangle{
        TextInput {
            id: passwordInput
            x: 171
            y: 166
            width: 80
            height: 20
            text: qsTr("Text Input")
            font.pixelSize: 12
        }
    }
}
