import QtQuick 2.0
import QtQuick.Controls 2.1
import QtQuick.Controls.Material 2.1

ApplicationWindow  {
    id: gretter
    visible: true
    width: 1000
    height: 700
    Material.theme: Material.Dark
    Material.accent: Material.Purple
    opacity: 2


    Item{
        id:body
        anchors.centerIn: parent
        Column {
            id: infoform
            anchors.centerIn: parent

            Pane{
                id:userInfo
                width: 400
                height: 200
                Material.elevation: 10

                Text {
                    color: "#9E9E9E"
                    objectName: "usernameInputForm"
                    anchors.verticalCenter: image.verticalCenter
                    font.pixelSize: 32
                }

                Image {
                    id: image
                    objectName: "userImageInputForm"
                    source: "file:///home/nuno/greeter/assets/social/drawable-hdpi/ic_person_white_48dp.png"
                    property bool rounded: true
                    property bool adapt: true

                    width: 96
                    height: 96
                    anchors.right: parent.right
                    z:-999

                    layer.enabled: rounded
                    layer.effect: ShaderEffect {
                        property real adjustX: image.adapt ? Math.max(width / height, 1) : 1
                        property real adjustY: image.adapt ? Math.max(1 / (width / height), 1) : 1

                        fragmentShader: "
                #ifdef GL_ES
                    precision lowp float;
                #endif // GL_ES
                varying highp vec2 qt_TexCoord0;
                uniform highp float qt_Opacity;
                uniform lowp sampler2D source;
                uniform lowp float adjustX;
                uniform lowp float adjustY;

                void main(void) {
                    lowp float x, y;
                    x = (qt_TexCoord0.x - 0.5) * adjustX;
                    y = (qt_TexCoord0.y - 0.5) * adjustY;
                    float delta = adjustX != 1.0 ? fwidth(y) / 2.0 : fwidth(x) / 2.0;
                    gl_FragColor = texture2D(source, qt_TexCoord0).rgba
                        * step(x * x + y * y, 0.25)
                        * smoothstep((x * x + y * y) , 0.25 + delta, 0.25)
                        * qt_Opacity;
                }"
                    }
                }

                PasswordFormComponent{
                    id:textBox
                    widgetWidth: parent.width
                    widgetHeight: 100
                    anchors.bottom: parent.bottom
                }

                Item{
                    id: arrows
                    objectName: "arrowKeysInput"
                    signal pushedRight()
                    signal pushedLeft()

                    anchors.top: textBox.bottom
                    anchors.centerIn: userInfo
                    Row{
                        spacing: 2
                        Button {
                            text: "<"
                            onClicked: arrows.pushedLeft()
                        }
                        Button {
                            text: ">"
                            onClicked: arrows.pushedRight()
                        }
                    }
                }
            }
        }
    }
}
