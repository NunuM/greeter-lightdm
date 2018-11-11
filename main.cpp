#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>

#include <QLightDM/Greeter>
#include <QLightDM/Power>
#include <QLightDM/UsersModel>

#include "passwordinput.h"
#include "usernameinput.h"
#include "authenticatormanager.h"
#include "keyhandler.h"

#define MZ_PASSWORD_INPUT "passwordInputForm"
#define MZ_USERNAME_INPUT "usernameInputForm"
#define MZ_USER_IMAGE_INPUT "userImageInputForm"
#define MZ_ARROW_KEYS_INPUT "arrowKeysInput"


int main(int argc, char *argv[])
{
    QLightDM::Greeter greeter;
    QLightDM::UsersModel users;
    int currentUser = 0;
    const int totalUsers = users.rowCount(QModelIndex());

    PasswordInput passwordInput;
    UsernameInput usernameInput;
    AuthenticatorManager authManager(greeter,passwordInput,usernameInput);

    QQuickStyle::setStyle("Material");
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    QObject * passwordInputObject = engine.rootObjects().value(0)->findChild<QObject*>(MZ_PASSWORD_INPUT);
    QObject * usernameInputObject = engine.rootObjects().value(0)->findChild<QObject*>(MZ_USERNAME_INPUT);
    QObject * userImageObject = engine.rootObjects().value(0)->findChild<QObject*>(MZ_USER_IMAGE_INPUT);
    QObject * arrowKeysdObject = engine.rootObjects().value(0)->findChild<QObject*>(MZ_ARROW_KEYS_INPUT);

    keyhandler key(passwordInputObject,usernameInputObject,userImageObject,&users,currentUser,totalUsers);

    QObject::connect(passwordInputObject,SIGNAL(setPassword(QString)), &passwordInput, SLOT(setPassword(QString)));
    QObject::connect(arrowKeysdObject, SIGNAL(pushedRight()), &key, SLOT(pushedRight()));
    QObject::connect(arrowKeysdObject, SIGNAL(pushedLeft()), &key, SLOT(pushedLeft()));

    return app.exec();
}
