#ifndef VERIFYID_H
#define VERIFYID_H

#include <QDialog>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include "user.h"
#include "admin.h"

namespace Ui {
class verifyid;
}

class verifyid : public QDialog
{
    Q_OBJECT


public:
    explicit verifyid(QWidget *parent = nullptr);
    ~verifyid();

    Admin *currAdmin;
    User VIusr;
    User *curUsr = &VIusr;

    void getVerifyDialogOutput(QString &i1, QString &i2, QString &fn, bool &v) {

        i1 = curUsr->getID1();
        i2 = curUsr->getID2();
        fn = curUsr->getName();
        v = curUsr->getVerification();
        qInfo() << "getVerifyOutput:";
        qInfo() << i1 << " " << i2;
        qInfo() << fn << " " << v;
    }

    void getIDInput();
private slots:
    void on_pushButton_submit_clicked();

private:
    Ui::verifyid *ui;
};

#endif // VERIFYID_H
