#ifndef VERIFYID_H
#define VERIFYID_H

#include <QDialog>
#include <QFile>
#include <QTextStream>

namespace Ui {
class verifyid;
}

class verifyid : public QDialog
{
    Q_OBJECT

public:
    explicit verifyid(QWidget *parent = nullptr);
    ~verifyid();

private slots:
    void on_pushButton_submit_clicked();

private:
    Ui::verifyid *ui;
};

#endif // VERIFYID_H
