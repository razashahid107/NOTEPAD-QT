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
    Notepad *nui = new Notepad(this);
    nui->show();
    hide();
}


void DashBoard::on_Reminder_pb_clicked()
{
    Reminders *rui = new Reminders();
    rui->show();
    hide();
}


void DashBoard::on_Events_pb_clicked()
{
    Events *eui = new Events(this);
    eui->show();
    hide();
}

