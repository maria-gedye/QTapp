#ifndef USER_H
#define USER_H

#include <QObject>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QDir>

class User : public QObject      // user-defined class
{
    Q_OBJECT
    QString firstName, surname, email, password;
    bool IDverified;
    QString ID1, ID2;

public:
    explicit User(QObject *parent = nullptr);

    User(QString f, QString s, QString i1, QString i2) {    // constructor
        firstName = f;
        surname = s;
        ID1 = i1;
        ID2 = i2;
    }

 // getter functions:
    QString getName();

    void printInfo();

    bool getVerification();

    QString getID1();

    QString getID2();

 // setter functions:
    void setName(User* usr, int p);

    void setID(User* usr, QString i1, QString i2, bool v, QString n);

    bool isVerified(User* usr, QString s);

    void setLogin(User* usr, QString e, QString p);

    bool login(QString s);

    void signup(QString e, QString p);

signals:

};



#endif // USER_H
