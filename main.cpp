#include "mainwindow.h"

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
    MainWindow w;
    w.show();
    return a.exec();
    delete dbh;
}
