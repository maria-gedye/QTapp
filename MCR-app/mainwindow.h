#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"

#include <QMainWindow>
#include <QWidget>
#include "signupdialog.h"
#include "verifyid.h"
#include "user.h"
#include "admin.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    User MWcurUsr;
    User *curUsr = &MWcurUsr;

    void delay()
    {
        QTime dieTime= QTime::currentTime().addSecs(5);
        while (QTime::currentTime() < dieTime)
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }


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

    void on_pushButton_LoadTable_clicked();

    void on_pushButton_3reportIssue_clicked();

private:
    Ui::MainWindow *ui;
    SignupDialog *signup_ui;
    verifyid *verify_ui;
};
#endif // MAINWINDOW_H
