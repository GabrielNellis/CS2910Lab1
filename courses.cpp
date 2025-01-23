#define courses
#ifdef courses
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include "courses.h"
using namespace std;
using COURSE = tuple<string, bool, int>; //string for the course name, bool for if it's fall or winter (denoted by isWinter)
#endif courses
vector<COURSE> courseList;
bool isWinter;
int courseNum;
void readC() {
	for (auto e : courseList) {
		cout << get<0>(e) << " ";
		if (get<1>(e)) cout << "winter\n"; //prints out the course name and semester for all courses
		else cout << "fall\n";
	}
}
void sortS(bool b) {
	for (auto e : courseList) {
		if (get<1>(e) == b) {
			cout << get<0>(e) << " ";
			if (get<1>(e)) cout << "winter\n"; //prints out the course name and semester for specified courses
			else cout << "fall\n";
		}
	}
}
void checkCourses() {
	fstream course("courses.csv");
	courseNum = 0; //only need it for adding new courses
	string line;
	while (!course.eof()) {
		getline(course, line);
		courseNum++;
		char c; //stores the value of each character
		string semest = ""; //for storing the semester, otherwise used as the course
		for (int i = 7; i < line.length(); i++) { //starting after the semicolon for which course it is
			c = line[i];
			if (c == ';') break;
			else semest.push_back(c);
		}
		isWinter = (semest == "winter"); //isWinter is true if it's the winter semester and false otherwise
		semest = line.substr(0, 6); //since the first 6 letters/numbers is the course code
		COURSE p; //either I was doing something wrong or I can't declare and define COURSE p in a single line
		get<0>(p) = semest;
		get<1>(p) = isWinter;
		get<2>(p) = courseNum;
		courseList.push_back(p);
	}
	courseList.pop_back(); //since there's a bug involving one extra course appearing (no course code), so this *should* fix it
	course.close();
}
void cSearch(string& s) {
	bool found = false;
	if (isalpha(s[0])) { //if the first character is a letter
		s[0]=toupper(s[0]); //making sure the first 2 characters are uppercase
		s[1]=toupper(s[1]);
		for (auto e : courseList) {
			if (get<0>(e) == s) {
				cout << "Course name: " << get<0>(e);
				cout << "\nSemester offered: ";
				if (get<1>(e)) cout << "winter "; //prints out the course name and semester for specified courses
				else cout << "fall ";
				cout << "\nCourse code: " << get<2>(e) << "\n";
				found = true;
				break;
			}
		}
	}
	else { //looking for a course code instead of a name
		for (auto e : courseList) {
			string a = to_string(get<2>(e)); //this converts the int from the third variable of e into a string to be compared with the input
			if (a == s) {
				cout << "Course name: " << get<0>(e);
				cout << " Semester offered: ";
				if (get<1>(e)) cout << "winter "; //prints out the course name and semester for specified courses
				else cout << "fall ";
				cout << "Course code: " << get<2>(e) << "\n";
				found = true;
				break;
			}
		}
	}
	if (!found) cout << "Could not locate the specified course\n";
}