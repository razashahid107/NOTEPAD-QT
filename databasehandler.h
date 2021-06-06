#ifndef DATABASEHANDLER_H
#define DATABASEHANDLER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <qfiledialog.h>
#include <qfile.h>
using namespace std;

class DatabaseHandler : public QObject
{
    Q_OBJECT
private:
    QString Email;
    QString Password;
    QString firebaseEmail;
    QString firebasepassword;

public:
    explicit DatabaseHandler(QObject *parent = nullptr);
    void DataEntry(QString first_name, QString last_name, QString email, QString password);
    void display(){}
    ~DatabaseHandler();

signals:
public slots:
    bool ReadEmail();
    bool ReadPass();

private:
    QNetworkAccessManager *Qman;
    QNetworkReply *Qreply1;
    QNetworkReply *Qreply2;
};
#endif // DATABASEHANDLER_H
