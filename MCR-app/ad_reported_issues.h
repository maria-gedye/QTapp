#ifndef AD_REPORTED_ISSUES_H
#define AD_REPORTED_ISSUES_H

#include <QDialog>

namespace Ui {
class ad_reported_issues;
}

class ad_reported_issues : public QDialog
{
    Q_OBJECT

public:
    explicit ad_reported_issues(QWidget *parent = nullptr);
    ~ad_reported_issues();

private:
    Ui::ad_reported_issues *ui;
};

#endif // AD_REPORTED_ISSUES_H
