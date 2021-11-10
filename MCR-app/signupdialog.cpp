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

        if(checked) {
      // this should be a function somewhere but I cant set up the User Class and also
        // get this slot to perform the function from User Class in here- annoying!!
            QFile file("/Users/mariagedye/QTapp/MCR-app/txt/Users.txt");

            if (!file.open(QFile::WriteOnly|QFile::Append|QFile::Text)) {
                qInfo() << "File is not open";
            }

            QTextStream out(&file);
            QString email = ui->lineEdit_Email->text();
            QString password = ui->lineEdit_2Password->text();
            out << email << "," << password << "\n";       //writes the data

            file.flush();   // flushes buffer in data stream
            file.close();    // write id, email and password to file
       // function should end here

            outcome.setText("New Account created");
            outcome.exec();
            this->close();      // close signup dialog

        } else {
            outcome.setText("Please agree to Privacy Policy before continuing");
            outcome.exec();
        }

}



