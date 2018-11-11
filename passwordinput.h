#ifndef PASSWORDINPUT_H
#define PASSWORDINPUT_H

#include <QObject>
#include <QQuickItem>
#include <QString>

class PasswordInput : public QObject
{
    Q_OBJECT
public:
    PasswordInput();
signals:

public slots:
    void setPassword(const QString &password);
    QString getPassword();
private:
    QString m_password;
};

#endif // PASSWORDINPUT_H
