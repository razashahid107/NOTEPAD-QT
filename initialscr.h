#ifndef INITIALSCR_H
#define INITIALSCR_H

#include <QMainWindow>
#include <fstream>
#include <QDir>
#include "mainwindow.h"

using namespace std;

namespace Ui {
class Initialscr;
}

class Initialscr : public QMainWindow
{
    Q_OBJECT
private:
    std::string username;
    std::string password;

public:
    explicit Initialscr(QWidget *parent = nullptr);
    string getusername(){
        return username;
    }
    string getpassword(){
        return password;
    }
    ~Initialscr();

private slots:
    void on_commandLinkButton_clicked();

private:
    Ui::Initialscr *ui;
};

#endif // INITIALSCR_H
