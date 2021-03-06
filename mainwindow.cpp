#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Signin");
    this->setWindowState(Qt::WindowMaximized);
    ui->groupBox->setPalette(QPalette(Qt::white));
    ui->lineEdit_email->setPlaceholderText("Username");
    ui->lineEdit_Password->setPlaceholderText("Password");
    DatabaseHandler *dbh = new DatabaseHandler();
    dbh->display();
}

void MainWindow::Readconting()
{
    QString firebaseReminders = Qreply1->readAll();
    qDebug() << firebaseReminders;
    QDir qdirectory;
    fstream myfile;
    QString qtfilename = qdirectory.currentPath() + "/number.txt";
    string filename = qtfilename.toStdString();
    myfile.open(filename, ios::out);
    myfile << firebaseReminders.toStdString();
    myfile.close();
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
        ui->lineEdit_Password->clear();
        password_check = 0;
    }

    if (password_check == 1){
        string line, username, temp, garbage, firstname, secondname, password, Number;
        bool check = false;
        QDir qdirectory;
        fstream myfile;
        QString qtfilename = qdirectory.currentPath() + "/login.csv";
        string filename = qtfilename.toStdString();
        myfile.open(filename, ios::in);
        str_Username =  " \"" + str_Username + "\"";
        str_password =  "\"" + str_password + "\"";
        while (getline(myfile, username, ',') && check == false) {
            getline(myfile, garbage, ',');
            getline(myfile, firstname, ',');
            getline(myfile, garbage, ',');
            getline(myfile, Number, ',');
            getline(myfile, garbage, ',');
            getline(myfile, password, ',');
            getline(myfile, garbage, ',');
            getline(myfile, secondname, '\n');
            if (username == str_Username){
                check = true;
                if(password == str_password){
                    this->hide();
                    DashBoard dsb;
                    dsb.setModal(true);
                    dsb.exec();
                }
                else{
                    ui->label_2->setText("Wrong Password");
                }
            }
            else {
                ui->label->setText("Username or Password is Incorrect");
            }
        }
        myfile.close();
     }
    fstream myfile3;
    QDir qdirectory2;
    QString qtfilename = qdirectory2.currentPath() + "/initialscrcheck.csv";
    string filename2 = qtfilename.toStdString();
    myfile3.open(filename2, ios::out);
    setUsername = Username.toStdString();
    setPassword = Password.toStdString();
    Login lg;
    myfile3 << lg.encr(Username.toStdString()) << ',' << lg.encr(Password.toStdString()) << '\n';
    Qman = new QNetworkAccessManager(this);
    Qreply1 = Qman->get(QNetworkRequest(QUrl("https://practice-e90c6-default-rtdb.firebaseio.com/Counting/" + QString::fromStdString(setUsername) + "/Number" + ".json")));
    connect(Qreply1, &QNetworkReply::readyRead, this, &MainWindow::Readconting);
}

void MainWindow::on_pushButton_clicked()
{
    hide();
    Register mui;
    mui.setModal(true);
    mui.exec();
}
