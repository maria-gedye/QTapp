#ifndef SIGNUPDIALOG_H
#define SIGNUPDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDebug>

// parent class
namespace Ui {
class SignupDialog;
}

class SignupDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SignupDialog(QWidget *parent = nullptr);
    ~SignupDialog();

private slots:
    void on_pushButton_submit_clicked(bool checked);

private:
    Ui::SignupDialog *ui;
};

// child class - not working???
//namespace Usr {
//class User;
//}

//class User : public SignupDialog {
//   Q_OBJECT
//    char email[30];
//    char password[20];
//    int id;

//public:
//   explicit User(QWidget *parent = nullptr);
//    ~User();
//    bool verifyLogin(char[], char[]);
//    void signup(QString, QString);  // this writes new accounts to file

//private:
//    Ui::SignupDialog *usr;
//};



#endif // SIGNUPDIALOG_H
