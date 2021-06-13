#ifndef REMINDERS_H
#define REMINDERS_H

#include <QMainWindow>
#include <QNetworkReply>
#include <qfiledialog.h>
#include <qfile.h>
#include <QJsonDocument>
#include <QVariantMap>
#include <QNetworkRequest>
#include <fstream>
#include "QNetworkAccessManager"
#include "initialscr.h"
#include "iostream"

namespace Ui {
class Reminders;
}

class Reminders : public QMainWindow
{
    Q_OBJECT
private:
    std::string setUsername;
    std::string setPassword;
    std::string username;
public:
    explicit Reminders(QWidget *parent = nullptr);
    ~Reminders();

private slots:

    void ReadReminders();

    void on_save_pushButton_clicked();

    void on_exit_pushButton_clicked();

private:
    Ui::Reminders *ui;
    QNetworkAccessManager *Qman;
    QNetworkReply *Qreply2;
};

#endif // REMINDERS_H
