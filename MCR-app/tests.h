#ifndef TESTS_H
#define TESTS_H

#include <QObject>
#include <QMessageBox>
#include <QDebug>
#include <QDir>
#include <QFile>


class Tests
{

public:    
Tests();

bool emailHasAtSign(QString email);

bool emailHasFullStops(QString email);

bool emailAlreadyExists(QString email);

void showPasswordHint(QString hint);

bool passwordHasMinOfSixChar(QString password);


};


#endif // TESTS_H
