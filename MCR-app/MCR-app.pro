QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ad_manage_record_test.cpp \
    ad_manage_user.cpp \
    ad_reported_issues.cpp \
    admin.cpp \
    admin_login.cpp \
    admin_menu.cpp \
    main.cpp \
    mainwindow.cpp \
    signupdialog.cpp \
    user.cpp \
    userqr.cpp \
    verifyid.cpp

HEADERS += \
    ad_manage_record_test.h \
    ad_manage_user.h \
    ad_reported_issues.h \
    admin.h \
    admin_login.h \
    admin_menu.h \
    mainwindow.h \
    signupdialog.h \
    user.h \
    userqr.h \
    verifyid.h

FORMS += \
    ad_manage_record_test.ui \
    ad_manage_user.ui \
    ad_reported_issues.ui \
    admin_login.ui \
    admin_menu.ui \
    mainwindow.ui \
    signupdialog.ui \
    userqr.ui \
    verifyid.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Images/icon.png \
    Images/logo.png \
    Images/whanau.2d006e8f.png \
    txt/IDs.txt \
    txt/Issues.txt \
    txt/Users.txt

RESOURCES += \
    Resources.qrc
