#include "signup.h"
#include "ui_signup.h"
#include <fstream>
#include <QDebug>
Signup::Signup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Signup)
{
    ui->setupUi(this);
}

Signup::~Signup()
{
    delete ui;
}

void Signup::on_pushButton_clicked()
{
    QString qfname, qsname, qemail, qpassword, qconfirmpassword;
    qfname = ui->qtfName->text();
    qsname = ui->qtsName->text();
    qemail = ui->qtEmail->text();
    qpassword = ui->qtPassword->text();
    qconfirmpassword = ui->qtconPassword->text();
    //email = ui->secName->text();
    string fname =qfname.toStdString();
    string sname =qsname.toStdString();
    string email =qemail.toStdString();
    string password =qpassword.toStdString();
    string confirmpassword= qconfirmpassword.toStdString();
    QMessageBox msg2;
    new_entry(fname, sname, email, password, confirmpassword);
    fsave();
}

string Signup::encr(string str){
    int code, count = 0;
    vector<int> veccode {};
    int length = str.size();
    char ch[length +1];
    vector<char> vecstr {};
    vector<char> vecenc {};
    strcpy(ch, str.c_str());

    for (int i = 0; i < length; i++){
        vecstr.push_back(ch[i]);
    }

    for (int i = 0; i < vecstr.size(); i++){
        code = (int)vecstr[i];
        if (code < 38){
            veccode.push_back('f');
            veccode.push_back('#');
            veccode.push_back('f');
            veccode.push_back(code);
            count++;
        }
        else
        veccode.push_back(code - 5 );
    }
    for (int i = 0; i < vecstr.size() + count * 3; i++){
        vecenc.push_back((char)veccode[i]);
    }
    string f_str(vecenc.begin(), vecenc.end());
    return f_str;
}

void Signup::fsave(){
    ofstream myfile;
    myfile.open("credentials.csv");
    myfile << encr(first_name) << ',' << encr(second_name) << ',' << encr(Email) << ',' << encr(Password) << ',' << encr(con_Password); //<< ',' << month_birth << ','
    //<< year_birth;
    myfile.close();
 }



