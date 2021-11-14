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

// user-defined functions below...
void MainWindow::delay()
{
    QTime dieTime= QTime::currentTime().addSecs(5);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void MainWindow::readTestsRecords() {
    QFile t_file(":/new/prefix1/txt/Tests.txt");
    if (!t_file.open(QFile::ReadOnly|QFile::Text)) {
        qInfo() << "Tests file is not open";
    }

    QTextStream in(&t_file);
    QString search_name, line, singleRec;
    QStringList allRec, temp, testList;
    int i = 0;

    search_name = curUsr->getName();
        qInfo() << "Searching name:  " << search_name;

    while(!in.atEnd()) {
        line = in.readLine();
        if (line.contains(search_name)) {
            allRec.append(line);    // check file and add matching lines to allRec
            i++;
        }
    }
    t_file.flush();
    t_file.close();

       for (int j = 0; j < allRec.size(); j++) {
           temp.append(allRec[j].split(","));   // copy to temp, split lines into strings sep by ','
       }

       // formula: remove name, remove name, skip, skip, skip
       for (int i = 0; i < allRec.size(); i++) {
           int indx = temp.indexOf(search_name); // remove name strings in temp
            temp.removeAt(indx);
             temp.removeAt(indx);
         }

    allRec.clear(); // empty allRec
    int k = 0;
       // formula: append every 3 strings in testList, do a join() and store str in allRec
    for (int i = 0; i < temp.size()/ 3; i++) {

        for (int j = 0; j < 3; j++) {
            testList.append(temp[k]);
            k++;
        }
        singleRec = testList.join(" | ");
        testList.clear();
        allRec.append(singleRec);
         qInfo() << "allRec test:  " << allRec;
    }

    testList = allRec;

    // add strings into list widget

    for (int i = 0; i < testList.size(); i++) {
    QListWidgetItem *testItem = new QListWidgetItem(QIcon(":/new/prefix1/Images/test.png"), testList[i]);
    ui->listWidget_records->addItem(testItem);
    ui->listWidget_records->setIconSize(QSize(80,80));
    }

} // end of readTestRecords function

void MainWindow::readVaccineRecords() {

        QFile v_file(":/new/prefix1/txt/Vaccines.txt");
        if (!v_file.open(QFile::ReadOnly|QFile::Text)) {
            qInfo() << "Vaccines file is not open";
        }

        QTextStream in(&v_file);
        QString search_name, line, singleRec;
        QStringList allRec, temp, vacList;
        int i = 0;

        search_name = curUsr->getName();
            qInfo() << "Searching name:  " << search_name;

        while(!in.atEnd()) {
            line = in.readLine();
            if (line.contains(search_name)) {
                allRec.append(line);    // check file and add matching lines to allRec
                i++;
            }
        }
        v_file.flush();
        v_file.close();

           for (int j = 0; j < allRec.size(); j++) {
               temp.append(allRec[j].split(","));   // copy to temp, split lines into strings sep by ','
           }

           // formula: remove name, remove name, skip, skip, skip
           for (int i = 0; i < allRec.size(); i++) {
               int indx = temp.indexOf(search_name); // remove name strings in temp
                temp.removeAt(indx);
                 temp.removeAt(indx);
             }

        allRec.clear(); // empty allRec
        int k = 0;
           // formula: append every 3 strings in testList, do a join() and store str in allRec
        for (int i = 0; i < temp.size()/ 3; i++) {

            for (int j = 0; j < 3; j++) {
                vacList.append(temp[k]);
                k++;
            }
            singleRec = vacList.join(" | ");
            vacList.clear();
            allRec.append(singleRec);
             qInfo() << "allRec vac:  " << allRec;
        }

        vacList = allRec;

        // add strings into list widget

        for (int i = 0; i < vacList.size(); i++) {
        QListWidgetItem *vacItem = new QListWidgetItem(QIcon(":/new/prefix1/Images/vaccine.png"), vacList[i]);
        ui->listWidget_records->addItem(vacItem);
        ui->listWidget_records->setIconSize(QSize(80,80));
        }


} // end of readVaccineRecord function


// private slots below...

void MainWindow::on_pushButton_start_3_clicked()
{


    ui->stackedWidget->setCurrentIndex(4);  // go to age check screen
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

} // end of verify ID slot


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

    ui->lineEdit_loginEmail->clear();       // clear form
    ui->lineEdit_loginPassword->clear();

    loggedin = curUsr->login(usrSearch); // returns a bool after file read

    curUsr->setLogin(curUsr, email, password); // store in current user object

    if (loggedin) {
        ui->stackedWidget->setCurrentIndex(2);
           ui->label_2Email->setText(email);
    }

} // end of login slot


void MainWindow::on_pushButton_2Logout_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);  // goto home
}


void MainWindow::on_pushButton_3Logout_clicked()
{
    ui->listWidget_records->clear();    // clear records
    ui->pushButton_LoadTable->setEnabled(true); // reset load records button
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

    // now for checking vaccine records...
    readVaccineRecords();

    // read tests file for matching records
    readTestsRecords();

    ui->pushButton_LoadTable->setEnabled(false);

} // end of loadRecords slot



void MainWindow::on_pushButton_1back_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_3reportIssue_clicked()
{
    report_issues_ui = new report_issues(this);
    report_issues_ui->show();
}


void MainWindow::on_pushButton_2reportIssue_clicked()
{
    report_issues_ui = new report_issues(this);
    report_issues_ui->show();
}


void MainWindow::on_pushButton_NEXT_clicked()
{
    //open signup dialog
    signup_ui = new SignupDialog(this);
    signup_ui->show();

    ui->stackedWidget->setCurrentIndex(1);  // go to login
}


void MainWindow::on_pushButton_EXIT_clicked()
{

}

