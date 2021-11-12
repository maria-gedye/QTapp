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

     bool verified;

    // check ID
    QString ID1, ID2, IDSearch;

    if(ui->radioButton_license->isChecked())
    {
//        out<<"Licence,";
        ID1 = ui->lineEdit_L1->text();
        ID2 = ui->lineEdit_L2->text();
        IDSearch = ID1 + ',' + ID2;
    }
    if(ui->radioButton_cc->isChecked())
    {
//        out<<"Citizenship certificate,";
        ID1 = ui->lineEdit_CC1->text();
        ID2 = ui->lineEdit_CC2->text();
        IDSearch = ID1 + ',' + ID2;
    }
    if(ui->radioButton_cer->isChecked())
    {
//        out<<"Birth certificate,";
        ID1 = ui->lineEdit_C1->text();
        ID2 = ui->lineEdit_C2->text();
        IDSearch = ID1 + ',' + ID2;
    }
    if(ui->radioButton_ppt->isChecked())
    {
//        out<<"Passport,";
        ID1 = ui->lineEdit_P1->text();
        ID2 = ui->lineEdit_P2->text();
        IDSearch = ID1 + ',' + ID2;
    }

    verified = curUsr->isVerified(curUsr, IDSearch); // defined in user.h also calls setName()

    if (verified) {
        QString name = curUsr->getName();
        curUsr->setID(curUsr, ID1, ID2, verified, name);  // works!
    }


    qInfo() << "verified status: " << verified;
    VIusr.printInfo(); // see what prints

    this->close();
}

