#pragma once
#include "Student.h"
#include "Degree.h"
#ifndef NETWORKSTUDENT_H
#define NETWORKSTUDENT_H
using namespace std;

class NetworkStudent : public Student {
	public:
		NetworkStudent();
		NetworkStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int* numDays, Degree degree);
		~NetworkStudent();
		Degree getDegree();
		void print();
		Degree degree = NETWORK;
};
#endif

