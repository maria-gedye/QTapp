#ifndef REPORT_ISSUES_H
#define REPORT_ISSUES_H

#include <QDialog>

namespace Ui {
class report_issues;
}

class report_issues : public QDialog
{
    Q_OBJECT

public:
    explicit report_issues(QWidget *parent = nullptr);
    ~report_issues();

private:
    Ui::report_issues *ui;
};

#endif // REPORT_ISSUES_H
