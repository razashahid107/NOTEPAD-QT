#include "register.h"
#include "ui_register.h"
#include "credentials.h"

bool email_checker(string email) {
    bool atCheck = false;
    bool comCheck = false;

    string temp = ".com";
    int length = email.length();
    for (int i = 0; i < email.length(); i++)
    {
        if (email[i] == '@')
        {
            atCheck = true;
            break;
        }
    }

    if (atCheck == true)
    {
        if (email[email.length() - 5] == '@')
        {
            // cout << "\t=>There is a missing domain in your Email." << endl;
            return false;
        }
        comCheck = true; // setting this true temporarily so that the following if function works properly
        for (int i = 4; i > 0; i--)
        {
            if (email[length - i] == temp[4 - i])
            {
                continue;
            }
            else
            {
                comCheck = false;
                break;
            }
        }
    }
    if (atCheck && comCheck)
    {
        return true;
    }
    else
    {
        return false;
    }
}

string encr(string str)
{
    int code, count = 0;
    vector<int> veccode{};
    int length = str.size();
    char ch[length + 1];
    vector<char> vecstr{};
    vector<char> vecenc{};
    strcpy(ch, str.c_str());

    for (int i = 0; i < length; i++)
    {
        vecstr.push_back(ch[i]);
    }

    for (int i = 0; i < vecstr.size(); i++)
    {
        code = (int)vecstr[i];
        if (code < 38)
        {
            veccode.push_back('f');
            veccode.push_back('#');
            veccode.push_back('f');
            veccode.push_back(code);
            count++;
        }
        else
            veccode.push_back(code - 5);
    }
    for (int i = 0; i < vecstr.size() + count * 3; i++)
    {
        vecenc.push_back((char)veccode[i]);
    }
    string f_str(vecenc.begin(), vecenc.end());
    return f_str;
}


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

void Save_DataBase(string F_name, string L_name, string EMail, string password)
{
   // file pointer
   fstream fout;

   // opens an existing csv file or creates a new file.
   fout.open("credentials.csv", ios::out | ios::app);

   string name;
//   QString error = QString::fromStdString(name);
//   QMessageBox msg1;
//   msg1.setText(error);
//   msg1.exec();
   // Insert the data to file
   fout << F_name << ", "
        << L_name << ", "
        << EMail << ", "
        << password
        << "\n";
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
    Save_DataBase(email, password, fname, sname);
}

