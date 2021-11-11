#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "verifyid.h"
#include "admin_login.h"
#include "userqr.h"


MainWindow::MainWindow(QWidget *parent)     // constructor
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //display the whanau image from our Resources.qrc file
    QPixmap whanauImg(":/new/prefix1/Images/whanau.2d006e8f.png");
    ui->label_3_mainimage->setPixmap(whanauImg);
    ui->label_3_mainimage->setScaledContents(true);

    ui->stackedWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow()   // destructor
{
    delete ui;
}


// slots below...

void MainWindow::on_pushButton_start_3_clicked()
{

    //open signup dialog
    signup_ui = new SignupDialog(this);
    signup_ui->show();

    ui->stackedWidget->setCurrentIndex(1);  // go to login
}


void MainWindow::on_pushButton_verifyID_clicked()
{
     Admin a1;
     a1.loadIDs();

    verifyid vid;
    vid.setModal(true);
    vid.exec();
}


void MainWindow::on_pushButton_adminLogin_clicked()
{
    Admin_login ad_login;
    ad_login.setModal(true);
    ad_login.exec();
}



void MainWindow::on_pushButton_loginUsr_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);  // goto login window
}


void MainWindow::on_pushButton_loginsubmit_clicked()
{
    User u1;
    // check credentials
    QString email, password, usrSearch;
    email = ui->lineEdit_loginEmail->text();
    password = ui->lineEdit_loginPassword->text();
    usrSearch = email + ',' + password;

    u1.login(usrSearch); // returns a bool

    //            if (user is verified)
    //             ui->stackedWidget->setCurrentIndex(3);  // goto userdashboard window
    //                            ui->label_2Email->setText("Kia ora " + user firstName);
    //            else
                    ui->stackedWidget->setCurrentIndex(2);  // goto userdashboard window

                    ui->label_2Email->setText(email);

}


void MainWindow::on_pushButton_2Logout_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);  // goto home
}


void MainWindow::on_pushButton_3Logout_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);  // goto home
}


void MainWindow::on_pushButton_testuserqr_clicked()
{
    userqr uqr;
    uqr.setModal(true);
    uqr.exec();
}

void MainWindow::on_pushButton_testadminqr_clicked()
{

}

