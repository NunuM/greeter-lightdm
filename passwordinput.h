#ifndef PASSWORDINPUT_H
#define PASSWORDINPUT_H

#include <QObject>
#include <QQuickItem>

class PasswordInput : public QObject
{
    Q_OBJECT
public:

signals:

public slots:
    void cppSlot(const QString &msg);
};

#endif // PASSWORDINPUT_H
