#include "ad_reported_issues.h"
#include "ui_ad_reported_issues.h"
#include "admin_menu.h"
#include <QDialog>
#include <QFile>
#include <QMessageBox>
#include <QDir>


ad_reported_issues::ad_reported_issues(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ad_reported_issues)
{
    ui->setupUi(this);
}

ad_reported_issues::~ad_reported_issues()
{
    delete ui;
}

void ad_reported_issues::on_pushButton_goback_clicked()
{
    this->close();
}


void ad_reported_issues::on_pushButton_2_clicked()
{
    QString newpath = QDir::currentPath();
    QFile file(newpath +"/Issues.txt");

    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this,"title","Issues file not open");
    }
    QTextStream in(&file);
    QString text = in.readAll();
    ui->plainTextEdit->setPlainText(text);

    file.close();
}

