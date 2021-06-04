#ifndef DATABASEHANDLER_H
#define DATABASEHANDLER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
using namespace std;

class DatabaseHandler : public QObject
{
    Q_OBJECT
private:
    QString Email;
    QString Password;
public:
    explicit DatabaseHandler(QObject *parent = nullptr);
    void DataEntry(QString first_name, QString last_name, QString email, QString password);
    void set_Credentials(QString Email, QString Password ){
        this->Email = Email;
        this->Password = Password;
    }


signals:
public slots:
    bool ReadData();

private:
    QNetworkAccessManager *Qman;
    QNetworkReply *Qreply1;
    QNetworkReply *Qreply2;
};

#endif // DATABASEHANDLER_H
