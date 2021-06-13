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
    ~Initialscr();

private slots:

    void Readconting();

    void on_pushButton_clicked();

private:
    Ui::Initialscr *ui;
    QNetworkAccessManager *Qman;
    QNetworkReply *Qreply1;
};

#endif // INITIALSCR_H
