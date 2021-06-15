QT       += core gui
QT       += network
CONFIG   += qtestlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dashboard.cpp \
    databasehandler.cpp \
    events.cpp \
    main.cpp \
    initialscr.cpp \
    mainwindow.cpp \
    mythread.cpp \
    notepad.cpp \
    register.cpp \
    reminders.cpp \
    welcome.cpp

HEADERS += \
    Login.h \
    dashboard.h \
    databasehandler.h \
    events.h \
    functions.h \
    initialscr.h \
    mainwindow.h \
    mythread.h \
    notepad.h \
    register.h \
    reminders.h \
    welcome.h

FORMS += \
    dashboard.ui \
    events.ui \
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

RESOURCES += \
    Resources.qrc
