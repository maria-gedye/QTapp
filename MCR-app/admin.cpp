#include "admin.h"

Admin::Admin(QObject *parent) : QObject(parent)
{

}

void Admin::loadIDs() {

        QString newpath = QDir::currentPath();
          QFile file(newpath + "/" + "IDs.txt");

          if (!file.open(QFile::WriteOnly|QFile::Text)) {
              qInfo() << "File is not open";
          }

          QTextStream out(&file);
//              out << "firstName" << "," << "surname" << "," << "ID1" << "," << "ID2" << "\n";
          out << "MCR123"<< "," << "101" << "\n";
                    out << "Pia" << "," << "Desai"<< ","<< "\n";
           out << "MCR456"<< "," << "102" << "\n";
                    out << "Farhan" << "," << "Khan"<< ","<< "\n";
            out << "MCR789"<< "," << "103"<< "\n";
                    out  << "John" << "," << "Doe"<< ","  << "\n";
             out << "MCR112"<< "," << "104"<< "\n";
                    out << "Jane" << "," << "Doe"<< "," << "\n";

             qInfo() << "IDs loaded";

          file.flush();
          file.close();

    } // end of loadIDs function
