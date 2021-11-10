#ifndef ADMIN_LOGIN_H
#define ADMIN_LOGIN_H

#include <QDialog>

namespace Ui {
class Admin_login;
}

class Admin_login : public QDialog
{
    Q_OBJECT

public:
    explicit Admin_login(QWidget *parent = nullptr);
    ~Admin_login();

private:
    Ui::Admin_login *ui;
};

#endif // ADMIN_LOGIN_H
