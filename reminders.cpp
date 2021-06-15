#include "reminders.h"
#include "ui_reminders.h"
#include <QDesktopServices>

Reminders::Reminders(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Reminders)
{
    ui->setupUi(this);
    this->setWindowTitle("Reminders");
    ui->reminderTitle->setPlaceholderText("Enter Title");
    ui->reminderBody->setPlaceholderText("Enter Reminder");
    this->setWindowState(Qt::WindowMaximized);
    ui->timeEdit->setTime(QTime::currentTime());
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
    QDir qdirec4;
    fstream myfile4;
    QString qtfilename4 = qdirec4.currentPath() + "/Reminders.csv";
    string filename4 = qtfilename4.toStdString();
    myfile4.open(filename4, ios::out | ios::app);
    myfile4 << "Body" << ',' << body.toStdString() << ',' << "DOM" << ','
            << date_day.toStdString() << ','<< "Hour" << ',' << time_hour.toStdString()
            << ',' << "Minute" << ',' << time_min.toStdString() << ',' << "Month" << ','
            << date_month.toStdString() << ',' << "Title" << ',' << title.toStdString()
            << ',' << "Year" << ',' << date_year.toStdString() << '\n';

    ui->saving_msg->setText("Note Saved");
    ui->reminderTitle->clear();
    ui->reminderBody->clear();
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
    myfile << strfirebaseReminders;
    myfile.close();
}

void Reminders::on_exit_pushButton_clicked()
{
    ui->reminderdisplay->clear();
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
    ui->reminderdisplay->appendPlainText(QString::number(i+1) + ".\n" + "Date: " + QString::fromStdString(vdate[i]) + "/" + QString::fromStdString(vmonth[i]) + "/ 2021" + "\tTime:" + QString::fromStdString(vhour[i]) + ":" + QString::fromStdString(vmin[i]) + ": 00" + "\nTitle:" + QString::fromStdString(vtitle[i]) + "\nReminder:" + QString::fromStdString(vbody[i]) + "\n\n");
    myfile2.close();
    }
}


void Reminders::on_pushButton_clicked()
{
    this->hide();
}


void Reminders::on_pushButton_2_clicked()
{
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
    for (int i = 0; i < vdate.size(); i++){
        int ihour = stoi(vhour[i]);
        int imin = stoi(vmin[i]);
        int idate = stoi(vdate[i]);
        int imonth = stoi(vmonth[i]);
        if (imonth == QDate::currentDate().month()){
            if (idate == QDate::currentDate().day()){
                if (ihour == QTime::currentTime().hour()){
                    if (QString::number(imin) == QString::number(QTime::currentTime().minute())){
                        QMessageBox::about(this, QString::fromStdString(vtitle[i]), QString::fromStdString(vbody[i]));
                    }
                }
            }
        }

    }
    myfile2.close();
}
