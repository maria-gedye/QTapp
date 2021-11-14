#ifndef REPORT_ISSUES_H
#define REPORT_ISSUES_H

#include <QDialog>
#include <QDateTime>
#include "admin.h"
#include "user.h"

namespace Ui {
class report_issues;
}

class report_issues : public QDialog
{
    Q_OBJECT
    static int count;

public:
    report_issues(QWidget *parent = nullptr);
    ~report_issues();

    QString timeStamp();

private slots:
    void on_pushButton_RIsend_clicked();

    void on_pushButton_RIcancel_clicked();

private:
    Ui::report_issues *ui;
};

#endif // REPORT_ISSUES_H
