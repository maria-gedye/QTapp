#include "report_issues.h"
#include "ui_report_issues.h"

report_issues::report_issues(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::report_issues)
{
    ui->setupUi(this);

}


 int report_issues::count = 0;

report_issues::~report_issues()
{
    delete ui;
}

QString report_issues::timeStamp() {

    QDateTime cdt = QDateTime::currentDateTime();
    qInfo() << "Issue reported @  " << cdt;

    return cdt.toString();
}

void report_issues::on_pushButton_RIsend_clicked()
{
    int issueID = createID() + 100;
    QFile file("Issues.txt");

    if (!file.open(QFile::Append|QFile::Text)) {
        qInfo() << "File is not open";
    }

    QTextStream out(&file);
    QString data = ui->plainTextEdit_UreportIssue->toPlainText();
    out << issueID << "\n";
    out << data << "\n";
    out << timeStamp() << "\n\n";
    file.flush();
    file.close();

    this->close();
}


void report_issues::on_pushButton_RIcancel_clicked()
{
    this->close();
}

