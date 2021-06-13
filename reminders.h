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
#include "dashboard.h"

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

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_actionSave_triggered();

    void on_actionDisplay_Reminders_triggered();

    void on_actionExit_Reminders_triggered();

    void on_actionNotes_triggered();

    void on_actionEvents_triggered();

    void on_actionNo_Help_triggered();

private:
    Ui::Reminders *ui;
    QNetworkAccessManager *Qman;
    QNetworkReply *Qreply2;
};

#endif // REMINDERS_H
