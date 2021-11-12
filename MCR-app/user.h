#ifndef USER_H
#define USER_H

#include "ui_mainwindow.h"

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

    void printInfo() {
        qInfo() << firstName << " " << surname;
        qInfo() << email << " " << password;
        qInfo() << "ID verified? " << IDverified;
        qInfo() << "ID:  " << ID1 << "  " << ID2;
    }

    void setName(User* usr, int p) {    // called in isVerified()

        QString newpath = QDir::currentPath();
        QFile file(newpath + "/" + "IDs.txt");  // relative path using QDir::currentPath()

        if(!file.open(QFile::ReadOnly|QFile::Text)) {
            qDebug() << "File not open";
        }

        QTextStream in(&file);
        QString line;
        QStringList names;
        in.seek(p);
        line = in.readLine();
        qInfo() << "line read:  " << line;
        names = line.split(",");
        usr->firstName = names[0];
        usr->surname = names[1];
        qInfo() << usr->firstName << " " << usr->surname;

    }


    QString getName() {
        return firstName;
    }

    void setID(User* usr, QString i1, QString i2, bool v, QString n) {
        usr->ID1 = i1;
        usr->ID2 = i2;
        usr->IDverified = v;
        usr->firstName = n;
    }

    bool getVerification() {
        return IDverified;
    }

    QString getID1() {
        return ID1;
    }

    QString getID2() {
        return ID2;
    }

    bool isVerified(User* usr, QString s) {    // gets called in verifyid.cpp

             QMessageBox outcome;

        //    QFile file("/Users/rnrn/QTapp/MCR-app/txt");  // absolute path
            QString newpath = QDir::currentPath();
            QFile file(newpath + "/" + "IDs.txt");  // relative path using QDir::currentPath()

            if(!file.open(QFile::ReadOnly|QFile::Text)) {
                qDebug() << "File not open";
            }

            QTextStream in(&file);
            QString line;
            bool found = false;
            int currPos;

            while(!in.atEnd()) {
                line = in.readLine();
                if (line == s) {
                    found = true;
                    qInfo() << "ID found" << line << found;
                    currPos = in.pos();
                    usr->setName(usr, currPos);


                    outcome.setText("Your ID has been verified!");
                    outcome.exec();
                    break;

                } else {
                    qInfo() << "Current readline:  " << line << "  " << found;
                }
            }
            file.flush();
            file.close();

            if (!found) {
                outcome.setText("We can't verify your ID. Please contact the MCR Help team by reporting an issue or email MCRhelp@gmail.com");
                outcome.exec();
             }

        return found;
    }



    void setLogin(User* usr, QString e, QString p) {
        usr->email = e;
        usr->password = p;
    }



    bool login(QString s) {     // called in mainwindow.cpp

        QMessageBox info;

        //    QFile file(":/new/prefix1/txt/Users.txt");  // resource filepath
            QString newpath = QDir::currentPath();
            QFile file(newpath + "/" + "Users.txt");  // relative path using QDir::currentPath()
                if(!file.open(QFile::ReadOnly|QFile::Text)) {
                    qDebug() << "File not open";
                }

            QTextStream in(&file);
            QString line;
            bool found = false;

            while(!in.atEnd()) {
                line = in.readLine();
                if (line == s) {
                    found = true;
                    qInfo() << "User found " << line << found;
                    break;

                } else {
                    found = false;
                    qInfo() << "Current readline:  " << line << "  " << found;
                }
            }
            file.flush();
            file.close();

            if (!found) {
                info.setText("Wrong email or password");
                info.exec();
           }

        return found;
    }


    void signup(QString e, QString p) {
//        QFile file("/Users/mariagedye/QTapp/MCR-app/txt/Users.txt");  // absolute path
        QString newpath = QDir::currentPath();
          QFile file(newpath + "/" + "Users.txt"); // this is writing to Users.txt in the build folder only

          if (!file.open(QFile::Append|QFile::Text)) {
              qInfo() << "File is not open";

          }

          QTextStream out(&file);
          out << e << "," << p << "\n";       //writes the data

          file.flush();   // flushes buffer in data stream
          file.close();    // write id, email and password to file
    }

signals:

};

#endif // USER_H
