#ifndef AD_MANAGE_RECORD_TEST_H
#define AD_MANAGE_RECORD_TEST_H

#include <QDialog>

namespace Ui {
class ad_manage_record_test;
}

class ad_manage_record_test : public QDialog
{
    Q_OBJECT

public:
    explicit ad_manage_record_test(QWidget *parent = nullptr);
    ~ad_manage_record_test();

private:
    Ui::ad_manage_record_test *ui;
};

#endif // AD_MANAGE_RECORD_TEST_H
