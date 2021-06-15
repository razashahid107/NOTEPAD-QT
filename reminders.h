#ifndef REMINDERS_H
#define REMINDERS_H

#include <QDialog>
#include <QNetworkReply>
#include <qfiledialog.h>
#include <qfile.h>
#include <QJsonDocument>
#include <QVariantMap>
#include <QNetworkRequest>
#include <fstream>
#include <QMessageBox>
#include <QNetworkAccessManager>
#include "initialscr.h"
#include "iostream"
#include "dashboard.h"

namespace Ui {
class Reminders;
}

class Reminders : public QDialog
{
    Q_OBJECT
private:
    std::string setUsername;
    std::string setPassword;
    std::string username;
public:
    explicit Reminders(QWidget *parent = nullptr);
    void ReadReminders();
    ~Reminders();

private slots:

    void on_save_pushButton_clicked();

    void on_exit_pushButton_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


private:
    Ui::Reminders *ui;
    QNetworkAccessManager *Qman;
    QNetworkReply *Qreply2;
};

#endif // REMINDERS_H
