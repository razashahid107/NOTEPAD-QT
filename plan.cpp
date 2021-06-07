#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <iomanip>
#include <stdlib.h>
#include <conio.h>
#include <fstream>

using namespace std;

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

// string decrypt(string str)
// {
//     vector<char> default_char{};
//     vector<char> decrypt_str{};
//     int temp_int;
    
//     char temp_char;
//     int length = str.length();

//     char ch[length + 1];
//     strcpy(ch, str.c_str());

//     for (int i = 0; i < length; i++) {
//         default_char.push_back(ch[i]);
//     }
    


//     for (int j = 0; j < length; j++){
//         if ((default_char[j] == 'f') && (default_char[j+1] == '#') && (default_char[j+2] == 'f') ) {
            
//             temp_int = ((int)default_char[j+3]);
//             temp_char = (char)temp_int;
//             decrypt_str.push_back(temp_char);
//             j =+ 3;
//         }
//         else {
//             temp_int = (int)default_char[j] + 5;
//             temp_char = (char)temp_int;
//             decrypt_str.push_back(temp_char);
//         }
//     }
//     for (int i = 0; i < decrypt_str.size(); i++){
//         cout << decrypt_str[i];
//     }
//     string str(decrypt_str.begin(), decrypt_str.end());
//     return str;
// }


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

bool readRecordFromFile(string input_email, string input_password){
    ifstream file;
    file.open("C:/Users/Anonymous/Downloads/build-NOTEPAD-Desktop_Qt_6_1_0_MinGW_64_bit-Debug/login.csv");

    bool foundRecord = false;
    string email, password;
    char del = ',';

    while (getline(file,email,del) && !(foundRecord)){
        getline(file, password, ',');
        if ((email == input_email)){
            cout << email;
            cout << password;
            foundRecord = true;
            return true;
        }
        else return false;
    }

}

int main(){
    if (readRecordFromFile("Password", "123456") != true){
        cout << "true";
    }
     
}

// int main(){
//     string str = encr("azeem!");
//     cout << str << endl << endl;
    
//     cout << decrypt(str);
// }