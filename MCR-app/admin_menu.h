#ifndef ADMIN_MENU_H
#define ADMIN_MENU_H

#include <QDialog>

namespace Ui {
class admin_menu;
}

class admin_menu : public QDialog
{
    Q_OBJECT

public:
    explicit admin_menu(QWidget *parent = nullptr);
    ~admin_menu();

private slots:
    void on_pushButton_manage_user_clicked();

    void on_pushButton_manage_RT_clicked();

    void on_pushButton_issues_clicked();

    void on_pushButton_logout_clicked();

private:
    Ui::admin_menu *ui;
};

#endif // ADMIN_MENU_H
