#include "dashboard.h"
#include "ui_dashboard.h"

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
    Notepad nui;
    nui.setModal(true);
    nui.exec();
    this->hide();
}


void DashBoard::on_Reminder_pb_clicked()
{
    Reminders rui;
    rui.setModal(true);
    rui.exec();
    this->hide();
}

void DashBoard::on_Events_pb_clicked()
{
    Events eui;
    eui.setModal(true);
    eui.exec();
    this->hide();
}

void DashBoard::on_Tasks_pb_2_clicked()                 // Quit
{

//}

