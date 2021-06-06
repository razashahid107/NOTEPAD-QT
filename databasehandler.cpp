#include "databasehandler.h"
#include <QJsonDocument>
#include <QVariantMap>
#include <QNetworkRequest>
#include <fstream>
#include <QDir>
using namespace std;

DatabaseHandler::DatabaseHandler(QObject *parent) : QObject(parent)
{
    Qman = new QNetworkAccessManager(this);
    Qreply1 = Qman -> get(QNetworkRequest(QUrl("https://practice-e90c6-default-rtdb.firebaseio.com/New_Entry/Email.json")));
    connect(Qreply1, &QNetworkReply::readyRead, this, &DatabaseHandler::ReadEmail);
    Qreply2 = Qman -> get(QNetworkRequest(QUrl("https://practice-e90c6-default-rtdb.firebaseio.com/New_Entry/Password.json")));
    connect(Qreply2, &QNetworkReply::readyRead, this, &DatabaseHandler::ReadPass);
}

void DatabaseHandler::DataEntry(QString first_name, QString last_name, QString email, QString password)
{
    QVariantMap newEntry;
    newEntry ["First Name"] = first_name;
    newEntry ["Second Name"] = last_name;
    //newEntry ["Email"] = email;
    newEntry ["Password"] = password;
    QJsonDocument enterDocs = QJsonDocument::fromVariant(newEntry);
    QString URL = "https://practice-e90c6-default-rtdb.firebaseio.com/" + email + ".json";
    QNetworkRequest qreq((QUrl(URL)));
    qreq.setHeader(QNetworkRequest::ContentTypeHeader, QString("application/json"));
    Qman -> put (qreq, enterDocs.toJson());
}

DatabaseHandler::~DatabaseHandler()
{
    delete Qman;
    delete Qreply1;
    delete Qreply2;
}

bool DatabaseHandler::ReadEmail()
{
    firebaseEmail = Qreply1 -> readAll();
    QDir qdirectory;
    fstream myfile;
    QString qtfilename = qdirectory.currentPath() + "/login.csv";
    qDebug() << qtfilename;
    string filename = qtfilename.toStdString();
    myfile.open(filename, ios::out | ios::app);
    string strfirebaseEmail = firebaseEmail.toStdString();
    myfile << "Email," << strfirebaseEmail << '\n';
    qDebug() << firebaseEmail;
}

bool DatabaseHandler::ReadPass()
{
    firebasepassword = Qreply2 -> readAll();
    QDir qdirectory;
    fstream myfile;
    QString qtfilename = qdirectory.currentPath() + "/login.csv";
    qDebug() << qtfilename;
    string filename = qtfilename.toStdString();
    myfile.open(filename, ios::out | ios::app);
    string strfirebasePass = firebasepassword.toStdString();
    myfile << "Password," << strfirebasePass << '\n';
    qDebug() << firebasepassword;
}
