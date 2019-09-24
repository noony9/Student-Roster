#include "NetworkStudent.h"
#include <iostream>
#include <string>
using namespace std;

NetworkStudent::NetworkStudent() :Student() {}
NetworkStudent::NetworkStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int* numDays, Degree degree){
	setStudentID(studentID);
	setFirstName(firstName);
	setLastName(lastName);
	setEmailAddress(emailAddress);
	setAge(age);
	setNumDays(numDays);
}
NetworkStudent::~NetworkStudent() {}
Degree NetworkStudent::getDegree() {
	return NETWORK;
}
void NetworkStudent::print()
{
	this->Student::print();
	cout << "NETWORK" << endl;
}
