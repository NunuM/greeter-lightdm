#ifndef AUTHENTICATORMANAGER_H
#define AUTHENTICATORMANAGER_H

#include <QString>
#include <QLightDM/Greeter>
#include "passwordinput.h"
#include "usernameinput.h"

class AuthenticatorManager
{
public:
    AuthenticatorManager(QLightDM::Greeter& greeter,
                         PasswordInput & password,
                         UsernameInput & m_username);

    bool authenticate();
private:
    QLightDM::Greeter& m_greeter;
    PasswordInput & m_password;
    UsernameInput & m_username;
};

#endif // AUTHENTICATORMANAGER_H
