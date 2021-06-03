#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <stdlib.h>
#include <conio.h>
#include <qmessagebox.h>
using namespace std;

class Login
{
private:
    string email, password;
    vector<char> temp{};

public:
    // we can have a contructor for the login
    Login(string input_email, string input_password)
    {
        // //cout << "Please enter your login credentials: " << endl;
        // email = input_email;
        while (1) {
            
            if (setEmail(input_email)){
                // future function to be called, if the email and password is correct
                break;
            }
            else if (!(setEmail(input_email))){
                QMessageBox msgBox;
                msgBox.setText("Re-Enter Email");
                msgBox.exec();
               
                if (QMessageBox::Ok){
                    msgBox.close();
                    break;
                }
            }
            
        }
        
        password = input_password;
    }
    // setters and getters
    bool setEmail(string input_email)
    {
        email = input_email;
        if (email_checker(email) == false)
        {
            //cout << "\tEnter your email again";
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

    string getEmail()
    {
        return email;
    }
    string getPassword()
    {
        return password;
    }
};
