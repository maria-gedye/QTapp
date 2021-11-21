#include "ad_manage_record_test.h"
#include "ui_ad_manage_record_test.h"
#include "ad_manage_qr.h"
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QDir>

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

}


void ad_manage_record_test::on_pushButton_RT_test_edit_clicked()
{
    QString newpath = QDir::currentPath();
      QFile testfile(newpath + "/" + "Tests.txt");
    if(!testfile.open(QFile::Append | QFile::Text))
    {
        QMessageBox::warning(this,"title","Test file not open");
    }
    QTextStream out(&testfile);
    QString data = ui->plainTextEdit->toPlainText();
    out << data;

    testfile.flush();
    testfile.close();
}


void ad_manage_record_test::on_pushButton_RT_record_edit_clicked()
{
    QString newpath = QDir::currentPath();
      QFile recordfile(newpath + "/" + "Vaccines.txt");
    if(!recordfile.open(QFile::Append | QFile::Text))
    {
        QMessageBox::warning(this,"title","Record file not open");
    }
    QTextStream out(&recordfile);
    QString data = ui->plainTextEdit->toPlainText();
    out << data;

    recordfile.flush();
    recordfile.close();
}


void ad_manage_record_test::on_pushButton_RT_QR_edit_clicked()
{
    ad_manage_qr qr;
    qr.setModal(true);
    qr.exec();
}

