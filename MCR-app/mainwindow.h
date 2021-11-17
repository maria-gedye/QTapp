#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"

#include <QMainWindow>
#include <QWidget>
#include <QListWidget>
#include <QString>

#include "signupdialog.h"
#include "verifyid.h"
#include "report_issues.h"
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

// user-defined functions below...
    void delay();

    void readTestsRecords();

    void readVaccineRecords();


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

    void on_pushButton_1back_clicked();

    void on_pushButton_3reportIssue_clicked();

    void on_pushButton_2reportIssue_clicked();

    void on_pushButton_NEXT_clicked();

    void on_pushButton_EXIT_clicked();

    void on_pushButton_2changeLogin_clicked();

    void on_pushButton_3changeLogin_clicked();


private:
    Ui::MainWindow *ui;
    SignupDialog *signup_ui;
    SignupDialog *changeLogin_ui;
    verifyid *verify_ui;
    report_issues *report_issues_ui;


};
#endif // MAINWINDOW_H
