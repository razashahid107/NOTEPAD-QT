#include "mainwindow.h"
#include "initialscr.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
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
