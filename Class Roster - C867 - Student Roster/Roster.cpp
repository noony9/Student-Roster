#include "Degree.h"
#include "Student.h"
#include "Roster.h"
#include "NetworkStudent.h"
#include "SecurityStudent.h"
#include "SoftwareStudent.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

Roster::Roster() {
	this->limit = 0;
	this->lastIndex = -1;
	this->classRosterArray = nullptr;
}
Roster::Roster(int limit) {
	this->limit = limit;
	this->lastIndex = -1;
	this->classRosterArray = new Student * [limit];
}
Roster::~Roster() {}

void Roster::parseThenAdd(string studRow) {
	if (lastIndex < limit) {
		lastIndex++;
		Degree degree;
		if (studRow[1] == '1') degree = SECURITY;
		else if (studRow[1] == '2') degree = NETWORK;
		else if (studRow[1] == '3') degree = SOFTWARE;
		else if (studRow[1] == '4') degree = SECURITY;
		else if (studRow[1] == '5') degree = SOFTWARE;
		else {
			cout << "INVALID TYPE!" << endl;
			exit(-1);
		}
		int rhs = studRow.find(",");
		string sID = studRow.substr(0, rhs);

		int lhs = rhs + 1;
		rhs = studRow.find(",", lhs);
		string sFirstName = studRow.substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = studRow.find(",", lhs);
		string sLastName = studRow.substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = studRow.find(",", lhs);
		string sEmailAddress = studRow.substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = studRow.find(",", lhs);
		int sAge = stoi(studRow.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studRow.find(",", lhs);
		int sCourseDays1 = stoi(studRow.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studRow.find(",", lhs);
		int sCourseDays2 = stoi(studRow.substr(lhs, rhs - lhs));
		
		lhs = rhs + 1;
		rhs = studRow.find(",", lhs);
		int sCourseDays3 = stoi(studRow.substr(lhs, rhs - lhs));
		add(sID, sFirstName, sLastName, sEmailAddress, sAge, sCourseDays1, sCourseDays2, sCourseDays3, degree);
	}
	else {
		cout << "Exceeded Capacity, exiting now." << endl;
		exit(-1);
	}
}
void Roster::add(string sID, string sFirstName, string sLastName, string sEmailAddress, int sAge, int sCourseDays1, int sCourseDays2, int sCourseDays3, Degree degree) {
	int courseDays[Student::cDays];
	courseDays[0] = sCourseDays1;
	courseDays[1] = sCourseDays2;
	courseDays[2] = sCourseDays3;
	if (degree == NETWORK) classRosterArray[lastIndex] = new NetworkStudent(sID, sFirstName, sLastName, sEmailAddress, sAge, courseDays, degree);
	else if (degree == SECURITY) classRosterArray[lastIndex] = new SecurityStudent(sID, sFirstName, sLastName, sEmailAddress, sAge, courseDays, degree);
	else classRosterArray[lastIndex] = new SoftwareStudent(sID, sFirstName, sLastName, sEmailAddress, sAge, courseDays, degree);
}
void Roster::remove(string sID) { 
	bool found = false;
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != NULL) {
			if (sID == classRosterArray[i]->getStudentID()) {
				classRosterArray[i] = nullptr;
				found = true;
			}
		}
	}
	if (!found) {
		cout << "Error, student not found..." << endl;
	}
}
void Roster::printAll(){ 
	for (int i = 0; i <= this->lastIndex; i++) (this->classRosterArray)[i]->print(); 
}
void Roster::printDaysInCourse(string studentID){										
	bool found = false;
	for (int i = 0; i <= lastIndex; i++) {
		if (this->classRosterArray[i]->getStudentID() == studentID) {
			found = true;
			int* d = this->classRosterArray[i]->getNumDays();
			cout << "Average number of days in three courses for student " << studentID << " is " << (d[0] + d[1] + d[2]) / 3 << endl;
		}
	}
}
void Roster::printInvalidEmails() {
	for (int i = 0; i < 5; i++) {
			string badEmail = classRosterArray[i]->getEmailAddress();
			if ((badEmail.find("@") == -1) || (badEmail.find(".") == -1) || !(badEmail.find(" ") == -1)) {
				cout << badEmail << endl;
			}
	}
}
void Roster::printByDegreeProgram(Degree degreeProgram){ 										     
	Degree tempDegree = degreeProgram;
	for (int i = 0; i < 5; i++) {
		if (tempDegree == classRosterArray[i]->getDegree()) {
			this->classRosterArray[i]->print();
		}
	}
}

int main() {
	const int numStudents = 5;
	const string studentData[] = { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
								  "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
								  "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
								  "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
								  "A5,Daniel,Jacobs,djaco39@wgu.edu,37,10,20,30,SOFTWARE" };
	
	cout << "Course: C867 - Scripting and Programming Applications" << endl;
	cout << "Written in C++ in Visual Studio" << endl;
	cout << "Student ID: 000803586" << endl;
	cout << "Name: Daniel Jacobs" << endl;

	Roster* classRoster = new Roster(numStudents);

	cout << "Adding each student to the classRoster... " << endl << endl;
	for (int i = 0; i < numStudents; i++) {
		classRoster->parseThenAdd(studentData[i]); 
	}
	cout << endl;
	cout << "Displaying all Students... " << endl << endl;
	classRoster->printAll();
	cout << endl;
	cout << "Displaying all Invalid Emails... " << endl << endl;
	classRoster->printInvalidEmails();
	cout << endl;
	cout << "Printing student's average days in course... " << endl << endl;
	classRoster->printDaysInCourse("A5");
	cout << endl;
	cout << "Printing student information for the degree program... " << endl << endl;
	classRoster->printByDegreeProgram(SOFTWARE);
	cout << endl;
	cout << "Removing selected Student \"A3\"..." << endl << endl;
	classRoster->remove("A3");
	cout << "Attempting to remove the same Student..." << endl << endl;
	classRoster->remove("A3");		
	classRoster->Roster::~Roster();

	system("pause");
	return 0;
}