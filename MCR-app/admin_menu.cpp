#include "admin_menu.h"
#include "ui_admin_menu.h"

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
