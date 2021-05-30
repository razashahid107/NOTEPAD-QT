#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>
#include "mainwindow.h"
using namespace std;

namespace Ui {
class Signup;
}

class Signup : public QDialog
{
    Q_OBJECT
private:
    string first_name;
    string second_name;
    string Email;
    string Password;
    string con_Password;
    int day_birth;
    int month_birth;
    int year_birth;
    ofstream myfile;
public:
    explicit Signup(QWidget *parent = nullptr);
    void new_entry(string first_name, string second_name, string Email, string Password, string con_Password){
            this->first_name = first_name;
            this->second_name = second_name;
            this->Email = Email;
            this->Password = Password;
            this->con_Password = con_Password;
    }
    void fsave();
    string encr(string str);
    ~Signup();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Signup *ui;
};

#endif // SIGNUP_H
