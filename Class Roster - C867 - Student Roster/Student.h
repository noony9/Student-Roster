#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include "Degree.h"
#include <string>
using namespace std;

class Student {

public:	
	Student();
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int numDays[]);
	~Student();
	const static int cDays = 3;
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getNumDays();
	virtual Degree getDegree() = 0;
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setNumDays(int numDays[]);
	virtual void print() = 0;

private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int* numDays;
	Degree degree;
};
#endif	

