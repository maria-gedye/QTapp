#ifndef SIGNUPDIALOG_H
#define SIGNUPDIALOG_H

#include <QDialog>
#include <QMessageBox>

#include "user.h"

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

    void changeIndex();

    void setCurUsr(User *cu);

    void extractMatchingLine(QStringList &beforeList, QStringList &postList);

    void rewriteUsersFile(QStringList &beforeList, QString &newline, QStringList &postList);

private slots:
    void on_pushButton_submit_clicked(bool checked);

    void on_lineEdit_4pword_check_returnPressed();

    void on_pushButton_4save_clicked();


private:
    Ui::SignupDialog *ui;

};





#endif // SIGNUPDIALOG_H
