#pragma once
#include <string>
#include "degree.h"
#include "student.h"

class SecurityStudent : public Student
{

public:

	SecurityStudent();
	SecurityStudent(
		string studentID,
		string firstName,
		string lastName,
		string emailAddress,
		int age,
		int daysAllotted[],
		DegreeType degreetype
	);

	DegreeType getDegreeType();
	void print();

	~SecurityStudent();
};

