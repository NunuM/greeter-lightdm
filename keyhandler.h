#ifndef KEYHANDLER_H
#define KEYHANDLER_H

#include <QObject>
#include <QLightDM/UsersModel>

class keyhandler :  public QObject
{
    Q_OBJECT
public:
    keyhandler(QObject * password,
               QObject * username,
               QObject * userImage,
               QLightDM::UsersModel * users,
               int m_current,
               int m_totalUsers);

signals:

public slots:
    void pushedRight();
    void pushedLeft();

private:
    QObject * m_password;
    QObject * m_username;
    QObject * m_userImage;
    QLightDM::UsersModel m_users;
    int m_current;
    int m_totalUsers;

    void nextUser();
};

#endif // KEYHANDLER_H
