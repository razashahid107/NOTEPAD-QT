#include "register.h"
#include "ui_register.h"

Register::Register(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
}

Register::~Register()
{
    delete ui;
}

void Register::on_Registerbutton_clicked()
{
    QString qfname, qsname, qemail, qpassword, qconfirmpassword;
    qfname = ui->qtfirstname->text();
    qsname = ui->qtsecondname->text();
    qemail = ui->qtemail->text();
    qpassword = ui->qtpassword->text();
    qconfirmpassword = ui->qtconfirmpassword->text();
    //email = ui->secName->text();
    string fname =qfname.toStdString();
    string sname =qsname.toStdString();
    string email =qemail.toStdString();
    string password =qpassword.toStdString();
    string confirmpassword= qconfirmpassword.toStdString();
    fsave();
}

string Register::encr(string str){
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

void Register::fsave(){
    ofstream myfile;
    myfile.open("credentials.csv");
    myfile << encr(first_name) << ',' << encr(second_name) << ',' << encr(Email) << ',' << encr(Password) << ',' << encr(con_Password); //<< ',' << month_birth << ','
    //<< year_birth;
    myfile.close();
 }

