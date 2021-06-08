#include "initialscr.h"
#include "ui_initialscr.h"
#include <QDebug>


Initialscr::Initialscr(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Initialscr)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowMaximized);
//    fstream myfile;
//    QDir qdirectory;
//    QString qtfilename = qdirectory.currentPath() + "/initialscrcheck.csv";
//    string filename = qtfilename.toStdString();
//    Login lg;
//    myfile.open(filename, ios::in);
//    if (myfile.fail()){
//        MainWindow *mui = new MainWindow();
//        mui->show();
//    }

//    while (getline(myfile, username, ',')) {
//        getline(myfile, password, '\n');
//        username = lg.decrypt(username);
//        password = lg.decrypt(password);
//        if (username.length()>3 && password.length()>5){
//            Notepad *nui = new Notepad();
//            nui->show();
//            hide();
//        }
//        else{
//            MainWindow *mui = new MainWindow();
//            mui->show();
//            hide();
//        }
//    }

}

Initialscr::~Initialscr()
{
    delete ui;
}

void Initialscr::on_commandLinkButton_clicked()
{
    fstream myfile;
    QDir qdirectory;
    QString qtfilename = qdirectory.currentPath() + "/initialscrcheck.csv";
    string filename = qtfilename.toStdString();
    Login lg;
    myfile.open(filename, ios::in);
    if (myfile.fail()){
        MainWindow *mui = new MainWindow();
        mui->show();
        hide();
    }

    while (getline(myfile, username, ',')) {
        getline(myfile, password, '\n');
        username = lg.decrypt(username);
        password = lg.decrypt(password);
        if (username.length()>3 && password.length()>5){
            Notepad *nui = new Notepad();
            nui->show();
            hide();
        }
        else{
            MainWindow *mui = new MainWindow();
            mui->show();
            hide();
        }
    }

}

