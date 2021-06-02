#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <stdlib.h>
#include <conio.h>
#include<windows.h>
#include <qmessagebox.h>

using namespace std;

class Login
{
private:
    string email, password;
    char pass;
    int npass, char_count = 0;
    vector<char> temp{};
public:
    // we can have a contructor for the login
    bool email_checker(string email) {
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

    Login(string input_email, string input_password);

    bool setEmail(string input_email);

    void setPassword(string input_password);

    string getEmail();

    string getPassword();
};

