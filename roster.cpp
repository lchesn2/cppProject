
#include "roster.h"
#include "student.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include "degree.h"
#include<iostream>
#include <cstdlib>
#include<string>
#include<string.h>
//#include <cstring>
using std::cout;
using std::cerr;

Roster::Roster()
{
	this->capacity = 0;
	this->lastIndex= -1;//empty array
	this-> students = nullptr;
}
Roster::Roster(int capacity)
{
	this->capacity = capacity;  //to the capacity coming in
	this->lastIndex = -1;
	this->students = new Student* [capacity]; //pointers to students (five)
}

Student* Roster:: getStudentAt(int index)
{
return students[index];
}


void Roster::parseThenAdd(string row)
{
	if(lastIndex < capacity) {
	lastIndex++;
	DegreeType degreeType;

    //student id 44-60
	int rhs = row.find(",");
	string studentID = row.substr(0, rhs);

	int lhs = rhs + 1;
	rhs = row.find(",", lhs);
	string firstName = row.substr(lhs, rhs - lhs);


	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	string lastName = row.substr(lhs, rhs- lhs);

    //student email
    lhs = rhs + 1;
    rhs = row.find(",", lhs);
    string emailAddress = row.substr(lhs, rhs - lhs);

    //age
	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	//string ageStri = row.substr(lhs, rhs - lhs);
	int age=stoi(row.substr(lhs, rhs - lhs));

	lhs = rhs +1;
	rhs = row.find(",", lhs);
	//string da1Stri = row.substr(lhs, rhs- lhs);// take string and parse to double
	int da1=stoi(row.substr(lhs, rhs- lhs));

	lhs = rhs +1;
	rhs = row.find(",", lhs);
	//string da2Stri = row.substr(lhs, rhs- lhs);
	int da2=stoi(row.substr(lhs, rhs- lhs));

	lhs = rhs +1;
	rhs = row.find(",", lhs);
	//string da3Stri = row.substr(lhs, rhs- lhs);
	int da3=stoi(row.substr(lhs, rhs- lhs));

	char k = 'K';
    char f= 'F';
    char y= 'Y';
	int foundK= row.find(k);
    int foundF=row.find(f);
    int foundY= row.find(y);

    if(foundK != string::npos){
        degreeType = NETWORK;
    }
    else if(foundF != string::npos){
        degreeType = SOFTWARE;
    }
    else if(foundY != string::npos){
        degreeType = SECURITY;
            }
    else{
        cerr<< "Invalid student. \n";
        exit(-1);
    }

	//int da3 = stoi(row.substr(lhs, rhs- lhs));

add(studentID, firstName, lastName, emailAddress, age, da1, da2, da3, degreeType);
}
else
{
cerr << "error! list has exceeded max capacity!\n";
exit(-1);
}
}



void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int da1, int da2, int da3, DegreeType degreeType)
{

	int daysAllotted[Student::dayArraySize];
	daysAllotted[0] = da1;
	daysAllotted[1] = da2;
	daysAllotted[2] = da3;
	if( degreeType == NETWORK) students[lastIndex] = new NetworkStudent(studentID, firstName, lastName, emailAddress, age, daysAllotted, degreeType);
	else if( degreeType == SECURITY) students[lastIndex] = new SecurityStudent(studentID, firstName, lastName, emailAddress, age, daysAllotted, degreeType);
	else if ( degreeType == SOFTWARE) students[lastIndex] = new SoftwareStudent(studentID, firstName, lastName, emailAddress, age, daysAllotted, degreeType); //deg type was conf about bp earlier
}
void Roster::print_All()
{
	for (int i =0; i <= this->lastIndex; i++) (this->students)[i]->print();
}
bool Roster::remove(string ID)
{
	bool found = false;
	for(int i =0; i <= lastIndex; i++)
	{
	    if (this->students[i]->getStudentID() == ID){
		found =true;

		delete this-> students[i];

		this->students[i] = this->students[lastIndex];
		lastIndex--;
	    }
	}

return found;
}


void Roster::printAverageDaysAllotted(string studentID)
{
    bool found = false;
        for(int i = 0; i <= lastIndex; i++)
        {
            if ( this->students[i] ->getStudentID() == studentID)
                {
                 found = true;
                 int* d = students[i] ->getDaysAllotted();
                 cout << "Student " << studentID << " has " << (d[0] + d[1] + d[2])/ 3  << " more days.\n";
            }
        }
if(!found) cout << "Student not found!\n";
}

void Roster::printInvalidEmails()



{	cout << "Displaying invalid email address entries:\n";

	for (int i = 0; i <= 5; i++){
	    bool foundAt = false;
        bool foundDot = false;
        bool foundLightYear = false;
        string email = "";
        email = (this->students[i]->getEmailAddress());
            for(char &p : email) {
                if(p == '@'){
                    foundAt = true;
                }
                if(p == '.'){
                    foundDot = true;
                }
                if(p== ' '){
                    foundLightYear = true;
                }
            }
            if(!foundAt){
                cout<<"Student " << this->students[i]->getStudentID() << " has no @ symbol in their email: " << (this->students[i] ->getEmailAddress()) <<"\n";
                }
            if(!foundDot){
                cout<<"Student " << this->students[i]->getStudentID() << " has no period in their email: " << (this->students[i]->getEmailAddress()) << "\n";
                }
            if(foundLightYear){
                cout<<"Student " << this->students[i]->getStudentID() << " has a space in their email: " << (this->students[i]->getEmailAddress()) << "\n";
            }

}

}

void Roster::printByDegreeType()
{


    	cout <<"Printing all " << degreeTypeStrings[2] << "S: \n";
	for(int i = 0; i <= lastIndex; ++i) {
		if(this->students[i] ->getDegreeType() == 2) this->students[i] ->print();

	}

}

Roster::~Roster()
{
	for (int i = 0; i <= lastIndex; i++)
	{
		delete this->students[i];//deletes each student first
	}
	delete students;//deletes array of pointers to students
}


int main()
{

    int numStudents = 5;

    const string studentData[5] =
    {   "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Larah,Chesnic,lchesn2@wgu.edu,26,19,27,39,SOFTWARE"
    };

    cout << "Scripting and Programming - Applications C867" << "\n";
	cout << "C++ Language" << "\n";
	cout << "Student ID# 001106662" << "\n";
	cout << "Larah Chesnic" << "\n";
	cout << "\n";

    Roster* rep = new Roster(numStudents);
    cout << "Parsing data and adding students: \n\n";
    for(int i =0; i < numStudents; i++)
    {
        rep -> parseThenAdd(studentData[i]);
    }

    cout << "Displaying all students: \n";
    rep-> print_All();
    cout<<"\n";

    cout << "Removing student A3: \n\n";
    if(rep-> remove("A3")) {
	rep->print_All();
	numStudents--;
    }
    else {
    cout<< "Student not found!\n";
    cout << "Removing  student A3: \n\n";}

    if(rep->remove("A3")) {rep->print_All();}
    else {cout << "Student not found! \n\n";
    cout << "Printing average number of days left for all students: \n";}
    for (int i = 0; i < numStudents; ++i)
    {
    rep->printAverageDaysAllotted(rep->getStudentAt(i)->getStudentID());
    }
    cout<< "\n";
    rep->printByDegreeType();
    cout<< "\n";
    rep->printInvalidEmails();


    //rep->printByDegreeType();

    return 0;


}

