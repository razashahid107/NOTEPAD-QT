#include "dashboard.h"
#include "ui_dashboard.h"


DashBoard::DashBoard(QWidget *parent) :
    QMainWindow(parent),
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

    nui = new Notepad(this);
    nui->show();
}


void DashBoard::on_Reminder_pb_clicked()
{
    rui = new Reminders(this);
    rui->show();
}


void DashBoard::on_Events_pb_clicked()
{
    eui = new Events(this);
    eui->show();
}

