#include "reminders.h"
#include "ui_reminders.h"
#include <unistd.h>

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
    QString qusername = QString::fromStdString(username);
    Qman = new QNetworkAccessManager();
    Qreply2 = Qman->get(QNetworkRequest(QUrl("https://practice-e90c6-default-rtdb.firebaseio.com/Reminders/"+ qusername + ".json")));
    connect(Qreply2, &QNetworkReply::readyRead, this, &Reminders::ReadReminders);
}

Reminders::~Reminders()
{
    delete ui;
    delete Qman;
}


void Reminders::on_save_pushButton_clicked()
{
    QDir qdirec;
    string Number;
    fstream myfile2;
    QString qtfilename2 = qdirec.currentPath() + "/number.txt";
    string filename2 = qtfilename2.toStdString();
    myfile2.open(filename2, ios::in);
    getline(myfile2, Number, '\n');
    QString title = ui->reminderTitle->toPlainText();
    QString body = ui->reminderBody->toPlainText();
    QString date_day = ui->calender->selectedDate().toString("dd");
    QString date_month = ui->calender->selectedDate().toString("MM");
    QString date_year = ui->calender->selectedDate().toString("yy");
    QString time_hour = ui->timeEdit->time().toString("hh");
    QString time_min = ui->timeEdit->time().toString("mm");
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
    string strURL = "https://practice-e90c6-default-rtdb.firebaseio.com/Reminders/" + username + "/" + Number +".json";
    Login lg;
    int num = stoi(Number);
    lg.setremainderno(username, num);
    QDir qdirec2;
    string Number2;
    fstream myfile;
    QString qtfilename = qdirec2.currentPath() + "/number.txt";
    string filename = qtfilename.toStdString();
    myfile.open(filename, ios::out);
    myfile << num +1;
    QString URL = QString::fromStdString(strURL);
    QNetworkRequest qreq((QUrl(URL)));
    qreq.setHeader(QNetworkRequest::ContentTypeHeader, QString("application/json"));
    Qman->put(qreq, docs.toJson());
}

void Reminders::ReadReminders()
{
    QString firebaseReminders = Qreply2->readAll();
    QDir qdirectory;
    fstream myfile;
    QString qtfilename = qdirectory.currentPath() + "/Reminders.csv";
    string filename = qtfilename.toStdString();
    myfile.open(filename, ios::out);
    string strfirebaseReminders = firebaseReminders.toStdString();
    for (int i = 0; i < strfirebaseReminders.length(); i++)
    {
        if (strfirebaseReminders[i] == '{')
        {
            strfirebaseReminders[i] = ' ';
        }
        else if (strfirebaseReminders[i] == '[')
        {
            strfirebaseReminders[i] = ' ';
        }
        else if (strfirebaseReminders[i] == ']')
        {
            strfirebaseReminders[i] = '\n';
        }
        else if (strfirebaseReminders[i] == ':')
        {
            strfirebaseReminders[i] = ',';
        }
        else if (strfirebaseReminders[i] == '}' && strfirebaseReminders[i + 1] == ',')
        {
            strfirebaseReminders[i] = '\n';
            strfirebaseReminders[i + 1] = ' ';
        }
        else if (strfirebaseReminders[i] == '}' && strfirebaseReminders[i + 1] == '}')
        {
            strfirebaseReminders[i] = '\n';
        }
        else if (strfirebaseReminders[i] == '}')
        {
            strfirebaseReminders[i] = ',';
        }
    }
    myfile << strfirebaseReminders << '\n';
    myfile.close();
}

void Reminders::on_exit_pushButton_clicked()
{
    Reminders rmd;
    string line, username, temp, garbage, month, date, hour, minute, body, title;
    vector<string> vbody;
    vector<string> vtitle;
    vector<string> vmonth;
    vector<string> vdate;
    vector<string> vhour;
    vector<string> vmin;
    bool check = false;
    QDir qdirectory2;
    fstream myfile2;
    QString qtfilename2 = qdirectory2.currentPath() + "/Reminders.csv";
    string filename2 = qtfilename2.toStdString();
    myfile2.open(filename2, ios::in);
    stringstream s(line);
    while (getline(myfile2, garbage, ',') && check == false) {
        getline(myfile2, body, ',');
        for (int i = 0; i < body.length(); i++)
        {
            if (body[i] == '"')
                body[i] = ' ';
        }
        vbody.push_back(body);
        getline(myfile2, garbage, ',');
        getline(myfile2, date, ',');
        for (int i = 0; i < date.length(); i++)
        {
            if (date[i] == '"')
                date[i] = ' ';
        }
        vdate.push_back(date);
        getline(myfile2, garbage, ',');
        getline(myfile2, hour, ',');
        for (int i = 0; i < hour.length(); i++)
        {
             if (hour[i] == '"')
                hour[i] = ' ';
        }
        vhour.push_back(hour);
        getline(myfile2, garbage, ',');
        getline(myfile2, minute, ',');
        for (int i = 0; i < minute.length(); i++)
        {
             if (minute[i] == '"')
                minute[i] = ' ';
        }
        vmin.push_back(minute);
        getline(myfile2, garbage, ',');
        getline(myfile2, month, ',');
        for (int i = 0; i < month.length(); i++)
        {
            if (month[i] == '"')
                month[i] = ' ';
        }
        vmonth.push_back(month);
        getline(myfile2, garbage, ',');
        getline(myfile2, title, ',');
        for (int i = 0; i < title.length(); i++)
        {
            if (title[i] == '"')
                title[i] = ' ';
        }
        vtitle.push_back(title);
        getline(myfile2, garbage, ',');
        getline(myfile2, garbage, '\n');
    }
    for (int i = 0; i < vtitle.size(); i++){
    ui->reminderdisplay->appendPlainText(QString::number(i+1) + ".\n" + "Date: " + QString::fromStdString(vdate[i]) + "/" + QString::fromStdString(vmonth[i]) + "/ 2021" + "\t\tTime:" + QString::fromStdString(vhour[i]) + ":" + QString::fromStdString(vmin[i]) + ": 00" + "\nTitle:" + QString::fromStdString(vtitle[i]) + "\nReminder:" + QString::fromStdString(vbody[i]) + "\n\n");
    myfile2.close();
    }
}

