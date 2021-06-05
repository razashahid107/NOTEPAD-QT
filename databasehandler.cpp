#include "databasehandler.h"
#include <QJsonDocument>
#include <QVariantMap>
#include <QNetworkRequest>
using namespace std;

DatabaseHandler::DatabaseHandler(QObject *parent) : QObject(parent)
{
    Qman = new QNetworkAccessManager(this);
    Qreply1 = Qman -> get(QNetworkRequest(QUrl("https://practice-e90c6-default-rtdb.firebaseio.com/New_Entry/Email.json")));
    connect(Qreply1, &QNetworkReply::readyRead, this, &DatabaseHandler::ReadData);
    Qreply2 = Qman -> get(QNetworkRequest(QUrl("https://practice-e90c6-default-rtdb.firebaseio.com/New_Entry/Password.json")));
    connect(Qreply2, &QNetworkReply::readyRead, this, &DatabaseHandler::ReadData);
}

void DatabaseHandler::DataEntry(QString first_name, QString last_name, QString email, QString password)
{
    QVariantMap newEntry;
    newEntry ["First Name"] = first_name;
    newEntry ["Second Name"] = last_name;
    newEntry ["Email"] = email;
    newEntry ["Password"] = password;
    QJsonDocument enterDocs = QJsonDocument::fromVariant(newEntry);
    QNetworkRequest qreq(QUrl("https://practice-e90c6-default-rtdb.firebaseio.com/New_Entry.json"));
    qreq.setHeader(QNetworkRequest::ContentTypeHeader, QString("application/json"));
    Qman -> put (qreq, enterDocs.toJson());
}

DatabaseHandler::~DatabaseHandler()
{
    delete Qman;
    delete Qreply1;
    delete Qreply2;
}

bool DatabaseHandler::ReadData()
{
      qDebug() << "yahan tuk tou theek";
      //QString str1 = Qreply1 -> readAll();
      qDebug() << Qreply1 -> readAll();
      //QString str2 = Qreply2 -> readAll();
      qDebug() << Qreply2 -> readAll();

//      QString Password_URL = "https://practice-e90c6-default-rtdb.firebaseio.com/New_Entry/Password.json";
//      Qreply = Qman -> get(QNetworkRequest(QUrl(Password_URL)));
//      QString qpass =  Qreply -> readAll();

//      if (qemail == Email){
//          qDebug() << true << Qreply -> readAll();
//          return true;
//      }
//      else {
//          qDebug() << false << Qreply -> readAll();
//          return false;
//      }
}
