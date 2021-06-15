#include "initialscr.h"
#include "ui_initialscr.h"

Initialscr::Initialscr(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Initialscr)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowMaximized); // maximizes screen

}

Initialscr::~Initialscr()
{
    delete ui;
}


void Initialscr::on_pushButton_clicked()
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
            DashBoard *dsb = new DashBoard();
            dsb->show();
            Qman = new QNetworkAccessManager(this);
            Qreply1 = Qman->get(QNetworkRequest(QUrl("https://practice-e90c6-default-rtdb.firebaseio.com/Counting/" + QString::fromStdString(username) + "/Number" + ".json")));
            connect(Qreply1, &QNetworkReply::readyRead, this, &Initialscr::Readconting);
            hide();
        }
        else{
            MainWindow *mui = new MainWindow();
            mui->show();
            hide();
        }
    }
}

void Initialscr::Readconting()
{
    QString firebaseReminders = Qreply1->readAll();
    QDir qdirectory;
    fstream myfile;
    QString qtfilename = qdirectory.currentPath() + "/number.txt";
    string filename = qtfilename.toStdString();
    myfile.open(filename, ios::out);
    myfile << firebaseReminders.toStdString();
    myfile.close();
}

