#include "signupdialog.h"
#include "ui_signupdialog.h"

SignupDialog::SignupDialog(QWidget *parent) :   // constructor
    QDialog(parent),
    ui(new Ui::SignupDialog)
{
    ui->setupUi(this);

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


// slots below...
void SignupDialog::on_pushButton_submit_clicked(bool checked)
{
    QMessageBox outcome;
    checked = ui->checkBox->isChecked();
    User u1;
    QString email = ui->lineEdit_Email->text();
    QString password = ui->lineEdit_2Password->text();

        if(checked) {
            u1.signup(email, password); // write email & password to Users.txt

            outcome.setText("New Account created");
            outcome.exec();
            this->close();      // close signup dialog

        } else {
            outcome.setText("Please agree to Privacy Policy before continuing");
            outcome.exec();
        }

}



