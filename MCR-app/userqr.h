#ifndef USERQR_H
#define USERQR_H

#include <QDialog>

namespace Ui {
class userqr;
}

class userqr : public QDialog
{
    Q_OBJECT

public:
    explicit userqr(QWidget *parent = nullptr);
    ~userqr();

private slots:
    void on_pushButton_clicked();

private:
    Ui::userqr *ui;
};

#endif // USERQR_H
