#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowMaximized);
    ui->groupBox->setPalette(QPalette(Qt::white));
    ui->lineEdit_email->setPlaceholderText("Username");
    ui->lineEdit_Password->setPlaceholderText("Password");
    DatabaseHandler *dbh = new DatabaseHandler();
    dbh->display();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Login_clicked()
{
    QString Username = ui -> lineEdit_email -> text();
    QString Password = ui -> lineEdit_Password -> text();

    string str_Username = Username.toStdString();
    string str_password = Password.toStdString();
    int password_check = 1, pass_length= str_password.length();
    Login obj;


    if (pass_length < 6){
        ui->statusbar->showMessage("Password not entered or less than 6 characters entered", 4000);
        ui->lineEdit_Password->clear();
        password_check = 0;
    }

    if (password_check == 1){
        string line, username, temp, garbage, firstname, secondname, password;
        vector<string> row;
        bool check = false;
        QDir qdirectory;
        fstream myfile;
        QString qtfilename = qdirectory.currentPath() + "/login.csv";
        string filename = qtfilename.toStdString();
        myfile.open(filename, ios::in);
        stringstream s(line);
        str_Username =  " \"" + str_Username + "\"";
        str_password =  "\"" + str_password + "\"";
        while (getline(myfile, username, ',') && check == false) {
            getline(myfile, garbage, ',');
            getline(myfile, firstname, ',');
            getline(myfile, garbage, ',');
            getline(myfile, password, ',');
            getline(myfile, garbage, ',');
            getline(myfile, secondname, '\n');
            if (username == str_Username){
                check = true;
                if(password == str_password){
                    nui = new Notepad(this);
                    nui->show();
                    this->hide();
                }
                else{
                    ui->label_wronpassword->setText("Wrong Password");
                    ui->statusbar->showMessage("Please Enter correct Password", 5000);
                }
            }
            else {
                ui->label->setText("Username or Password is Incorrect");
                ui->statusbar->showMessage("Please Enter correct Username and Password", 5000);
            }
        }
        myfile.close();
     }
}

void MainWindow::on_pushButton_clicked()
{
    hide();
    Register *mui;
    mui = new Register(this);
    mui->show();
    this->hide();
}
