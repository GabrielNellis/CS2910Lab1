#define students
#ifdef students
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
#endif students
using LIST = vector<string>;
LIST students;
void searchSID() {

}
void searchName(){

}
void sortName() { //prints the list of students in alphabetical order

}
void sortRname(LIST &v) { //prints the list of students in reverse alphabetical order
std::fstream Students("students .csv");
//std::fstream Grades("grades.csv");
	vector<string> a = v;
	a.push_back("name");
	for (auto e : a) {
		cout << e;
	}
	Students.close();
//	Grades.close();
}