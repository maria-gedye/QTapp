#include "mainwindow.h"
#include "ui_mainwindow.h"


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

    // when signup is complete navigate to index 1 of stackedwidget
    ui->stackedWidget->setCurrentIndex(1);
}

