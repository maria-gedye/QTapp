#ifndef AD_MANAGE_USER_H
#define AD_MANAGE_USER_H

#include <QDialog>

namespace Ui {
class ad_manage_user;
}

class ad_manage_user : public QDialog
{
    Q_OBJECT

public:
    explicit ad_manage_user(QWidget *parent = nullptr);
    ~ad_manage_user();

private slots:
    void on_pushButton_test_clicked();

    void on_pushButton_record_clicked();

    void on_pushButton_goback_clicked();

private:
    Ui::ad_manage_user *ui;
};

#endif // AD_MANAGE_USER_H
