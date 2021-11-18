#ifndef SIGNUPDIALOG_H
#define SIGNUPDIALOG_H

#include <QDialog>
#include <QMessageBox>

#include "user.h"
#include "tests.h"

namespace Ui {
class SignupDialog;
}

class SignupDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SignupDialog(QWidget *parent = nullptr);
    ~SignupDialog();

    User Susr;
    User *curUsr = &Susr;
    QString newEmail;

    void changeIndex();

    void setCurUsr(User *cu);

    void extractMatchingLine(QStringList &beforeList, QStringList &postList);

    void rewriteUsersFile(QStringList &beforeList, QString &newline, QStringList &postList);

    void setNewEmail(QString e) {
        newEmail = e;
    }

    QString updateDisplayEmail(QString &e) {
        e = newEmail;
        return e;
    }

private slots:
    void on_pushButton_submit_clicked(bool checked);

    void on_lineEdit_4pword_check_returnPressed();

    void on_pushButton_4save_clicked();


    void on_pushButton_4cancel_clicked();

private:
    Ui::SignupDialog *ui;
    Tests *testObject;

};





#endif // SIGNUPDIALOG_H
