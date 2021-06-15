#include "dashboard.h"
#include "ui_dashboard.h"
#include<QCoreApplication>

DashBoard::DashBoard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DashBoard)
{
    ui->setupUi(this);
}

DashBoard::~DashBoard()
{
    delete ui;
}

void DashBoard::on_Note_pb_clicked()
{
    this->hide();
    Notepad nui;
    nui.setModal(true);
    nui.exec();
}


void DashBoard::on_Reminder_pb_clicked()
{
    this->hide();
    Reminders rui;
    rui.setModal(true);
    rui.exec();
}

void DashBoard::on_Events_pb_clicked()
{
    this->hide();
    Events eui;
    eui.setModal(true);
    eui.exec();
}

//void QCoreApplication::exit(int returnCode = 0)
void DashBoard::on_Tasks_pb_2_clicked()                 // Quit
{
//    QPushButton *quitButton = new QPushButton("Quit");
//    connect(quitButton, &QPushButton::clicked, &app, &QCoreApplication::quit, Qt::QueuedConnection);
    QCoreApplication::exit();

}


void DashBoard::on_Tasks_pb_clicked()
{
    QDir qdirectory2;
    QString qtfilename = qdirectory2.currentPath() + "/initialscrcheck.csv";
    string filename2 = qtfilename.toStdString();
    qdirectory2.remove(qtfilename);
    this->hide();
    MainWindow mui;
    mui.setModal(true);
    mui.exec();
}

