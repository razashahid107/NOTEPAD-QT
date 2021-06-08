#include "reminders.h"
#include "ui_reminders.h"

Reminders::Reminders(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Reminders)
{
    ui->setupUi(this);
}

Reminders::~Reminders()
{
    delete ui;
}

void Reminders::on_pushButton_clicked()
{

}

