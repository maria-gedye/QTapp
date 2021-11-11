#ifndef ADMINQR_H
#define ADMINQR_H

#include <QDialog>

namespace Ui {
class adminqr;
}

class adminqr : public QDialog
{
    Q_OBJECT

public:
    explicit adminqr(QWidget *parent = nullptr);
    ~adminqr();

private:
    Ui::adminqr *ui;
};

#endif // ADMINQR_H
