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
using STUDENT = pair<string, int>; //name for sorting, ID for searching through the file
using LIST = vector<STUDENT>; //for sorting alphabetically
#endif students
int studentNum;
LIST studList;
bool comp(const STUDENT& a, const STUDENT& b) {
	return a.first < b.first;
}
bool rcomp(const STUDENT& a, const STUDENT &b) { //for sorting in descending order (reverse alphabetical rn)
	return a.first > b.first;
}
void readN() { //reads the names of the students in order
	for (auto e : studList) {
		cout << e.first << "\n";
	}
}
void sortN() {
	LIST a = studList; //that way studList itself doesn't change (keeping the original list)
	sort(a.begin(), a.end(), comp);
	for (auto e : a) {
		cout << e.first << "\n";
	}
}
void sortR() {
	LIST a = studList; //that way studList itself doesn't change (keeping the original list)
	sort(a.begin(), a.end(), rcomp);
	for (auto e : a) {
		cout << e.first << "\n";
	}
}
void checkStudNum() { //will run at the beginning of the program to check the number of students
	studentNum = 1; //only need number for adding new students
	fstream Students("students .csv");
	string line; //to store the line obtained from the program
	while (getline(Students, line)) {
		char c;
		bool isName = false;
		string output = "";
		string nameLen = ""; //for ";Lname;Fname;" to sort the names
		for (int i = 0; i < line.length(); i++) { //trying the create the name to push onto the vector
			c = line[i];
			if (isalpha(c) || c == ';') { //if c is a letter
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
			else {
				output.push_back(',');
				output.push_back(' ');
			}
		}
		STUDENT p;
		p.first = output;
		p.second = studentNum;
		studList.push_back(p);
		studentNum++; //since every line is a new student
	}
	Students.close();
	//cout << studentNum << "\n"; //for debugging purposes
}
void updateSID(int& a) {

}
void sNumSearch(string& s) { //does not work (can't locate the student no matter what)
	bool found = false;
	fstream Students("students .csv");
	string line, num = "";
	int semis = 0;
	while (!Students.eof()) {
		getline(Students, line);
		for (int i = 0; i < line.length(); i++) {
			char c = line[i];
			if (c == ';') semis++;
			else if (semis == 3) num.push_back(c);
			if (semis == 4) break;
		}
		semis = 0;
		if (s == num) {
			found = true;
			break;
		}
	}
	if (!found) cout << "Could not locate the specified student\n";
	else {
		//cout << "Student Name: ";
		cout << "\nStudent Number: ";
		semis = 0;
		for (int i = 0; i < line.length(); i++) {
			char c = line[i];
			if (c == ';') semis++;
			else if (semis == 3) cout << c;
			else if (semis == 4) { //this being the last part with the email
				semis++;
				cout << "\nStudent Email: ";
			}
			if (semis >= 5) cout << c; //this should only happen during the part where it writes the email
		}
		cout << "\n";
	}
	Students.close();
	return;
}
void sNSearch(string &s) {
	bool found = false;
	int studID;
	if (isalpha(s[0])) { //is the student's last name
		for (int i = 0; i < s.length(); i++) s[i] = tolower(s[i]); //making the rest of the name lowercase to not mess with the search
		s[0] = toupper(s[0]); //making the first letter uppercase to not mess with the search
		for (auto e : studList) {
			if (s == e.first.substr(0, s.length())) {
				studID = e.second;
				found = true;
				cout << "Student Name: " << e.first;
				break;
			}
		}
	}
	else { //is the student's phone number
		sNumSearch(s);
	}
	if (!found) cout << "Could not locate the specified student\n";
	else {
		string item = to_string(studID);
		string line;
		string output = "";
		int semis = 0; //for number of semicolons to determine what to print
		fstream Students("students .csv");
		while (!Students.eof()) {
			getline(Students, line);
			string num = "";
			for (int i = 0; i < line.length(); i++) { //checking the student ID
				if (line[i] == ';') break;
				else num.push_back(line[i]);
			}
			if (num == item) { //this being the student you're looking for
				cout << "\nStudent Number: ";
				semis = 0;
				for (int i = 0; i < line.length(); i++) {
					char c = line[i];
					if (c == ';') semis++;
					else if (semis == 3) cout << c;
					else if (semis == 4) { //this being the last part with the email
						semis++;
						cout << "\nStudent Email: ";
					}
					if (semis>=5) cout << c; //this should only happen during the part where it writes the email
				}
				cout << "\n";
				break;
			}
		}
		Students.close();
	}
}