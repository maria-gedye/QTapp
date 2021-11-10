#include "admin_login.h"
#include "ui_admin_login.h"
#include "admin_menu.h"
#include <QMessageBox>


Admin_login::Admin_login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Admin_login)
{
    ui->setupUi(this);
}

Admin_login::~Admin_login()
{
    delete ui;
}

void Admin_login::on_pushButton_adminLogin_clicked()
{
    QString adminname = ui->lineEdit_name->text();
    QString pwd = ui->lineEdit_pwd->text();

    if(adminname == "admin" && pwd == "123")
    {

        admin_menu ad_menu;
        ad_menu.setModal(true);
        ad_menu.exec();
    }
    else
    {
        QMessageBox::warning(this,"Login","Username and password is not correct");
    }
}

