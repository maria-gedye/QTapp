#include "ad_reported_issues.h"
#include "ui_ad_reported_issues.h"

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
