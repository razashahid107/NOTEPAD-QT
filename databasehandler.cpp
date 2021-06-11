#include "databasehandler.h"

using namespace std;

DatabaseHandler::DatabaseHandler(QObject *parent) : QObject(parent)
{
    Qman = new QNetworkAccessManager(this);
    // QNetworkAccessManger uploads the data to the .json file in the link belwo
    // QNetworkManager enstablishes connection with firebase
    Qreply1 = Qman->get(QNetworkRequest(QUrl("https://practice-e90c6-default-rtdb.firebaseio.com/.json")));
    connect(Qreply1, &QNetworkReply::readyRead, this, &DatabaseHandler::ReadData);
}

void DatabaseHandler::DataEntry(QString first_name, QString last_name, QString username, QString password)
{
    // converts data to JSON files
    QVariantMap newEntry;
    newEntry["First Name"] = first_name;
    newEntry["Second Name"] = last_name;
    //newEntry ["Email"] = email;
    newEntry["Password"] = password;
    // creating a json file
    QJsonDocument enterDocs = QJsonDocument::fromVariant(newEntry);
    string strusername = username.toStdString();
    string strURL = "https://practice-e90c6-default-rtdb.firebaseio.com/" + strusername + ".json";
    QString URL = QString::fromStdString(strURL);
    // uploads the username to the url
    QNetworkRequest qreq((QUrl(URL)));
    qreq.setHeader(QNetworkRequest::ContentTypeHeader, QString("application/json"));
    Qman->put(qreq, enterDocs.toJson());
}

DatabaseHandler::~DatabaseHandler()
{
    delete Qman;
    delete Qreply1;
    delete Qreply2;
}

bool DatabaseHandler::ReadData()
{
    firebaseEmail = Qreply1->readAll();
    QDir qdirectory;
    fstream myfile;
    QString qtfilename = qdirectory.currentPath() + "/login.csv";
    string filename = qtfilename.toStdString();
    myfile.open(filename, ios::out);
    string strfirebaseEmail = firebaseEmail.toStdString();
    for (int i = 0; i < strfirebaseEmail.length(); i++)
    {
        if (strfirebaseEmail[i] == '{')
        {
            strfirebaseEmail[i] = ' ';
        }

        else if (strfirebaseEmail[i] == ':')
        {
            strfirebaseEmail[i] = ',';
        }
        else if (strfirebaseEmail[i] == '}' && strfirebaseEmail[i + 1] == ',')
        {
            strfirebaseEmail[i] = '\n';
            strfirebaseEmail[i + 1] = ' ';
        }
        else if (strfirebaseEmail[i] == '}' && strfirebaseEmail[i + 1] == '}')
        {
            strfirebaseEmail[i] = '\n';
        }
        else if (strfirebaseEmail[i] == '}')
        {
            strfirebaseEmail[i] = ',';
        }
    }
    myfile << strfirebaseEmail << '\n';
    myfile.close();
}
