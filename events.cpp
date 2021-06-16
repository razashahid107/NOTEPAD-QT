#include "events.h"
#include "ui_events.h"
#include <QDebug>
#include <QDir>
#include<stdio.h>
#include<stdlib.h>
Events::Events(QWidget *parent) : QDialog(parent),
                                  ui(new Ui::Events)
{
    ui->setupUi(this);
    this->setWindowTitle("Events");
    ui->Current_Event->setPlaceholderText("Add a New Event");
//    QString path = "C:/Users/User/OneDrive - National University of Sciences & Technology/Uni STUDY/Semester 2/OOP/OOP Proj/NOTEPAD 2/NOTEPAD-QT/SampleEvents"; // assume it is some path
    QString path = QDir::currentPath();
    qDebug() << "PATH:     " << path;
    QFile _file( path );
    QDir _dir;

    // check if "scripts" folder exists
    int _dirExists = _dir.exists(  "SampleEvents" );
    // if not, create it
    if( !_dirExists )
        _dir.mkdir( "SampleEvents" );

//    QString finalPath = QDir(QDir::currentPath()).filePath("/SampleEvents");
    QString latest_path = QDir::currentPath() + "/SampleEvents";
    qDebug() << "Latest Path: " << latest_path;

    QDir dir(latest_path);
    dir.setFilter(QDir::AllEntries | QDir::NoDotAndDotDot);
    int total_files = dir.count();
    qDebug() << "total files: " << total_files;

    if (total_files < 2)
    {
        //        ui->Prev_Note_label->setText(text);
        ui->label_2->setPlainText("No previous events exist. Create your first Event :)");
    }
    else
    {
        int counter = -1;
        fstream newfile;
        string current_path = QDir::currentPath().toStdString() + "/SampleEvents";

        string counter_Address = current_path + "/counter.txt";
        // opens counter.txt where the counter exists for filename
        newfile.open(counter_Address, ios::in); //open counter to perform read
        if (newfile.is_open())
        { //checking whether the file is open
            string tp;
            getline(newfile, tp); //read num from counter and open tht number file.txt.
            counter = stoi(tp);
            newfile.close(); //close the file object.
        }
        string Address = latest_path.toStdString()  + "/" + to_string(counter - 1) + ".txt";
        qDebug() << " Address :" << QString::fromStdString((Address));
        fstream myfile;
        myfile.open(Address, ios::in);
        string tp;
        if (myfile.is_open())
        {
            while (getline(myfile, tp))
            {             //read data from file object and put it into string.
                tp += tp;
            }
            qDebug() << "string loaded " << QString::fromStdString((tp));

            ui->label_2->setPlainText(QString::fromStdString((tp)));
            myfile.close();
        }


    }
}

Events::~Events()
{
    delete ui;
}

void Events::on_reminderTitle_blockCountChanged(int newBlockCount)
{
    QDir Location;
    Location.currentPath();
}

void Events::on_pushButton_clicked()
{

    int counter = -1;
    fstream newfile;
    fstream fout;
    string current_path = QDir::currentPath().toStdString();
    string counter_Address = current_path + "/SampleEvents/counter.txt";
    // opens counter.txt where the counter exists for filename
    newfile.open(counter_Address, ios::in); //open counter to perform read
    if (newfile.is_open())
    { //checking whether the file is open
        string tp;
        getline(newfile, tp); //read data from file object and put it into string.
        counter = stoi(tp);
        newfile.close(); //close the file object.
    }
    newfile.open(counter_Address, ios::out);
    if (newfile.is_open())
    {
        newfile << to_string(counter + 1); // updating counter in counter.txt
        newfile.close();
    }

    // writing event in file
    string Address = current_path + "/SampleEvents/" + to_string(counter) + ".txt";
    fout.open(Address, ios::out);

    // Insert the data to file
    QString Data = ui->Current_Event->toPlainText();
    //        qDebug() << Data;
    string strData = Data.toStdString();
    fout << strData;
}

void Events::on_pushButton_2_clicked()
{
    fstream newfile;
    int counter = -1;
    string current_path = QDir::currentPath().toStdString() + "/SampleEvents";
    string counter_Address = current_path + "/counter.txt";
    // opens counter.txt where the counter exists for filename
    newfile.open(counter_Address, ios::in); //open counter to perform read
    if (newfile.is_open())
    { //checking whether the file is open
        string tp;
        getline(newfile, tp); //read num from counter and open tht number file.txt
        counter = stoi(tp);
        newfile.close(); //close the file object.
    }
    string Address = current_path + "/" + to_string(counter - 1) + ".txt";
    fstream myfile;
    newfile.open(Address, ios::out);
    if (newfile.is_open())
    {
        QString tp = ui->Current_Event->toPlainText();
        newfile << tp.toStdString();
        newfile.close();
    }
}




void Events::on_pushButton_3_clicked()
{
    fstream newfile;
    int counter = -1;
    string current_path = QDir::currentPath().toStdString() + "/SampleEvents";
    string counter_Address = current_path + "/counter.txt";
    // opens counter.txt where the counter exists for filename
    newfile.open(counter_Address, ios::out); //open counter to perform read
    if (newfile.is_open())
    { //checking whether the file is open
        string tp;
        getline(newfile, tp); //read num from counter and open tht number file.txt
        counter = stoi(tp);
        counter--;
        newfile << to_string(counter);
        newfile.close(); //close the file object.
    }
    string Address = current_path + "/" + to_string(counter) + ".txt";
    QString x = QString::fromStdString(Address);
    QFile file (x);
    file.remove();
    newfile.open(Address, ios::out);
    if (newfile.is_open())
    {
        QString tp = ui->Current_Event->toPlainText();
        newfile << tp.toStdString();
        newfile.close();
    }
}

