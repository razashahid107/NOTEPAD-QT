QT       += core gui
QT       += network
CONFIG   += qtestlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    CheckDatabase.cpp \
    dashboard.cpp \
    databasehandler.cpp \
    initialscr.cpp \
    main.cpp \
    mainwindow.cpp \
    notepad.cpp \
    register.cpp \
    reminders.cpp \
    welcome.cpp

HEADERS += \
    dashboard.h \
    databasehandler.h \
    functions.h \
    Login.h \
    initialscr.h \
    mainwindow.h \
    notepad.h \
    register.h \
    reminders.h \
    welcome.h

FORMS += \
    dashboard.ui \
    initialscr.ui \
    mainwindow.ui \
    notepad.ui \
    register.ui \
    reminders.ui \
    welcome.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    credentials.csv

RESOURCES += \
    Resources.qrc
