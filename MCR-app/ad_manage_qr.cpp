#include "ad_manage_qr.h"
#include "ui_ad_manage_qr.h"
#include <QPixmap>

ad_manage_qr::ad_manage_qr(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ad_manage_qr)
{
    ui->setupUi(this);
}

ad_manage_qr::~ad_manage_qr()
{
    delete ui;
}

void ad_manage_qr::on_pushButton_PRU_clicked()
{
    QPixmap rqr(":/new/prefix1/Images/qrcode1.png");
    ui->label_PiaR->setPixmap(rqr.scaled(151,151));
}


void ad_manage_qr::on_pushButton_PRD_clicked()
{
    ui->label_PiaR->clear();
}


void ad_manage_qr::on_pushButton_FRU_clicked()
{
    QPixmap rqr(":/new/prefix1/Images/qrcode1.png");
    ui->label_FarhanR->setPixmap(rqr.scaled(151,151));
}


void ad_manage_qr::on_pushButton_FRD_clicked()
{
    ui->label_FarhanR->clear();
}


void ad_manage_qr::on_pushButton_JARU_clicked()
{
    QPixmap rqr(":/new/prefix1/Images/qrcode1.png");
    ui->label_JaneR->setPixmap(rqr.scaled(151,151));
}


void ad_manage_qr::on_pushButton_JARD_clicked()
{
    ui->label_JaneR->clear();
}


void ad_manage_qr::on_pushButton_JORU_clicked()
{
    QPixmap rqr(":/new/prefix1/Images/qrcode1.png");
    ui->label_JohnR->setPixmap(rqr.scaled(151,151));
}


void ad_manage_qr::on_pushButton_JORD_clicked()
{
    ui->label_JohnR->clear();
}


void ad_manage_qr::on_pushButton_PCU_clicked()
{
    QPixmap cqr(":/new/prefix1/Images/stock-photo-random-generated-qr-code-abstract-pattern-103027724.jpg");
    ui->label_PiaC->setPixmap(cqr.scaled(151,151));
}


void ad_manage_qr::on_pushButton_PCD_clicked()
{
    ui->label_PiaC->clear();
}


void ad_manage_qr::on_pushButton_FCU_clicked()
{
    QPixmap cqr(":/new/prefix1/Images/stock-photo-random-generated-qr-code-abstract-pattern-103027724.jpg");
    ui->label_FarhanC->setPixmap(cqr.scaled(151,151));
}


void ad_manage_qr::on_pushButton_FCD_clicked()
{
    ui->label_FarhanC->clear();
}


void ad_manage_qr::on_pushButton_JACU_clicked()
{
    QPixmap cqr(":/new/prefix1/Images/stock-photo-random-generated-qr-code-abstract-pattern-103027724.jpg");
    ui->label_JaneC->setPixmap(cqr.scaled(151,151));
}


void ad_manage_qr::on_pushButton_JACD_clicked()
{
    ui->label_JaneC->clear();
}


void ad_manage_qr::on_pushButton_JOCU_clicked()
{
    QPixmap cqr(":/new/prefix1/Images/stock-photo-random-generated-qr-code-abstract-pattern-103027724.jpg");
    ui->label_JohnC->setPixmap(cqr.scaled(151,151));
}


void ad_manage_qr::on_pushButton_JOCD_clicked()
{
    ui->label_JohnC->clear();
}

