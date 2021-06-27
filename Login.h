#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <stdlib.h>
#include <qmessagebox.h>
#include "mainwindow.h"
#include "databasehandler.h"
#include "notepad.h"

using namespace std;

class Login
{
private:
    string email, password;
    vector<char> temp{};

public:
    // we can have a contructor for the login
    // setters and getters
    bool setEmail(string input_email)
    {
        email = input_email;
        if (email_checker(email) == false)
        {
            return false;
        }
        return true;
    }

    bool email_checker(string email)
    {
        bool atCheck = false;
        bool comCheck = false;

        string temp = ".com";
        int length = email.length();
        for (int i = 0; i < length; i++)
        {
            if (email[i] == '@')
            {
                atCheck = true;
                break;
            }
        }

        if (atCheck == true)
        {
            if (email[email.length() - 5 ] == '@'){
                return false;
            }
            comCheck = true; // setting this true temporarily so that the following if function works properly
            for (int i = 4; i > 0; i--)
            {
                if (email[length - i] == temp[4 - i])
                {
                    continue;
                }
                else
                {
                    comCheck = false;
                    break;
                }
            }
        }
        if (atCheck && comCheck)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    string getEmail()
    {
        return email;
    }

    string getPassword()
    {
        return password;
    }


    string encr(string str)
    {
        int code, count = 0;
        vector<int> veccode{};
        int length = str.size();
        char ch[length + 1];
        vector<char> vecstr{};
        vector<char> vecenc{};
        strcpy(ch, str.c_str());

        for (int i = 0; i < length; i++)
        {
            vecstr.push_back(ch[i]);
        }

        for (int i = 0; i < vecstr.size(); i++)
        {
            code = (int)vecstr[i];
            if (code < 38 || code == 49)
            {
                veccode.push_back('f');
                veccode.push_back('#');
                veccode.push_back('f');
                veccode.push_back(code);
                count++;
            }
            else
                veccode.push_back(code - 5);
        }
        for (int i = 0; i < vecstr.size() + count * 3; i++)
        {
            vecenc.push_back((char)veccode[i]);
        }
        string f_str(vecenc.begin(), vecenc.end());
        return f_str;
    }

    string decrypt(string str)
    {
        int code, count = 0;
        vector<int> veccode{};
        int length = str.size();
        char ch[length + 1];
        vector<char> vecstr{};
        vector<char> vecdec{};
        strcpy(ch, str.c_str());

        for (int i = 0; i < length; i++)
        {
            vecstr.push_back(ch[i]);
        }

        for (int i = 0; i < length; ++i)
        {
            if ((ch[i] == 'f') && (ch[i+1] == '#') && (ch[i+2] == 'f') ) {

                code = (int)vecstr[i+3];
                veccode.push_back(code);
                i += 3;
                count++;
            }
            else {
                code = (int)vecstr[i];
                veccode.push_back(code +5);
            }
        }

        for (int i = 0; i < vecstr.size() - count * 3; i++)
        {
            vecdec.push_back((char)veccode[i]);
        }

        string f_str(vecdec.begin(), vecdec.end());
        return f_str;
    }

    void setremainderno(string username, int number){
        qDebug() << number;
        QNetworkAccessManager *Qman;
        Qman = new QNetworkAccessManager();
        QVariantMap newEntry;
        newEntry ["Number"] = number+1;
        QJsonDocument  docs = QJsonDocument::fromVariant(newEntry);
        string strURL = "https://practice-e90c6-default-rtdb.firebaseio.com/Counting/" + username +".json";
        QString URL = QString::fromStdString(strURL);
        QNetworkRequest qreq((QUrl(URL)));
        qreq.setHeader(QNetworkRequest::ContentTypeHeader, QString("application/json"));
        Qman->put(qreq, docs.toJson());
    }
};
