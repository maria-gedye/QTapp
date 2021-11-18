#include "signupdialog.h"
#include "ui_signupdialog.h"

SignupDialog::SignupDialog(QWidget *parent) :   // constructor
    QDialog(parent),
    ui(new Ui::SignupDialog)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    // connect the checkbox with the submit button
    QObject::connect(ui->checkBox, &QCheckBox::toggled, ui->pushButton_submit, &QPushButton::setEnabled);

    // set attribute so that dialog will close on command
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->show();


}

SignupDialog::~SignupDialog()       // destructor
{
    delete ui;
}


// user-defined functions below..

void SignupDialog::changeIndex() {
    // set up the 'change login' widget
 ui->stackedWidget->setCurrentIndex(1);
 ui->label_4changeMsg->hide();
 ui->label_4newemail->hide();
 ui->label_4newpword->hide();
 ui->lineEdit_4newEmail->hide();
 ui->lineEdit_4newPassword->hide();
 ui->pushButton_4save->hide();

}


void SignupDialog::setCurUsr(User *cu) {
        // retrieve login details from main window
    QString email = cu->getEmail();
    QString pwd = cu->getPwd();
    bool loggedin = cu->getLoggedIn();
    curUsr->setLogin(curUsr, email, pwd, loggedin);
    curUsr->printInfo(); // check if set
}


void SignupDialog::extractMatchingLine(QStringList &beforeList, QStringList &postList) {
         // first search users for matching login details,
       // then get line counts for before and after the matching line
       // next store all the other lines in QStringList

       QString newpath = QDir::currentPath();
       QFile file(newpath + "/" + "Users.txt");
           if(!file.open(QFile::ReadOnly|QFile::Text)) {
               qDebug() << "File not open";
           }

       QTextStream in(&file);

       QString line, email, pwd;
       int p1, p2, match, lineCount = 0;

       pwd = curUsr->getPwd();
       email = curUsr->getEmail();
       qInfo() << "curUsr's email & password  " << email << "  " << pwd;


       // 1. readLine to get positions, countline n find matching line
       p1 = in.pos();
       while(!in.atEnd()) {

           line = in.readLine();

           if (line.contains(email)) {
               match = lineCount;           // store matching line number;
               p2 = in.pos();          // get pos end of readline

               qInfo() << "Current login found @ line:  " << lineCount;

           } else {

               qInfo() << "Skipped " << lineCount;
           }

           lineCount++;          // find out how many lines in total in the file
       }
       qInfo() << "Total line count @   " << lineCount;
        lineCount -= match;
            qInfo() << "New Post line count @   " << lineCount;


   //   // 2. readLine to store unchanged info into QStringList params

       in.seek(p1);
       for(int i = 0; i < match; i++) {
           line = in.readLine();
           beforeList.append(line);
           qInfo() << "Added to beforeList:  " << line;
       }

       in.seek(p2);
       for(int i = 0; i < lineCount; i++) {
           line = in.readLine();
           postList.append(line);
           qInfo() << "Added to postList:  " << line;
       }

       file.close();


}  // ennd of extractMatchingLine function



void SignupDialog::rewriteUsersFile(QStringList &beforeList, QString &newline, QStringList &postList) {

    // 1. write unmatched lines and the newline to temp file
    QString newpath = QDir::currentPath();
    QFile file(newpath + "/" + "tempUsers.txt");
        if(!file.open(QFile::Append|QFile::Text)) {
            qDebug() << "File not open";
        }

    QTextStream out(&file);

    for(int i = 0; i < beforeList.size(); i++) {
        out << beforeList.at(i).toLocal8Bit().constData() << Qt::endl;
    }

    out << "\n" + newline;

    for(int i = 0; i < postList.size(); i++) {
        out << postList.at(i).toLocal8Bit().constData() << Qt::endl;
    }


    file.flush();
    file.close();

 // 2. remove old file and rename new file as Users.txt
    QFile::rename(newpath + "/" + "Users.txt", newpath + "/" + "remove.txt");
    QFile::remove(newpath + "/" + "remove.txt");

    QFile::rename(newpath + "/" + "tempUsers.txt", newpath + "/" + "Users.txt");

}



// private slots below...

void SignupDialog::on_pushButton_submit_clicked(bool checked)
{
    QMessageBox outcome;
    checked = ui->checkBox->isChecked();

    QString email = ui->lineEdit_Email->text();
    QString password = ui->lineEdit_2Password->text();

        if(checked) {
//              if (!hasAtSign && !hasFullStop) {
            curUsr->signup(email, password); // write email & password to Users.txt

            outcome.setText("New Account created");
            outcome.exec();
            this->close();      // close signup dialog
//           }
        } else {
            outcome.setText("Please agree to Privacy Policy before continuing");
            outcome.exec();
        }

}




void SignupDialog::on_lineEdit_4pword_check_returnPressed()
{
    QString passwordCheck, pwd, eml;
    passwordCheck = ui->lineEdit_4pword_check->text();

    pwd = curUsr->getPwd();
    eml = curUsr->getEmail();

    if(passwordCheck == pwd) {
        ui->label_4changeMsg->show();
        ui->label_4newemail->show();
        ui->label_4newpword->show();
        ui->lineEdit_4newEmail->show();
        ui->lineEdit_4newPassword->show();
        ui->pushButton_4save->show();
    } else {
        QMessageBox::information(this, "Oops", "Password is wrong");
        qInfo() << "password:  " << pwd;
    }

}




void SignupDialog::on_pushButton_4save_clicked()
{  

    QString newEmail = ui->lineEdit_4newEmail->text();
    QString newPwd = ui->lineEdit_4newPassword->text();

    QStringList beforeList, postList;

    extractMatchingLine(beforeList, postList);

    if (!newEmail.isEmpty()) {
//// ** Tests below **
        // replace email in curUsr object if there is text in editLine
        curUsr->resetEmail(curUsr, newEmail);
        setNewEmail(newEmail);
    }

    if (!newPwd.isEmpty()) {
        // replace password in curUsr object if there is text in editLine
        curUsr->resetPwd(curUsr, newPwd);
    }

    QString newpwd = curUsr->getPwd();
    QString neweml = curUsr->getEmail();
    QString newline = neweml + "," + newpwd;

    rewriteUsersFile(beforeList, newline, postList);

    QMessageBox outcome;
    outcome.setText("Your changes have been saved");
    outcome.exec();

    this->close();

}


void SignupDialog::on_pushButton_4cancel_clicked()
{
    this->close();
}

