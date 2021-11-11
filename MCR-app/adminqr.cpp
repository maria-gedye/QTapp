#include "adminqr.h"
#include "ui_userqr.h"

adminqr::adminqr(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminqr)
{
    ui->setupUi(this);
}

adminq::~adminqr()
{
    delete ui;
}


