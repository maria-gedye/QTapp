#include "mainwindow.h"
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

     verify_ui = new verifyid(this);
     verify_ui->show();

    QString ID1, ID2, FirstName;
    bool verified;

     delay(); // wait before executing rest of the function
     int count = 0;

verify_again:
        verify_ui->getVerifyDialogOutput(ID1, ID2, FirstName, verified);
        curUsr->setID(curUsr, ID1, ID2, verified, FirstName);
        qInfo() << "verifybutton: ";
        qInfo() << ID1 << " " << ID2 << " " << FirstName << " " << verified;

     if (verified) {
         ui->stackedWidget->setCurrentIndex(3);
        ui->label_3Name->setText("Kia ora " + FirstName);
     } else {
         count++;
         delay();
         if (count < 5)
            goto verify_again;
     }

} // end of verify ID function


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

    bool loggedin;

    // check credentials
    QString email, password, usrSearch;
    email = ui->lineEdit_loginEmail->text();
    password = ui->lineEdit_loginPassword->text();
    usrSearch = email + ',' + password;

    loggedin = curUsr->login(usrSearch); // returns a bool after file read

    curUsr->setLogin(curUsr, email, password); //works!

    if (loggedin) {
        ui->stackedWidget->setCurrentIndex(2);
           ui->label_2Email->setText(email);
    }

} // end of login function


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


void MainWindow::on_pushButton_LoadTable_clicked()
{
    qInfo() << "Hello";
}

