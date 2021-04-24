#include <iostream>
#include "softwareStudent.h"
#include "degree.h"
#include "student.h"
using std::cout;

SoftwareStudent::SoftwareStudent():Student()
{

degreetype = SOFTWARE;
}

SoftwareStudent::SoftwareStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int daysAllotted[], DegreeType degreetype)
	:Student(studentID, firstName, lastName, emailAddress, age, daysAllotted)
{
	degreetype = SOFTWARE;
}

DegreeType SoftwareStudent::getDegreeType()
{
return SOFTWARE;
}

void SoftwareStudent::print()
{
	this->Student::print();
	cout << "SOFTWARE STUDENT" << "\n";
}

/*SoftwareStudent::~SoftwareStudent()
{
	Student::~Student();
}*/
