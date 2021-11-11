#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include "signupdialog.h"
#include "verifyid.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    User *currUser;

private slots:
    void on_pushButton_start_3_clicked();

    void on_pushButton_verifyID_clicked();

    void on_pushButton_adminLogin_clicked();

    void on_pushButton_loginUsr_clicked();

    void on_pushButton_loginsubmit_clicked();

    void on_pushButton_2Logout_clicked();

    void on_pushButton_3Logout_clicked();

    void on_pushButton_testuserqr_clicked();

    void on_pushButton_testadminqr_clicked();

private:
    Ui::MainWindow *ui;
    SignupDialog *signup_ui;
};
#endif // MAINWINDOW_H
