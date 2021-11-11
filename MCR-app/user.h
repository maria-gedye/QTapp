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

    bool isVerified(QString s) {    // gets called in verifyid.cpp

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

            while(!in.atEnd()) {
                line = in.readLine();
                if (line == s) {
                    found = true;
                    qInfo() << "ID found" << line << found;
                    outcome.setText("Your ID has been verified!");
                    outcome.exec();

                } else {
                    qInfo() << "Current readline:  " << line << "  " << found;
                }
            }
            file.flush();
            file.close();

            if (!found) {
                outcome.setText("We can't verify your ID. Please contact the MCR Help team by \n reporting an issue or email MCRhelp@gmail.com");
                outcome.exec();
             }

        return found;
    }


    bool login(QString s) {

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

                } else {
                    qInfo() << "Current readline:  " << line << "  " << found;
                }
            }
            file.flush();
            file.close();

            if (!found) {
                info.setText("Wrong email or password");
                info.exec();
                found = false;
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
