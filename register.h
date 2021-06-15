#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>
#include "welcome.h"
#include <databasehandler.h>

namespace Ui {
class Register;
}

class Register : public QDialog
{
    Q_OBJECT
public:
    explicit Register(QWidget *parent = nullptr);
    QString getUserName();
    ~Register();

private slots:


    void on_pushButton_2_clicked();

    void on_Register_button_2_clicked();

private:
    Ui::Register *ui;
    DatabaseHandler *dbh;
};

#endif // REGISTER_H
