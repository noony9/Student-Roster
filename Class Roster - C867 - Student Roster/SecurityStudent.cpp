#include "SecurityStudent.h"
#include <iostream>
#include <string>
using namespace std;

SecurityStudent::SecurityStudent() :Student() {}
SecurityStudent::SecurityStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int* numDays, Degree degree) {
	setStudentID(studentID);
	setFirstName(firstName);
	setLastName(lastName);
	setEmailAddress(emailAddress);
	setAge(age);
	setNumDays(numDays);
}
SecurityStudent::~SecurityStudent() {}
Degree SecurityStudent::getDegree() {
	return SECURITY;
}
void SecurityStudent::print() {
	this->Student::print();
	cout << "SECURITY" << endl;
}