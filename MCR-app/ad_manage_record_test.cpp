#include "ad_manage_record_test.h"
#include "ui_ad_manage_record_test.h"

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
