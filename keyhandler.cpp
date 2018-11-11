#include "keyhandler.h"

keyhandler::keyhandler(QObject * password,
                       QObject * username,
                       QObject * userImage,
                       QLightDM::UsersModel * users,
                       int current,
                       int totalUsers) :
    m_password(password),
    m_username(username),
    m_userImage(userImage),
    m_users(users),
    m_current(current),
    m_totalUsers(totalUsers)
{
    this->nextUser();
}


void keyhandler::nextUser()
{
    if(m_current >= m_totalUsers){
        m_current  = 0;
    }

    auto username = m_users.data(m_users.index(m_current,0), QLightDM::UsersModel::NameRole);
    auto image = m_users.data(m_users.index(m_current,0), QLightDM::UsersModel::ImagePathRole);


    m_username->setProperty("text",QVariant(username.toString().toUpper()));
    m_userImage->setProperty("source",QVariant("file://" + image.toString()));
    m_password->setProperty("text",QVariant(""));

    m_current = m_current + 1;

    if(m_current >= m_totalUsers){
        m_current = 0;
    }
}

void keyhandler::pushedLeft()
{
    if(m_current < 0){
        m_current  = m_totalUsers-1;
    }

    auto username = m_users.data(m_users.index(m_current,0), QLightDM::UsersModel::NameRole);
    auto image = m_users.data(m_users.index(m_current,0), QLightDM::UsersModel::ImagePathRole);

    m_username->setProperty("text",QVariant(username.toString().toUpper()));
    m_userImage->setProperty("source",QVariant("file://" + image.toString()));

    m_password->setProperty("text",QVariant(""));

    m_current = m_current - 1;

    if(m_current < 0){
        m_current  = m_totalUsers-1;
    }
}

void keyhandler::pushedRight()
{
    this->nextUser();
}
