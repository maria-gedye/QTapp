#include "userqr.h"
#include "ui_userqr.h"
#include <QPixmap>

userqr::userqr(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::userqr)
{
    ui->setupUi(this);

    QPixmap rqr(":/new/prefix1/Images/qrcode1.png");
    ui->label_userrqr->setPixmap(rqr.scaled(271,271));
    QPixmap cqr(":/new/prefix1/Images/stock-photo-random-generated-qr-code-abstract-pattern-103027724.jpg");
    ui->label_usercqr->setPixmap(cqr.scaled(271,271));
}

userqr::~userqr()
{
    delete ui;
}


void userqr::on_pushButton_clicked()
{
    this->close();
}

