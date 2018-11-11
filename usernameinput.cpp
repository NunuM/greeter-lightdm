#include "usernameinput.h"

/**
 * @brief UsernameInput::UsernameInput
 */
UsernameInput::UsernameInput()
{
    this->m_username = QString();
}

/**
 * @brief UsernameInput::getUsername
 * @return QString
 */
QString UsernameInput::getUsername(){
    return this->m_username;
}

/**
 * @brief UsernameInput::setUsername
 * @param username QString
 */
void UsernameInput::setUsername(const QString & username){
    this->m_username = username;
}
