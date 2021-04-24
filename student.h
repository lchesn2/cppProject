#pragma once
#include <string>
#include "degree.h"
using std::string;


class Student
{
public:
	const static int dayArraySize = 3;

protected:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysAllotted[dayArraySize];
	DegreeType degreetype;//name of field

public:
	Student();
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysAllotted[]); //full constructor doesn't include deg type, subclasses will do it

    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmailAddress();//ADDED POINTER SO I CAN RETURN THE POINTER TO THE NEW OBJECT
    int getAge();
    int* getDaysAllotted();
    virtual DegreeType getDegreeType() = 0;

    void setStudentID(string ID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmailAddress(string emailAddress);
    void setAge(int age);
    void setDaysAllotted(int daysAlotted[]);

    virtual void print() = 0;

~Student();
};









