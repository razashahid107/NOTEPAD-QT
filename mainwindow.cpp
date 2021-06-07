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
    ui->lineEdit_email->setPlaceholderText("Username");
    ui->lineEdit_Password->setPlaceholderText("Password");
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

    if (!obj.email_checker(str_Username)){
        ui->statusbar->showMessage("You Entered wrong Email", 4000);
        ui->lineEdit_email->clear();
    }

    if (pass_length < 6){
        ui->statusbar->showMessage("Password not entered or less than 6 characters entered", 4000);
        ui->lineEdit_Password->clear();
        password_check = 0;
    }

    if (obj.email_checker(str_Username) && password_check == 1){
        string line, word, temp;
        QDir qdirectory;
        fstream myfile;
        QString qtfilename = qdirectory.currentPath() + "/login.csv";
        string filename = qtfilename.toStdString();
        myfile.open(filename, ios::in);
        vector<string> row;
        while (myfile >> temp) {
        row.clear();
        // read an entire row and
                // store it in a string variable 'line'
                getline(myfile, line);

                // used for breaking words
                stringstream s(line);

                // read every column data of a row and
                // store it in a string variable, 'word'
                while (getline(s, word, ',')) {

                    // add all the column data
                    // of a row to a vector
                    row.push_back(word);
                }
    }
}

void MainWindow::on_pushButton_clicked()
{
    hide();
    Register *mui;
    mui = new Register(this);
    mui->show();
}
