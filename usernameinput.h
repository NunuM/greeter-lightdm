#ifndef USERNAMEINPUT_H
#define USERNAMEINPUT_H

#include <QString>

class UsernameInput
{
public:
    UsernameInput();
    void setUsername(const QString &username);
    QString getUsername();
private:
    QString m_username;
};

#endif // USERNAMEINPUT_H
