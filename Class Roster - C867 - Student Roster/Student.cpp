#include "Student.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

	Student::Student() {
		this->studentID = "";
		this->firstName = "";
		this->lastName = "";
		this->emailAddress = "";
		this->age = 0;
		this->numDays = new int[cDays];
		for (int i = 0; i < cDays; ++i) this->numDays[i] = 0;
	}
	Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int numDays[]) {
		this->studentID = studentID;
		this->firstName = firstName;
		this->lastName = lastName;
		this->emailAddress = emailAddress;
		this->age = age;
		this->numDays = new int[cDays];
		for (int i = 0; i < 3; ++i) this->numDays[i] = numDays[i];
	}
	string Student::getStudentID() {
		return studentID;
	}
	string Student::getFirstName() {
		return firstName;
	}
	string Student::getLastName() {
	return lastName;
	}
	string Student::getEmailAddress() {
		return emailAddress;
	}
	int Student::getAge() {
		return age;
	}
	int* Student::getNumDays() {
		return numDays;
	}
	void Student::setStudentID(string studentID) {
		this->studentID = studentID;
	}
	void Student::setFirstName(string firstName) {
		this->firstName = firstName;
	}
	void Student::setLastName(string lastName)	{
		this->lastName = lastName;
	}
	void Student::setEmailAddress(string emailAddress) {
		this->emailAddress = emailAddress;
	}
	void Student::setAge(int age) {
		this->age = age;
	}
	void Student::setNumDays(int numDays[])	{
		if (this->numDays != nullptr) {
			delete[] this->numDays;
			this->numDays = nullptr;
		}
		this->numDays = new int[cDays];
		for (int i = 0; i < 3; ++i)
			this->numDays[i] = numDays[i];
	}
	void Student::print() {
		cout << "Student ID: " << studentID << "\t" << "First Name: " << firstName << "\t" << "Last Name: " << lastName << "\t" << "Age: " << age
			<< "\t" << "Email: " << emailAddress << "\t" << "\t" << " " << "Days in course: (" << numDays[0] << ", " << numDays[1] << ", " << numDays[2] << ")" << "\t" << "Degree: ";
	}
	Student::~Student() {}
	