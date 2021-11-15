#include "ad_manage_record_test.h"
#include "ui_ad_manage_record_test.h"
#include <QFile>
#include <QMessageBox>

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
    ui->listWidget_RT->clear();
    while(!in.atEnd())
    {        
        QString text = in.readLine();
        ui->listWidget_RT->addItem(text);
    }

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
    ui->listWidget_RT->clear();
    while(!in.atEnd())
    {
        QString text = in.readLine();
        ui->listWidget_RT->addItem(text);
    }

    recordfile.close();
}

