#ifndef USER_H
#define USER_H

#include "ui_mainwindow.h"

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QDir>

class User : public QObject
{
    Q_OBJECT
public:
    explicit User(QObject *parent = nullptr);
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
