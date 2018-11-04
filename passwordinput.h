#ifndef PASSWORDINPUT_H
#define PASSWORDINPUT_H

#include <QObject>
#include <QQuickItem>
#include <QWidget>

class PasswordInput : public QObject
{
    Q_OBJECT
public:
    explicit PasswordInput(QObject *parent = nullptr);

signals:

public slots:
};

#endif // PASSWORDINPUT_H