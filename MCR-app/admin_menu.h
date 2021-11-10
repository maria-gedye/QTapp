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

private:
    Ui::admin_menu *ui;
};

#endif // ADMIN_MENU_H
