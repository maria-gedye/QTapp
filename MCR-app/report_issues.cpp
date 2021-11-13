#include "report_issues.h"
#include "ui_report_issues.h"

report_issues::report_issues(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::report_issues)
{
    ui->setupUi(this);
}

report_issues::~report_issues()
{
    delete ui;
}
