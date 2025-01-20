#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

#include "degree.h"
#include "student.h"


//contructor 
student::student(string studentID, string firstName, string lastName, string emailAddress, int age, float daysInCourse[], DegreeProgramEnum degreeprogram)
{
	const HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(h, FOREGROUND_GREEN); cout << "//// Student constructor called ////" << endl << endl;
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < daysArray; i++) this->daysInCourse[i] = daysInCourse[i];
	this->degreeprogram = degreeprogram;
}
//destructor 
student::~student() { const HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); SetConsoleTextAttribute(h, FOREGROUND_GREEN); cout << "//// Student deconstructor called ////" << endl << endl; }

//getters
string student::get_studentID() { return studentID;}
string student::get_firstName() { return firstName; }
string student::get_lastName() { return lastName; }
string student::get_emailAddress() { return emailAddress; }
int student::get_age() { return age; }
float* student::get_daysInCourse() { return daysInCourse; }
DegreeProgramEnum student::get_degreeprogram() { return degreeprogram; }

//setters
void student::set_studentID(string studentID) { this->studentID = studentID; }
void student::set_firstName(string firstName) { this->firstName = firstName; }
void student::set_lastName(string lastName) { this->lastName = lastName; }
void student::set_emailAddress(string emailAddress) { this->emailAddress = emailAddress; }
void student::set_age(int age) { this->age = age; }
void student::set_daysInCourse(float daysInCourse[]) { for (int i = 0; i < daysArray; i++) this->daysInCourse[i] = daysInCourse[i]; }
void student::set_degreeprogram(DegreeProgramEnum degreeprogram) { this->degreeprogram = degreeprogram; }


//print
void student::print(printEnum item) const
{
	int getArrayLength = sizeof(daysInCourse) / sizeof(int);
	const HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	switch (item) {
	case printEnum::ALL:
		SetConsoleTextAttribute(h, FOREGROUND_BLUE);cout << "Student ID: "; SetConsoleTextAttribute(h, FOREGROUND_RED);cout << studentID;
		SetConsoleTextAttribute(h, FOREGROUND_BLUE);cout << " First Name: "; SetConsoleTextAttribute(h, FOREGROUND_RED); cout << firstName;
		SetConsoleTextAttribute(h, FOREGROUND_BLUE);cout << " Last Name: "; SetConsoleTextAttribute(h, FOREGROUND_RED); cout << lastName;
		SetConsoleTextAttribute(h, FOREGROUND_BLUE);cout << " Email: "; SetConsoleTextAttribute(h, FOREGROUND_RED); cout << emailAddress;
		SetConsoleTextAttribute(h, FOREGROUND_BLUE);cout << " Age: "; SetConsoleTextAttribute(h, FOREGROUND_RED); cout << age;
		SetConsoleTextAttribute(h, FOREGROUND_BLUE);cout << " Days In Courses: "; SetConsoleTextAttribute(h, FOREGROUND_RED); cout << "{";
		
		for (int i = 0; i < getArrayLength; i++) {
			cout << daysInCourse[i];
			if(i + 1 < getArrayLength) { cout << ","; }
		}
		cout << "}" ;
		SetConsoleTextAttribute(h, FOREGROUND_BLUE); cout << " Program: "; SetConsoleTextAttribute(h, FOREGROUND_RED); cout << degreeProgramEnumToString[(int)degreeprogram];
		break;
	case printEnum::age:
		SetConsoleTextAttribute(h, FOREGROUND_BLUE); cout << " Age: "; SetConsoleTextAttribute(h, FOREGROUND_RED); cout << age;
		break;
	case printEnum::daysInCourse:
		SetConsoleTextAttribute(h, FOREGROUND_BLUE); cout << " Days In Courses: "; SetConsoleTextAttribute(h, FOREGROUND_RED); cout << "{";
		
		for (size_t i = 0; i < getArrayLength; i++)
		{
			cout << daysInCourse[i];
			if (i + 1 < getArrayLength) { cout << ","; }
		}
		cout << "}" << endl;
		break;
	case printEnum::degreeprogram:
		SetConsoleTextAttribute(h, FOREGROUND_BLUE);cout << " Program: "; SetConsoleTextAttribute(h, FOREGROUND_RED); cout << degreeProgramEnumToString[(int)degreeprogram];
		break;
	case printEnum::emailAddress:
		SetConsoleTextAttribute(h, FOREGROUND_BLUE);cout << " Email: "; SetConsoleTextAttribute(h, FOREGROUND_RED); cout << emailAddress;
		break;
	case printEnum::firstName:
		SetConsoleTextAttribute(h, FOREGROUND_BLUE);cout <<  " First Name: "; SetConsoleTextAttribute(h, FOREGROUND_RED); cout << firstName;
		break;
	case printEnum::lastName:
		SetConsoleTextAttribute(h, FOREGROUND_BLUE);cout << " Last Name: "; SetConsoleTextAttribute(h, FOREGROUND_RED); cout << lastName;
		break;
	case printEnum::studentID:
		SetConsoleTextAttribute(h, FOREGROUND_BLUE);cout <<  "Student ID: "; SetConsoleTextAttribute(h, FOREGROUND_RED); cout << studentID;
		break;
	}
	cout << endl << endl;
}
