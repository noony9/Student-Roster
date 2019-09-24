#pragma once
#include "Student.h"
#include "Degree.h"
#ifndef SECURITYSTUDENT_H
#define SECURITYSTUDENT_H
using namespace std;

class SecurityStudent : public Student {
	public:
		SecurityStudent();
		SecurityStudent(string studentID, string firstName, string lastName, string emailAddress, int age,  int* numDays, Degree degree);
		~SecurityStudent();
		Degree getDegree();
		void print();
		Degree degree = SECURITY;
};
#endif
