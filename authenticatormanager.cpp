#include "authenticatormanager.h"


/**
 * @brief AuthenticatorManager::AuthenticatorManager
 * @param greeter
 * @param password
 * @param username
 */
AuthenticatorManager::AuthenticatorManager(QLightDM::Greeter & greeter,
                                           PasswordInput & password,
                                           UsernameInput & username)
    : m_greeter(greeter), m_password(password), m_username(username)
{

}

/**
 * @brief AuthenticatorManager::authenticate
 * @return
 */
bool AuthenticatorManager::authenticate()
{
    auto username =  m_username.getUsername();

    qDebug() << "Username:" << username;

    m_greeter.authenticate(username);

    return true;
}
