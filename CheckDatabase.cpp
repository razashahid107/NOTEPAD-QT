#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

bool readRecordFromFile(string input_email, string input_password){
    ifstream file;
    file.open("credentials.csv");

    bool foundRecord = false;
    string email, password;

    while (getline(file,email,',') && !(foundRecord)){
        getline(file, password, ',');
        if ((email == input_email) && (password == input_password)){
            foundRecord = true;
            return true;
        }
        else{
            return false;
        }
    }
}

int main(){
    if (readRecordFromFile("razashaid107@gmail.com", "12345"));
}