#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <iostream>
#include <fstream>
#include <cstring>
#include <string.h>
#include <vector>
#include <iomanip>
#include <stdlib.h>
#include <conio.h>
#include <fstream>
#include <QMainWindow>
#include <QMessageBox>
#include "register.h"
#include "Login.h"
#include "notepad.h"

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    string setUsername;
    string setPassword;

public:
    MainWindow(QWidget *parent = nullptr);
    string getusername(){
        return setUsername;
    }
    string getpassword(){
        return setPassword;
    }
    ~MainWindow();

private slots:
    void on_pushButton_Login_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Notepad *nui;
};
#endif // MAINWINDOW_H
