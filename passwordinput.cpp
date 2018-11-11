#include "passwordinput.h"

/**
 * @brief PasswordInput::PasswordInput
 */
PasswordInput::PasswordInput(){
    this->m_password = QString();
}

/**
 * @brief PasswordInput::setPassword
 * @param password
 */
void PasswordInput::setPassword(const QString &password){
    qDebug() << "Property value:" << password;
    this->m_password = password;
}

/**
 * @brief PasswordInput::getPassword
 * @return QString
 */
QString PasswordInput::getPassword()
{
    return this->m_password;
}
