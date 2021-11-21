#include "tests.h"

Tests::Tests()
{

}

bool Tests::emailHasAtSign(QString email) {
    bool flag;
    int count = 0;

    for (int i = 0; i < email.length(); i++) {
       if (email[i] == '@') {
           count++;
       }
    }

    if ((email.contains('@')) && (count == 1)) {
        flag = true;
    } else {
        qInfo() << count << "  '@' counted";
        QMessageBox outcome;
        outcome.setText("Email must contain one '@'");
        outcome.exec();
        flag = false;
    }

        return flag;
}



bool Tests::emailHasFullStops(QString email) {
    bool flag;
    int count = 0;

    for (int i = 0; i < email.length(); i++) {
       if (email[i] == '.') {
           count++;
       }
    }

    if ((email.contains('.')) && (count >= 1)) {
        flag = true;
    } else {
        qInfo() << count << "  '.' counted";
        QMessageBox outcome;
        outcome.setText("Email must contain at least one '.'");
        outcome.exec();
        flag = false;
    }

    return flag;
}



bool Tests::emailAlreadyExists(QString email) {

    QString path = QDir::currentPath();
    qInfo() << "current path is   " << path;
    QFile file(path + "/" + "Users.txt");
        if(!file.open(QFile::ReadOnly|QFile::Text)) {
            qDebug() << "File did not open during test:  emailAlreadyExists()";
    }

    QTextStream in(&file);
    QString line;
    QStringList record;

    while (!in.atEnd()) {
        line = in.readLine();

        if (line.contains(email)) {
            record = line.split(",");
            break;
        }
    }

    file.close();

    if (!record.isEmpty()) {

        if (record[0] == email) {
            QMessageBox outcome;
            outcome.setText("This email has already been registered");
            outcome.exec();
            return true;
        } else {
            qInfo() << "END OF THE TEST";
            return false;
        }
    } else {
        qInfo() << "END OF THE TEST";
        return false;
    }

}

void Tests::showPasswordHint(QString hint) {

       qInfo() << "hint size:  " << hint.size();

    for(int i = 1; i < hint.size() -1; i++ ) {
        hint[i] = '*';
    }
        QMessageBox outcome;
        outcome.setText("You've entered incorrect password 2 times. Here is a hint: " + hint);
        outcome.exec();

}

bool Tests::passwordHasMinOfSixChar(QString password) {

}
