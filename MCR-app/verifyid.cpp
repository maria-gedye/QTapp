#include "verifyid.h"
#include "ui_verifyid.h"
#include <QMessageBox>

verifyid::verifyid(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::verifyid)
{
    ui->setupUi(this);
}

verifyid::~verifyid()
{
    delete ui;
}

void verifyid::on_pushButton_submit_clicked()
{
     QMessageBox outcome;

    QFile file("Users.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);

    if(ui->radioButton_license->isChecked())
    {
        //out<<ui->radioButton_license->text();
        out<<",Licence,";
        out<<ui->lineEdit_L1->text()<<",";
        out<<ui->lineEdit_L2->text()<<Qt::endl;
    }
    if(ui->radioButton_cc->isChecked())
    {
        out<<",Citizenship certificate,";
        out<<ui->lineEdit_CC1->text()<<",";
        out<<ui->lineEdit_CC2->text()<<Qt::endl;
    }
    if(ui->radioButton_cer->isChecked())
    {
        out<<",Birth certificate,";
        out<<ui->lineEdit_C1->text()<<",";
        out<<ui->lineEdit_C2->text()<<Qt::endl;
    }
    if(ui->radioButton_ppt->isChecked())
    {
        out<<",Passport,";
        out<<ui->lineEdit_P1->text()<<",";
        out<<ui->lineEdit_P2->text()<<Qt::endl;
    }

    outcome.setText("Your ID has been verified!");
    outcome.exec();
    this->close();
}

