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
    databasehandler.cpp \
    main.cpp \
    mainwindow.cpp \
    notepad.cpp \
    register.cpp \
    welcome.cpp

HEADERS += \
    databasehandler.h \
    functions.h \
    Login.h \
    mainwindow.h \
    notepad.h \
    register.h \
    welcome.h

FORMS += \
    mainwindow.ui \
    notepad.ui \
    register.ui \
    welcome.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    credentials.csv

RESOURCES += \
    Resources.qrc
