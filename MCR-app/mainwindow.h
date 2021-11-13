#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"

#include <QMainWindow>
#include <QWidget>
#include <QListWidget>
#include <QString>
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

    void readTestsRecords() {
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

    void readVaccineRecords() {

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

<<<<<<< HEAD

    void on_pushButton_1back_clicked();

||||||| 7e5570f
=======
    void on_pushButton_3reportIssue_clicked();

>>>>>>> 200c97cf862849e81543e3fdbd4755a2a0a281fa
private:
    Ui::MainWindow *ui;
    SignupDialog *signup_ui;
    verifyid *verify_ui;
};
#endif // MAINWINDOW_H
