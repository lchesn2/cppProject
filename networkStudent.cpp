#include <iostream>
#include "networkStudent.h"
#include "degree.h"
#include "student.h"
using std::cout;

NetworkStudent::NetworkStudent():Student()//calls empty constructor from student

{
degreetype = NETWORK;//student class does rest
}

NetworkStudent::NetworkStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int daysAllotted[], DegreeType degreetype)
	:Student(studentID, firstName, lastName, emailAddress, age, daysAllotted)//calls full constructor from student class
	//passing in all this information, initializing values
{
	degreetype = NETWORK;
}

DegreeType NetworkStudent::getDegreeType()
{
return NETWORK;
}

void NetworkStudent::print()
{
	this->Student::print();//print from student
	cout << "NETWORK STUDENT" << "\n";
}

/*NetworkStudent::~NetworkStudent()
{
	Student::~Student();
}
*/
