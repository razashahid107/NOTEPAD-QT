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


void DashBoard::on_actionLogout_triggered()
{
    // will push back to the main window when Logout is clicked
    QDir qdirectory2;
    QString qtfilename = qdirectory2.currentPath() + "/initialscrcheck.csv";
    string filename2 = qtfilename.toStdString();
    qdirectory2.remove(qtfilename);
    MainWindow *mui;
    mui = new MainWindow(this);
    mui->show();
    hide();
}

