#pragma once
#include <string>
#include "degree.h"
#include "student.h"

class NetworkStudent : public Student
{

public:

	NetworkStudent();
	NetworkStudent(
		string studentID,
		string firstName,
		string lastName,
		string emailAddress,
		int age,
		int daysAllotted[],
		DegreeType degreetype
	);

	DegreeType getDegreeType();//virtual from student NOT VIRTUAL HERE
	void print();//virtual from student need to know what degree type is before can print

	~NetworkStudent();
};
