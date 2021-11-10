#include "admin_login.h"
#include "ui_admin_login.h"

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
