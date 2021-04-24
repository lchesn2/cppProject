#include <iostream>
#include<iomanip>
#include "student.h"
using std::cout;
using std::left;
using std::setw;

Student::Student()
{
    this->studentID  = "";
	this->firstName  = "";
	this->lastName  = "";
	this->emailAddress  = ""; //fields pointing at strings
	this->age  = 0;
	for(int i = 0; i<dayArraySize; ++i) this->daysAllotted[i] = 0;
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysAllotted[]) // full constructor
{//full constructor
	this->studentID  = studentID;
	this->firstName  = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;//not creating object, giving instructions for their behavior
	this->age = age;
	for(int i =0; i < dayArraySize; ++i) this-> daysAllotted[i] = daysAllotted[i];
}

string Student::getStudentID()
{
return studentID;
}

string Student::getFirstName()
{
return firstName;
}

string Student::getLastName()
{
return lastName;
}

string Student::getEmailAddress()//passing parameter ID
{;
return emailAddress;
}

int Student::getAge()
{
return age;
}

int * Student::getDaysAllotted()
{
return daysAllotted;
}


void Student::setStudentID(string studentID)
{studentID = studentID;}

void Student::setLastName(string lastName)
{
    this ->lastName = lastName;
}

void Student::setFirstName(string firstName)
{
    this->firstName = firstName;
}

void Student::setEmailAddress(string emailAddress)
{
    this->emailAddress = emailAddress;

}

void Student::setAge(int age)//this -> when referring to something inside object
{
    this->age = age;//without this-> it is only parameter "playing with itself"
}

void Student::setDaysAllotted(int daysAllotted[])
{
    for(int i = 0; i <dayArraySize; i++)
	this-> daysAllotted[i] = daysAllotted[i];
}

void Student::print()//virtual in this class
{
cout << left << setw(5) << studentID;
cout << left << setw(20) << firstName;
cout << left << setw(20) << lastName;
cout << left << setw(45) << emailAddress;
cout << left << setw(9) << age;
cout << left << setw(9) << daysAllotted[0];
cout << left << setw(9) << daysAllotted[1];
cout << left << setw(9) << daysAllotted[2];
}
Student::~Student()//only if you created anything new, with keyword new
{

}

