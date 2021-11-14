#include "admin_menu.h"
#include "ui_admin_menu.h"
#include "ad_manage_user.h"
#include "ad_manage_record_test.h"
#include "ad_reported_issues.h"

admin_menu::admin_menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin_menu)
{
    ui->setupUi(this);
}

admin_menu::~admin_menu()
{
    delete ui;
}

void admin_menu::on_pushButton_manage_user_clicked()
{
    ad_manage_user ad_user;
    ad_user.setModal(true);
    ad_user.exec();
}


void admin_menu::on_pushButton_manage_RT_clicked()
{
    ad_manage_record_test ad_RT;
    ad_RT.setModal(true);
    ad_RT.exec();
}


void admin_menu::on_pushButton_issues_clicked()
{
    ad_reported_issues ad_issues;
    ad_issues.setModal(true);
    ad_issues.exec();
}


void admin_menu::on_pushButton_logout_clicked()
{
    this->close();
}

