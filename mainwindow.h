#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <iostream>
#include <fstream>
#include <cstring>
#include <string.h>
#include <vector>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <QMessageBox>
#include "register.h"
#include "Login.h"
#include "dashboard.h"

using namespace std;
#include <QDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QDialog
{
    Q_OBJECT
private:
    string setUsername;
    string setPassword;
    string number;

public:
    MainWindow(QWidget *parent = nullptr);
    void setNumber(string no){
        number = no;
    }
    string getNumber(){
        qDebug() << QString::fromStdString(number);
        return number;
    }
    void Readconting();
    ~MainWindow();

private slots:
    void on_pushButton_Login_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *Qman;
    QNetworkReply *Qreply1;
};
#endif // MAINWINDOW_H
