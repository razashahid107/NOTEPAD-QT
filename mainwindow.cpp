#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_Login_clicked()
{
    QString Email = ui -> lineEdit_email -> text();
    QString Password = ui -> lineEdit_Password -> text();

    string str_email = Email.toStdString();
    string str_password = Password.toStdString();

    Login obj(str_email, str_password);

}




void MainWindow::on_pushButton_clicked()
{
    hide();
    Signup *ui2;
    ui2 = new Signup(this);
    ui2->show();
}

