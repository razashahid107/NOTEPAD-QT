#include <functions.h>
#include "register.h"
#include "ui_register.h"
#include "functions.h"

Register::Register(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    connect(ui->Register_button, SIGNAL(clicked()), this, SLOT(on_Register_button_clicked()));
    ui->label->setStyleSheet("border: 1px solid white;");
    ui->label_2->setStyleSheet("border: 1px solid white;");
    ui->label_3->setStyleSheet("border: 1px solid white;");
    ui->label_4->setStyleSheet("border: 1px solid white;");
    ui->label_5->setStyleSheet("border: 1px solid white;");
    ui->label_6->setStyleSheet("border: 1px solid white;");
    ui->qtfirstname->setPlaceholderText("First Name");
    ui->qtsecondname->setPlaceholderText("Second Name");
    ui->qtemail->setPlaceholderText("Email");
    ui->qtpassword->setPlaceholderText("Password");
    ui->qtconfirmpassword->setPlaceholderText("Confirm Password");
}

Register::~Register()
{
    delete ui;
}

void Register::on_Register_button_clicked()
{
    QString qfname = ui->qtfirstname->text();
    QString qsname = ui->qtsecondname->text();
    QString qemail = ui->qtemail->text();
    QString qpassword = ui->qtpassword->text();
    QString qconfirmpassword = ui->qtconfirmpassword->text();
    //email = ui->secName->text();
    string fname =qfname.toStdString();
    string sname =qsname.toStdString();
    string email =qemail.toStdString();
    string password =qpassword.toStdString();
    string confirmpassword= qconfirmpassword.toStdString();
    if (password != confirmpassword){
        QMessageBox msgBox;
        msgBox.setText("Password mis-match");
        msgBox.exec();
    }
    if (!(email_checker(email))){
        QMessageBox msgBox;
        msgBox.setText("Re-Enter Email");
        msgBox.exec();
    }
    Save_DataBase(fname, sname, email, password);
}



