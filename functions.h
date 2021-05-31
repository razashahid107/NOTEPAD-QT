#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "mainwindow.h"
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
        if (email[email.length() - 5 ] == '@'){
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
#endif // FUNCTIONS_H
