#include "initialscr.h"

#include <QApplication>
#include "mythread.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyThread mthread;
    mthread.start();
    QDir qdirectory;
    fstream myfile;
    QString qtfilename = qdirectory.currentPath() + "/login.csv";
    qdirectory.remove(qtfilename);
    DatabaseHandler *dbh = new DatabaseHandler();
    dbh->display();
    Initialscr iui;
    iui.show();
    return a.exec();
    delete dbh;
}