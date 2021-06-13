#include <QtCore/QCoreApplication>
#include <windows.h>
#include <QMessageBox>
#include "mythread.h"

MyThread::MyThread()
{

}

void MyThread::run()
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
    while (1)
    {
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
                            Beep(523,500);
                            sleep(5);
                        }
                    }
                }
            }

        }
        myfile2.close();
        sleep(2);
    }
}
