#pragma once
#ifndef ROSTER_H
#define ROSTER_H
#include "Student.h"
#include <iostream>
#include <string>
using namespace std;

class Roster {
public:
	Roster();
	Roster(int limit);
	~Roster();
	void parseThenAdd(string studRow);
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int days1, int days2, int days3, Degree degree);
	void remove(string studentID);
	void printAll();
	void printDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(Degree degree);
private:
	int lastIndex;
	int limit;
	Student** classRosterArray;
};
#endif
