#ifndef ADMIN_H
#define ADMIN_H

#include "ui_mainwindow.h"
#include "user.h"

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QDir>

class Admin : public QObject    // user-defined class
{
    Q_OBJECT
public:
    explicit Admin(QObject *parent = nullptr);


    void loadIDs() {

            QString newpath = QDir::currentPath();
              QFile file(newpath + "/" + "IDs.txt");

              if (!file.open(QFile::WriteOnly|QFile::Text)) {
                  qInfo() << "File is not open";
              }

              QTextStream out(&file);
              out << "firstName" << "," << "surname" << "," << "ID1" << "," << "ID2" << "\n";
              out << "Pia" << "," << "Desai"<< "," << "MCR123"<< "," << "101"<< "\n";
               out << "Farhan" << "," << "Khan"<< "," << "MCR456"<< "," << "102"<< "\n";
                out << "John" << "," << "Doe"<< "," << "MCR789"<< "," << "103"<< "\n";
                 out << "Jane" << "," << "Doe"<< "," << "MCR112"<< "," << "104"<< "\n";

                 qInfo() << "IDs loaded";

              file.flush();
              file.close();
        }

signals:

};

#endif // ADMIN_H

