#include "user.h"

User::User(QObject *parent) : QObject(parent)
{

}



// getter functions....

QString User::getName() {
    return firstName;
}

void User::printInfo() {
    qInfo() << firstName << " " << surname;
    qInfo() << "LoggedIn?  " << loggedIn;
    qInfo() << email << " " << password;
    qInfo() << "ID verified? " << IDverified;
    qInfo() << "ID:  " << ID1 << "  " << ID2;
}

bool User::getVerification() {
    return IDverified;
}

bool User::getLoggedIn() {
   return loggedIn;
}

QString User::getID1() {
    return ID1;
}

QString User::getID2() {
    return ID2;
}

QString User::getPwd() {
    return password;
}

QString User::getEmail() {
    return email;
}

int User::getCount() {
    return counter;
}


// setter functions
void User::setName(User* usr, int p) {    // called in isVerified()
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
        names = line.split(",");

        usr->firstName = names[0];
        usr->surname = names[1];

    qInfo() << "Names split: " << usr->firstName << " " << usr->surname;

} // end of setName function


void User::setID(User* usr, QString i1, QString i2, bool v, QString n) {
    usr->ID1 = i1;
    usr->ID2 = i2;
    usr->IDverified = v;
    usr->firstName = n;
}


bool User::isVerified(User* usr, QString s) {    // gets called in verifyid.cpp

         QMessageBox outcome;

        QString newpath = QDir::currentPath();
        QFile file(newpath + "/" + "IDs.txt");

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

} // end of isVerified function


void User::setLogin(User* usr, QString e, QString p, bool l) {
    usr->email = e;
    usr->password = p;
    usr->loggedIn = l;
}


void User::resetEmail(User* usr, QString a) {
    usr->email = a;
}


void User::resetPwd(User* usr, QString a) {
    usr->password = a;
}


bool User::login(QString e, QString p, int a) {     // called in mainwindow.cpp

    QMessageBox info;
    QString s = e + "," + p;

        QString newpath = QDir::currentPath();
        QFile file(newpath + "/" + "Users.txt");
            if(!file.open(QFile::ReadOnly|QFile::Text)) {
                qDebug() << "File not open";
            }

        QTextStream in(&file);
        QString line;
        bool found = false;
        int stop;

        while(!in.atEnd()) {
            line = in.readLine();
            if (line == s) {
                found = true;
                qInfo() << "User found " << line << found;
                break;

            } else if (a == 2 ) {
                stop = in.pos();
                    if(line.contains(e)) {
                        QString p;
                        QStringList l;
                        in.seek(stop);

                        qInfo() << "found line with email" << line;

                        l.append(line.split(','));
                        qInfo() << "line is:  " << l;
                        p = l[1];
                        testObject->showPasswordHint(p);     // **Test**
                        break;
                }

            } else {
                found = false;
            }
        }

        file.close();

        if (!found && a < 2) {
            info.setText("Wrong email or password");
            info.exec();
       }

    return found;

} // end of login function


void User::signup(QString e, QString p) {

    QString newpath = QDir::currentPath();
      QFile file(newpath + "/" + "Users.txt"); // this is writing to Users.txt in the build folder only

      if (!file.open(QFile::Append|QFile::Text)) {
          qInfo() << "File is not open";

      }

      QTextStream out(&file);
      out << e << "," << p << "\n";       //writes the data

      file.flush();   // flushes buffer in data stream
      file.close();    // write id, email and password to file
} // end of signup function


void User::setCount(int i) {
    counter = i;
}
