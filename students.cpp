#define students
#ifdef students
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include "students.h"
using namespace std;
using LIST = vector<string>; //for sorting alphabetically
#endif students
int studentNum;
LIST studList;
void readN() { //reads the names of the students in order
	for (auto e : studList) {
		cout << e << "\n";
	}
}
void sortN() {
	LIST a = studList; //that way studList itself doesn't change (keeping the original list)
	sort(a.begin(), a.end());
	for (auto e : studList) {
		cout << e << "\n";
	}
}
void sortR() {
	LIST a = studList; //that way studList itself doesn't change (keeping the original list)
	sort(a.begin(), a.end());
	for (auto e : studList) {
		cout << e << "\n";
	}
}
void checkStudNum() { //will run at the beginning of the program to check the number of students
	studentNum = 0; //only need number for adding new students
	fstream Students("students .csv");
	string line; //don't need the line in this case, but have it here so the program won't break
	while (std::getline(Students, line)) {
		char c;
		bool isName = false;
		string output = "";
		string nameLen = ""; //for ";Lname;Fname;" to sort the names
		for (int i = 0; i < line.length(); i++) { //trying the create the name to push onto the vector
			c = line[i];
			if (isalpha(c)||c==';') { //if c is a letter
				nameLen.push_back(c); //creating the name
				isName = true; //making sure the name cuts off where it's supposed to
			}
			else if (isName) {
				isName = false;
				break;
			}
		}
		for (int i = 1; i < nameLen.length()-1; i++) { //cutting off the end commas
			if (!(nameLen[i] == ';')) output.push_back(nameLen[i]);
			else output.push_back(' ');
		}
		studList.push_back(output);
		studentNum++; //since every line is a new student
	}
	Students.close();
	//cout << studentNum << "\n"; //for debugging purposes
}