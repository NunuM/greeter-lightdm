#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "passwordinput.h"
#include <QLightDM/Greeter>
#include <QQuickStyle>
#include <QLightDM/Power>
#include <QLightDM/UsersModel>

int main(int argc, char *argv[])
{

    PasswordInput myClass;

    QQuickStyle::setStyle("Material");

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    QObject * myObject = engine.rootObjects().value(0)->findChild<QObject*>("passwordForm");
    QObject * usernameObj = engine.rootObjects().value(0)->findChild<QObject*>("username");

    QLightDM::UsersModel pr;

    auto e = pr.data(pr.index(0,0), QLightDM::UsersModel::NameRole);

    auto hello = e.toString().toUpper();

    QVariant v(hello);

    usernameObj->setProperty("text",v);

     auto ee = pr.data(pr.index(0,0), QLightDM::UsersModel::ImagePathRole);

    qDebug() << "---" << ee.toString();

    QObject::connect(myObject,SIGNAL(validatePassword(QString)), &myClass, SLOT(cppSlot(QString)));

    return app.exec();
}
