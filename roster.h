#pragma once
#include <string>
#include<iostream>
#include "student.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include "degree.h"

class Roster{
private:
	int lastIndex;// increment inside the object, sets pointer to object at right position
	int capacity;//small or large as want.. only an array of pointers, later will create objects
	Student** students;//pointer to pointer to student. arrays are addresses//changed to pointer to array
    //addresses stored in roster array, students. have to create dynamically bc don't know student degree type
public:
	Roster();
	Roster(int capacity);

	Student* getStudentAt(int index);//group of methods
	void parseThenAdd(string row);
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int da1, int da2, int da3, DegreeType dt);
	void print_All();
	bool remove(string studentID);
	void printAverageDaysAllotted(string studentID);
	void printInvalidEmails();//changed to add string email so that i can return something
	void printByDegreeType();

	~Roster();
};

