#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DatabaseHandler *dbh = new DatabaseHandler();
    dbh->display();
    MainWindow w;
    w.show();
    return a.exec();
    delete dbh;
}
