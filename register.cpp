#include "register.h"
#include "ui_register.h"

Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->setWindowState(Qt::WindowMaximized);
    ui->qtfirstname_2->setPlaceholderText("First Name");
    ui->qtsecondname_2->setPlaceholderText("Second Name");
    ui->qtemail_2->setPlaceholderText("Username");
    ui->qtpassword_2->setPlaceholderText("Password");
    ui->qtconfirmpassword_2->setPlaceholderText("Confirm Password");
}

QString Register::getUserName(){
    return ui->qtemail_2->text();
}

void Register::on_Register_button_2_clicked()
{
    QString qfname = ui->qtfirstname_2->text();
    QString qsname = ui->qtsecondname_2->text();
    QString qusername = ui->qtemail_2->text();
    QString qpassword = ui->qtpassword_2->text();
    QString qconfirmpassword = ui->qtconfirmpassword_2->text();
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
           ui->statusbar->setText("Username already Exists");
           ui->qtemail_2->clear();
           check = true;
        }
    }
    myfile.close();

    if (name_length == 0){
        name_check = 0;
        ui->statusbar->setText("First Name not entered");
    }

    if (pass_length < 6){
        ui->statusbar->setText("Password or Confirm Password not entered or less than 6 characters entered");
        ui->qtpassword_2->clear();
        ui->qtconfirmpassword_2->clear();
        password_check = 0;
    }

    else if (password != confirmpassword){
        ui->statusbar->setText("Password and Confirm Password Mis-match");
        ui->qtpassword_2->clear();
        ui->qtconfirmpassword_2->clear();
        password_check = 0;
    }

    if (username.length() < 3){
        ui->statusbar->setText("Total Characters are less than 3 Characters");
        ui->qtemail_2->clear();
    }
    if (password_check == 1 && name_check == 1 && check == false)
    {
        dbh = new DatabaseHandler(this);
        dbh->DataEntry(qfname, qsname, qusername, qpassword);
        myfile.close();
        this->hide();
        Welcome nui;
        nui.setModal(true);
        nui.exec();
    }
}

Register::~Register()
{
    delete ui;
}

void Register::on_pushButton_2_clicked()
{
    dbh = new DatabaseHandler(this);
    this->hide();
    MainWindow mui;
    mui.setModal(true);
    mui.exec();
}
