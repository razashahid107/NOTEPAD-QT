#ifndef REGISTER_H
#define REGISTER_H

#include <QMainWindow>
#include "mainwindow.h"
using namespace std;

namespace Ui {
class Register;
}

class Register : public QMainWindow
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
    explicit Register(QWidget *parent = nullptr);
    ~Register();

private slots:

    void on_Register_button_clicked();

private:
    Ui::Register *ui;
};

#endif // REGISTER_H
