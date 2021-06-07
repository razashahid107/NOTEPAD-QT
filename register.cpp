#include "register.h"
#include "ui_register.h"
#include "functions.h"
#include <cstdio>
#include <QDir>
#include <QtTest>
#include <unistd.h>

Register::Register(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    ui->qtfirstname->setPlaceholderText("First Name");
    ui->qtsecondname->setPlaceholderText("Second Name");
    ui->qtemail->setPlaceholderText("Username");
    ui->qtpassword->setPlaceholderText("Password");
    ui->qtconfirmpassword->setPlaceholderText("Confirm Password");
}

void Register::on_Register_button_clicked()
{
    QString qfname = ui->qtfirstname->text();
    QString qsname = ui->qtsecondname->text();
    QString qusername = ui->qtemail->text();
    QString qpassword = ui->qtpassword->text();
    QString qconfirmpassword = ui->qtconfirmpassword->text();
    string fname =qfname.toStdString();
    string sname =qsname.toStdString();
    string username =qusername.toStdString();
    string password =qpassword.toStdString();
    string confirmpassword= qconfirmpassword.toStdString();
    int pass_length = password.length(), name_length = fname.length();
    int password_check = 1, name_check = 1;
    string line, user_name, temp, garbage, firstname, secondname, pass_word;
    vector<string> row;
    bool check  = false;
    QDir qdirectory;
    fstream myfile;
    QString qtfilename = qdirectory.currentPath() + "/login.csv";
    string filename = qtfilename.toStdString();
    myfile.open(filename, ios::in);
    stringstream s(line);
    string tusername =  " \"" + username + "\"";
    string tpassword =  "\"" + password + "\"";
    while (getline(myfile, user_name, ',')) {
    getline(myfile, garbage, ',');
    getline(myfile, firstname, ',');
    getline(myfile, garbage, ',');
    getline(myfile, pass_word, ',');
    getline(myfile, garbage, ',');
    getline(myfile, secondname, '\n');
    if (user_name == tusername){
           ui->statusbar->showMessage("Username already Exists");
           ui->qtemail->clear();
           check = true;
    }
    }
    myfile.close();

    if (name_length == 0){
        name_check = 0;
        ui->statusbar->showMessage("First Name not entered", 4000);
    }

    if (pass_length < 6){
        ui->statusbar->showMessage("Password or Confirm Password not entered or less than 6 characters entered", 4000);
        ui->qtpassword->clear();
        ui->qtconfirmpassword->clear();
        password_check = 0;
    }

    else if (password != confirmpassword){
        ui->statusbar->showMessage("Password and Confirm Password Mis-match", 4000);
        ui->qtpassword->clear();
        ui->qtconfirmpassword->clear();
        password_check = 0;
    }

    if (username.length() < 3){
        ui->statusbar->showMessage("Total Characters are less than 3 Characters", 4000);
        ui->qtemail->clear();
    }
    if (password_check == 1 && name_check == 1 && check == false)
    {
        dbh = new DatabaseHandler(this);
        dbh->DataEntry(qfname, qsname, qusername, qpassword);
        myfile.close();
        Notepad *nui;
        nui = new Notepad(this);
        nui->show();
        this->hide();
    }
}

Register::~Register()
{
    delete ui;
}

void Register::on_pushButton_clicked()
{
    dbh = new DatabaseHandler(this);
    MainWindow *mui;
    mui = new MainWindow(this);
    mui->show();
    hide();
}
