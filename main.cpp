#define CS2910Lab1
#ifdef CS2910Lab1
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cctype>
#include "students.cpp"
using namespace std;
#endif CS2910Lab1
int main()
{
    string input = "";
    bool end = false;
    while (!end) {
        cout << "Welcome! Type help for assistance and type exit to exit the program.\n";
        cin >> input;
        for (int i = 0; i < input.length(); i++) { //this is to turn the string to uppercase, making the program non case-sensitive
            input[i] = toupper(input[i]);
        }
        if (input == "EXIT") end = true;
        if (input == "HELP") { //to showcase all of the different features
            
        }
    }
}
//student format is in the form of student#, l.name, f.name, student #, email
//grades format is in the form of l.name, f.name, grades (based on course#)
//courses format is in the form of courseID, when, course#