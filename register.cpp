#include "register.h"
#include "ui_register.h"
#include <functions.h>

Register::Register(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
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
    int pass_length = password.length(), name_length = fname.length();
    int password_check = 1, name_check = 1;

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

    if (!(email_checker(email))){
        ui->statusbar->showMessage("You Entered wrong Email", 4000);
        ui->qtemail->clear();
    }
    if (password_check == 1 && name_check == 1 && email_checker(email) == true)
    {
        dbh = new DatabaseHandler(this);
        dbh->DataEntry(qfname, qsname, qemail, qpassword);
        Save_DataBase(fname, sname, email, password);
        MainWindow *mui;
//        mui = new MainWindow(this);
//        mui->show();
//        hide();
        Notepad *nui;
        nui = new Notepad(this);
        nui->show();
    }
}

Register::~Register()
{
    delete ui;
    delete dbh;
}
