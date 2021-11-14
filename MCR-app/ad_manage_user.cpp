#include "ad_manage_user.h"
#include "ui_ad_manage_user.h"
#include "admin_menu.h"
#include <QFile>
#include <QMessageBox>

ad_manage_user::ad_manage_user(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ad_manage_user)
{
    ui->setupUi(this);
}

ad_manage_user::~ad_manage_user()
{
    delete ui;
}

void ad_manage_user::on_pushButton_test_clicked()
{
    QFile testfile(":/new/prefix1/txt/Tests.txt");
    if(!testfile.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this,"title","Test file not open");
    }
    QTextStream in(&testfile);
    QString text = in.readAll();
    ui->textBrowser_display->setPlainText(text);

    testfile.close();


}


void ad_manage_user::on_pushButton_record_clicked()
{
    QFile recordfile(":/new/prefix1/txt/Vaccines.txt");
    if(!recordfile.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this,"title","Record file not open");
    }
    QTextStream in(&recordfile);
    QString text = in.readAll();
    ui->textBrowser_display->setPlainText(text);

    recordfile.close();
}


void ad_manage_user::on_pushButton_goback_clicked()
{
    admin_menu am;
    am.setModal(true);
    am.exec();

}

