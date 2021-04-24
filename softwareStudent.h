#pragma once
#include <string>
#include "degree.h"
#include "student.h"

class SoftwareStudent : public Student
{

public:

	SoftwareStudent();
	SoftwareStudent(
		string studentID,
		string firstName,
		string lastName,
		string emailAddress,
		int age,
		int daysAllotted[],
		DegreeType degreetype
	);

	DegreeType getDegreeType();//virtual methods-- no longer abstract
	void print();

	~SoftwareStudent();
};

