#ifndef ADMIN_H
#define ADMIN_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QDir>

class Admin : public QObject    // user-defined class
{
    Q_OBJECT
public:
    explicit Admin(QObject *parent = nullptr);  // default constructor

    void loadIDs();

signals:

};

#endif // ADMIN_H

