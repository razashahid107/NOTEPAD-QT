#ifndef REGISTER_H
#define REGISTER_H

#include <QMainWindow>
#include "mainwindow.h"
#include "notepad.h"
#include "databasehandler.h"

using namespace std;

namespace Ui {
class Register;
}

class Register : public QMainWindow
{
    Q_OBJECT
public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();

private slots:

    void on_Register_button_clicked();

    void on_pushButton_clicked();

private:
    Ui::Register *ui;
    DatabaseHandler *dbh;
};

#endif // REGISTER_H
