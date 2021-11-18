#ifndef TESTS_H
#define TESTS_H

#include <QObject>
#include <QMessageBox>
#include <QDebug>

#include "user.h"

class Tests
{

public:    
Tests();

bool emailHasAtSign(QString email);

bool emailHasFullStops(QString email);

bool emailAlreadyExists(QString email);

// will implement these tests later...
void showPasswordHint(QString password);

bool passwordIsHidden(QString password);

bool passwordHasMinOfSixChar(QString password);

bool userIsVerified(User currentUser);

};


#endif // TESTS_H
