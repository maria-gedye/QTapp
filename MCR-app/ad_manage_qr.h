#ifndef AD_MANAGE_QR_H
#define AD_MANAGE_QR_H

#include <QDialog>

namespace Ui {
class ad_manage_qr;
}

class ad_manage_qr : public QDialog
{
    Q_OBJECT

public:
    explicit ad_manage_qr(QWidget *parent = nullptr);
    ~ad_manage_qr();

private slots:
    void on_pushButton_PRU_clicked();

    void on_pushButton_PRD_clicked();

    void on_pushButton_FRU_clicked();

    void on_pushButton_FRD_clicked();

    void on_pushButton_JARU_clicked();

    void on_pushButton_JARD_clicked();

    void on_pushButton_JORU_clicked();

    void on_pushButton_JORD_clicked();

    void on_pushButton_PCU_clicked();

    void on_pushButton_PCD_clicked();

    void on_pushButton_FCU_clicked();

    void on_pushButton_FCD_clicked();

    void on_pushButton_JACU_clicked();

    void on_pushButton_JACD_clicked();

    void on_pushButton_JOCU_clicked();

    void on_pushButton_JOCD_clicked();

private:
    Ui::ad_manage_qr *ui;
};

#endif // AD_MANAGE_QR_H
