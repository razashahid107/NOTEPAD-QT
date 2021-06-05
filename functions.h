// #ifndef FUNCTIONS_H
// #define FUNCTIONS_H
#pragma once
#include <iostream>
#include <fstream>
#include <qdir.h>
#include <QDir>
#include <qfiledialog.h>
#include <qfile.h>
#include <QDebug>
using namespace std;

bool email_checker(string email)
{
    bool atCheck = false;
    bool comCheck = false;

    string temp = ".com";
    int length = email.length();
    for (int i = 0; i < email.length(); i++)
    {
        if (email[i] == '@')
        {
            atCheck = true;
            break;
        }
    }

    if (atCheck == true)
    {
        if (email[email.length() - 5] == '@')
        {
            // cout << "\t=>There is a missing domain in your Email." << endl;
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
        if (code < 38)
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

void Save_DataBase(string F_name, string L_name, string EMail, string password)
{
    // file pointer
    QDir qdirectory;
    fstream fout;
//    QString qdfilename = QFileDialog::getSaveFileName();
//    qDebug() << qdfilename;
    QString qtfilename = qdirectory.currentPath() + "/credentials.csv";
    string filename = qtfilename.toStdString();
    // opens an existing csv file or creates a new file.
    fout.open(filename, ios::out | ios::app);

    // Insert the data to file
    fout << F_name << ", "
         << L_name << ", "
         << EMail << ", "
         << password
         << "\n";
}
// #endif // FUNCTIONS_H

