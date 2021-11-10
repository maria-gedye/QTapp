#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "verifyid.h"
#include "admin_login.h"


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

    // when signup is complete display user dashboard
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_pushButton_verifyID_clicked()
{
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

