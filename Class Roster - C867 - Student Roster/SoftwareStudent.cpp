#include "SoftwareStudent.h"
#include <iostream>
#include <string>
using namespace std;

SoftwareStudent::SoftwareStudent() :Student() {}
SoftwareStudent::SoftwareStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int* numDays, Degree degree) {
	setStudentID(studentID);
	setFirstName(firstName);
	setLastName(lastName);
	setEmailAddress(emailAddress);
	setAge(age);
	setNumDays(numDays);
}
SoftwareStudent::~SoftwareStudent() {}
Degree SoftwareStudent::getDegree() {
	return SOFTWARE;
}
void SoftwareStudent::print() {
	this->Student::print();
	cout << "SOFTWARE" << endl;
}



