#include <iostream>
#include "securityStudent.h"
#include "degree.h"
#include "student.h"
using std::cout;

SecurityStudent::SecurityStudent():Student()
{

degreetype = SECURITY;
}

SecurityStudent::SecurityStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int daysAllotted[], DegreeType degreetype)
	:Student(studentID, firstName, lastName, emailAddress, age, daysAllotted)
{
	degreetype = SECURITY;
}

DegreeType SecurityStudent::getDegreeType()
{
return SECURITY;
}

void SecurityStudent::print()
{
	this->Student::print();
	cout << "SECURITY STUDENT" << "\n";
}

/*SecurityStudent::~SecurityStudent()
{
	Student::~Student();
}*/
