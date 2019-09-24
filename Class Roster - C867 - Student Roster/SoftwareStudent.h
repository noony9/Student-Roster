#pragma once
#include "Student.h"
#include "Degree.h"
#ifndef SOFTWARESTUDENT_H
#define SOFTWARESTUDENT_H
using namespace std;

class SoftwareStudent : public Student {
	public:
		SoftwareStudent();
		SoftwareStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int* numDays, Degree degree);
		~SoftwareStudent();
		Degree getDegree();
		void print();
		Degree degree = SOFTWARE;
};
#endif
