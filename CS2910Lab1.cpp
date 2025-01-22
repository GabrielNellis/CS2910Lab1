#define CS2910Lab1
#ifdef CS2910Lab1
#include <iostream>
#include <fstream>
#include <cstring>
#include "students.h"
using namespace std;
#endif CS2910Lab1
int main()
{
    checkStudNum();
    bool end = false;
    string input = "";
    while (!end) { //making it an endless program until you wish to quit
        cout << "Welcome! Type a command to start or type help to see a list of commands\n";
        cin >> input;
        for (int i = 0; i < input.length(); i++) input[i] = toupper(input[i]); //making the input non case-sensitive
        if (input == "EXIT") end = true; //to leave the program
        if (input == "SLIST") readN(); //brings up a list of all students
        if (input == "ALPHA") sortN(); //brings up a list of all students in alphabetical order
        if (input == "RALPHA") sortR(); //brings up a list of all students in reverse alphabetical order
        if (input == "HELP") cout << "Slist - brings up a list of all students\n" //list of commands for the user to enter
            << "Alpha - brings up a list of all students in alphabetical order\n"
            << "Ralpha - brings up a list of all students in reverse alphabetical order\n"
            << "Exit - exits the program\n";
        else cout << "That is not a proper command. Please type a command or type help to see a list of commands\n";
    }
}
//student format is in the form of student#, l.name, f.name, student #, email
//grades format is in the form of l.name, f.name, grades (based on course#)
//courses format is in the form of courseID, when, course#