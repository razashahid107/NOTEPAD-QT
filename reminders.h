#ifndef REMINDERS_H
#define REMINDERS_H

#include <QMainWindow>
#include <QNetworkReply>
#include <qfiledialog.h>
#include <qfile.h>
#include <QJsonDocument>
#include <QVariantMap>
#include <QNetworkRequest>
#include "QNetworkAccessManager"
#include "initialscr.h"

namespace Ui {
class Reminders;
}

class Reminders : public QMainWindow
{
    Q_OBJECT
private:
    std::string username;
public:
    explicit Reminders(QWidget *parent = nullptr);
    ~Reminders();

private slots:


    void on_save_pushButton_clicked();

private:
    Ui::Reminders *ui;
    QNetworkAccessManager *Qman;
};

#endif // REMINDERS_H
