#pragma once
#include <string>

void readN(); //reads the names of the students in order

void sortN(); //sorts and prints the names of the students in alphabetical order

void sortR(); //sorts and prints the names of the students in reverse alphabetical order

void checkStudNum(); //checks the number of students (since the program will also allow the user to add new students)

//void writeS(); //makes a new student in the database

void updateSID(int &); //updates student information by looking up their id

void sNSearch(std::string &);