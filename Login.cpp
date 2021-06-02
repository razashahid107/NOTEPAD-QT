#include "credentials.h"
#include "Login.h"

// we can have a contructor for the login
Login::Login(string input_email, string input_password)
{
    // //cout << "Please enter your login credentials: " << endl;
    // email = input_email;
    while (1)
    {

        if (setEmail(input_email))
        {
            // future function to be called, if the email and password is correct
            break;
        }
        else if (!(setEmail(input_email)))
        {
            QMessageBox msgBox;
            msgBox.setText("Re-Enter Email");
            msgBox.exec();

            if (QMessageBox::Ok)
            {
                msgBox.close();
                break;
            }
        }
    }

    password = input_password;
}

bool Login::setEmail(string input_email)
{
    email = input_email;
    if (email_checker(email) == false)
    {
        //cout << "\tEnter your email again";
        return false;
    }
    return true;
}

void Login::setPassword(string input_password)
{
    password = input_password;
}

string Login::getEmail()
{
    return email;
}

string Login::getPassword()
{
    return password;
}
