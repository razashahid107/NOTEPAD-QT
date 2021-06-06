#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowMaximized);
    //ui->label_Email->setStyleSheet("border: 1px solid white;");
    //ui->label_Password->setStyleSheet("border: 1px solid white;");
    ui->groupBox->setPalette(QPalette(Qt::white));
    ui->lineEdit_email->setPlaceholderText("Email");
    ui->lineEdit_Password->setPlaceholderText("Password");
}

MainWindow::~MainWindow()
{
    delete ui;
    qDebug() << "Excellent Work done";

//    delete nui;
}

void MainWindow::on_pushButton_Login_clicked()
{
    QString Email = ui -> lineEdit_email -> text();
    QString Password = ui -> lineEdit_Password -> text();

    string str_email = Email.toStdString();
    string str_password = Password.toStdString();
    int password_check = 1, pass_length= str_password.length();
    Login obj;
//    DatabaseHandler *dbh = new DatabaseHandler();
//    dbh->display();

    if (!obj.email_checker(str_email)){
        ui->statusbar->showMessage("You Entered wrong Email", 4000);
        ui->lineEdit_email->clear();
    }

    if (pass_length < 6){
        ui->statusbar->showMessage("Password not entered or less than 6 characters entered", 4000);
        ui->lineEdit_Password->clear();
        password_check = 0;
    }
    if (obj.email_checker(str_email) && password_check == 1){
//        QDir qdirectory;
//        fstream myfile;
//        QString qtfilename = qdirectory.currentPath() + "/login.csv";
//        string filename = qtfilename.toStdString();
//        myfile.open(filename, ios::in);
        //myfile << "Password," << strfirebasePass << '\n';



    }

}

void MainWindow::on_pushButton_clicked()
{
    hide();
    Register *mui;
    mui = new Register(this);
    mui->show();
}
