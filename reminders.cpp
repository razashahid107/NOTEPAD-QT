#include "reminders.h"
#include "ui_reminders.h"

Reminders::Reminders(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Reminders)
{
    ui->setupUi(this);
    ui->reminderTitle->setPlaceholderText("Enter Title");
    ui->reminderBody->setPlaceholderText("Enter Reminder");
    fstream myfile;
    QDir qdirectory;
    QString qtfilename = qdirectory.currentPath() + "/initialscrcheck.csv";
    string filename = qtfilename.toStdString();
    Login lg;
    myfile.open(filename, ios::in);
    getline(myfile, username, ',');
    username = lg.decrypt(username);
}

Reminders::~Reminders()
{
    delete ui;
    delete Qman;
}


void Reminders::on_save_pushButton_clicked()
{
    QString title = ui->reminderTitle->toPlainText();
    QString body = ui->reminderBody->toPlainText();
    QString date_day = ui->calender->selectedDate().toString("dd");
    QString date_month = ui->calender->selectedDate().toString("MM");
    QString date_year = ui->calender->selectedDate().toString("yy");
    QString time_hour = ui->timeEdit->time().toString("hh");
    QString time_min = ui->timeEdit->time().toString("mm");
    qDebug() << date_day << date_month << date_year << time_hour << time_min;
    Qman = new QNetworkAccessManager();
    QVariantMap newEntry;
    newEntry ["Title"] = title;
    newEntry ["Body"] = body;
    newEntry ["Day_of_Month"] = date_day;
    newEntry ["Month"] = date_month;
    newEntry ["Year"] = date_year;
    newEntry ["Hour"] = time_hour;
    newEntry ["Minute"] = time_min;
    QJsonDocument  docs = QJsonDocument::fromVariant(newEntry);
    string Date_month = date_month.toStdString();
    string Date_day = date_day.toStdString();
    string Time_hour = time_hour.toStdString();
    string Time_min = time_min.toStdString();
    string strURL = "https://practice-e90c6-default-rtdb.firebaseio.com/" + username + "/Reminders/" + Date_month + "/" + Date_day + "/" + Time_hour + "/" + Time_min +".json";
    QString URL = QString::fromStdString(strURL);
    QNetworkRequest qreq((QUrl(URL)));
    qreq.setHeader(QNetworkRequest::ContentTypeHeader, QString("application/json"));
    Qman->put(qreq, docs.toJson());
}
