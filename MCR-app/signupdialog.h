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

private slots:
    void on_pushButton_submit_clicked(bool checked);

private:
    Ui::SignupDialog *ui;
};





#endif // SIGNUPDIALOG_H
