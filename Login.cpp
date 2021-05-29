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

    void setPassword(string input_password)
    {
        // //cout << "Enter Password: ";
        // for (int i = 0;;)
        // {
        //     pass = getch();
        //     npass = (int)pass;
        //     if (npass >= 20 && npass <= 126 && char_count <= 15)
        //     { //displays asteriks instead of characters to maintain privacy
        //         temp.push_back(pass);
        //         char_count++;
        //         //cout << '*';
        //     }
        //     else if (char_count > 15)
        //     {
        //         //cout << "Maximum Limit reached!\n"; // Checks for maximunm limit
        //         break;
        //     }
        //     else if (npass == 8 && char_count != 0)
        //     {
        //         //cout << '\b' << " " << '\b'; // Makes sure that user can use backspace and backspace do work
        //         temp.pop_back();
        //         char_count--;
        //     }
        //     else if (char_count == 0) // stops to erase the characters already printed
        //         continue;
        //     else
        //     {
        //         //cout << endl;
        //         break;
        //     }
        // }
        password = input_password;
    }

    string getEmail()
    {
        return email;
    }
    string getPassword()
    {
        for (int i = 0; i <= temp.size(); i++)
        {
            //std::cout << temp[i];
        }
    }

    // Adding a friend function to allow it to save the notes in an array
    friend void SaveNote();
};
