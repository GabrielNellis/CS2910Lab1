#define CS2910Lab1
#ifdef CS2910Lab1
#include <iostream>
#include <fstream>
#include <cstring>
#include "students.h"
#include "courses.h"
using namespace std;
#endif CS2910Lab1
int main() { //all this does is call functions in other files and print some tips
    checkStudNum(); //calls the function in students.cpp for the student list
    checkCourses(); //calls the function in courses.cpp for the course list
    bool end = false;
    string input = "";
    while (!end) { //making it an endless program until you wish to quit
        cout << "Welcome! Type a command to start or type help to see a list of commands\n";
        cin >> input;
        for (int i = 0; i < input.length(); i++) input[i] = toupper(input[i]); //making the input non case-sensitive
        if (input == "EXIT") end = true; //to leave the program
        else if (input == "SLIST") readN(); //brings up a list of all students
        else if (input == "ALPHA") sortN(); //brings up a list of all students in alphabetical order
        else if (input == "RALPHA") sortR(); //brings up a list of all students in reverse alphabetical order
        else if (input == "CLIST") readC(); //brings up a list of all courses
        else if (input == "CSLIST") { //bring up a list of all courses for the specified semester
            bool validIn = false;
            while (!validIn) {
                cout << "Which semester were you looking for? Fall or Winter (or go back)?\n";
                cin >> input;
                for (int i = 0; i < input.length(); i++) input[i] = toupper(input[i]); //making the input non case-sensitive
                if (input == "WINTER") {
                    validIn = true; //to get out of the while loop
                    sortS(true);
                }
                else if (input == "FALL") {
                    validIn = true; //to get out of the while loop
                    sortS(false);
                }
                else if (input == "BACK") break; //if they wanted to go back to the main menu
                else cout << "This input is invalid, please try again\n"; //for if the input is invalid
            }
        }
        else if (input == "SEARCH") { //for searching for information from the files
            bool validIn = false;
            while (!validIn) {
                cout << "Are you looking for a student or course (or go back)?\n";
                cin >> input;
                for (int i = 0; i < input.length(); i++) input[i] = toupper(input[i]); //making the input non case-sensitive
                if (input == "STUDENT") { //warning, does not work properly (won't crash, just always fails)
                    validIn = true;
                    cout << "Please enter the student's last name or last 4 digits of their phone number\n";
                    cin >> input;
                    sNSearch(input);
                    break;
                }
                else if (input == "COURSE") {
                    validIn = true;
                    cout << "Please enter the name or code of the course\n";
                    cin >> input;
                    cSearch(input);
                    break;
                }
                else if (input == "BACK") break; //to go back to the main menu
                else cout << "This input is invalid, please try again\n";
            }
        }
        /*
        else if (input == "CALCGRADE") { //does not work
            bool validIn = false;
            while (!validIn) {
                cout << "Which course would you like to calculate the grade for?\n"
                    << "Feel free to go back for the list of courses\n";
                cin >> input;
                for (int i = 0; i < input.length(); i++) input[i] = toupper(input[i]); //making the input non case-sensitive
                if (input == "BACK") break;
                //else cCalculate(input);
            }
        }
        */
        else if (input == "HELP") cout << "Slist - brings up a list of all students\n" //list of commands for the user to enter
            << "Alpha - brings up a list of all students in alphabetical order\n"
            << "Ralpha - brings up a list of all students in reverse alphabetical order\n"
            << "Clist - brings up a list of all courses\n"
            << "Cslist - brings up a list of all courses for the specified semester\n"
            << "Search - searches to find the specified student or course\n"
            //<< "CalcGrade - calculates the average grade for the specified course\n"
            << "Exit - exits the program\n";
        else cout << "That is not a proper command. Please type a command or type help to see a list of commands\n";
    }
}
//student format is in the form of studentID, l.name, f.name, student #, email
//grades format is in the form of l.name, f.name, grades (based on course#)
//courses format is in the form of courseID, when, course#