#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <stdlib.h>
#include <conio.h>
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

    void setcredentials(QString email, QString Password){
        DatabaseHandler *dbh1 = new DatabaseHandler();
        dbh1->set_Credentials(email, Password);
        if (dbh1->ReadData() == true){
        Notepad *nui = new Notepad();
        nui->show();
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
};
