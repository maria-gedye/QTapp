#include "ad_manage_record_test.h"
#include "ui_ad_manage_record_test.h"
#include <QFile>
#include <QMessageBox>
#include <QTextStream>

ad_manage_record_test::ad_manage_record_test(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ad_manage_record_test)
{
    ui->setupUi(this);
}

ad_manage_record_test::~ad_manage_record_test()
{
    delete ui;
}

void ad_manage_record_test::on_pushButton_RT_goback_clicked()
{
    this->close();
}


void ad_manage_record_test::on_pushButton_RT_test_clicked()
{
    QFile testfile(":/new/prefix1/txt/Tests.txt");
    if(!testfile.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this,"title","Test file not open");
    }
    QTextStream in(&testfile);
    QString text = in.readAll();
    ui->plainTextEdit->setPlainText(text);

    testfile.close();
}


void ad_manage_record_test::on_pushButton_RT_record_clicked()
{
    QFile recordfile(":/new/prefix1/txt/Vaccines.txt");
    if(!recordfile.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this,"title","Record file not open");
    }
    QTextStream in(&recordfile);
    QString text = in.readAll();
    ui->plainTextEdit->setPlainText(text);

    recordfile.close();
}


void ad_manage_record_test::on_pushButton_RT_QR_clicked()
{
    QFile usernamefile(":/new/prefix1/txt/Usernames.txt");
    if(!usernamefile.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this,"title","Username file not open");
    }
    QTextStream in(&usernamefile);
    QString text = in.readAll();
    ui->plainTextEdit->setPlainText(text);

    usernamefile.close();
}


void ad_manage_record_test::on_pushButton_RT_test_edit_clicked()
{
    QFile testfile(":/new/prefix1/txt/Tests.txt");
    if(!testfile.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this,"title","Test file not open");
    }
    QTextStream out(&testfile);
    QString data = ui->plainTextEdit->toPlainText();
    out << data;

    testfile.flush();
    testfile.close();
}

