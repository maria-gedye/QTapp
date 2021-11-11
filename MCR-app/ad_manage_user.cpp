#include "ad_manage_user.h"
#include "ui_ad_manage_user.h"

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
