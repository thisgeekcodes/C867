#include <iostream>
#include <string>
#include <vector>
#include<regex>
#include <windows.h>
using namespace std;

#include "degree.h"
#include "student.h"
#include "roster.h"

//setters
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, float daysInCourse1, float daysInCourse2, float daysInCourse3, DegreeProgramEnum degreeprogram)
{
	float tmpArray[3] = {daysInCourse1, daysInCourse2,  daysInCourse3};

	student* addStudent = new student(studentID, firstName, lastName, emailAddress, age, tmpArray, degreeprogram);
	classRosterArray[++lIndex] = new student(studentID, firstName, lastName, emailAddress, age, tmpArray, degreeprogram);
}
void Roster::remove(string studentID)
{
	const HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	bool findStudent = false;
	bool success = false; 
	for (int i = 0; i <= Roster::lIndex; i++)
		//use lastIndex since index may change
	{
		if (classRosterArray[i]->get_studentID() == studentID)
		{

			success = true; //found student
			if (i < studentDataTable)
			{
				student* tmpTBL = classRosterArray[i]; // place current student in temp table
				classRosterArray[i] = classRosterArray[i + 1]; //moves table to left
				//classRosterArray[studentDataTable + 1] = tmpTBL; // 
			}
			Roster::lIndex--;//last student is hidden but not destroyed
		} else if (success) { classRosterArray[i] = classRosterArray[i + 1]; }
	}
	if (success)
	{
		SetConsoleTextAttribute(h, FOREGROUND_GREEN);cout << "//// Deleting student ID: ";SetConsoleTextAttribute(h, FOREGROUND_RED); cout << studentID;  SetConsoleTextAttribute(h, FOREGROUND_GREEN); cout << " from the table ////" << endl;
		cout << endl << endl;
	}
}

//print
void Roster::printAll()  {
	const HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, FOREGROUND_GREEN);cout <<  "//// PRINTING STUDENT LIST ////" << endl << endl;
	
	for (int i = 0; i <= Roster::lIndex; i++)
	{
		classRosterArray[i]->print(printEnum::ALL);
	}
	cout << endl << endl;
}

void Roster::printInvalidEmails() {
	const HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	bool email_check = false;
	SetConsoleTextAttribute(h, FOREGROUND_GREEN); cout << "//// PRINTING INVALID EMAILS ////" << endl << endl;
	
	for (int i = 0; i <= Roster::lIndex; i++) {
		const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
			if (!regex_match(classRosterArray[i]->get_emailAddress(), pattern)) {
				SetConsoleTextAttribute(h, FOREGROUND_BLUE); cout << "Student ID: ";SetConsoleTextAttribute(h, FOREGROUND_RED); cout << classRosterArray[i]->get_studentID(); SetConsoleTextAttribute(h, FOREGROUND_BLUE); cout << " Email: "; SetConsoleTextAttribute(h, FOREGROUND_RED); cout << classRosterArray[i]->get_emailAddress(); SetConsoleTextAttribute(h, FOREGROUND_GREEN); cout << " <-- Invalid email" << endl;
				email_check = true;
			}
		
			if (!email_check) { SetConsoleTextAttribute(h, FOREGROUND_GREEN); cout << "//// No bad emails found ////" << endl << endl; }
			
	}
	cout << endl;
}
void Roster::printAverageDaysInCourse(string studentID)
{
	const HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	for (int i = 0; i <= Roster::lIndex; i++)
	{
		if (classRosterArray[i]->get_studentID() == studentID)
		{
			float avgResult = (classRosterArray[i]->get_daysInCourse()[0] +
				classRosterArray[i]->get_daysInCourse()[1] +
				classRosterArray[i]->get_daysInCourse()[2]) / 3;
			SetConsoleTextAttribute(h, FOREGROUND_BLUE); cout << "Student ID: ";SetConsoleTextAttribute(h, FOREGROUND_RED); cout << classRosterArray[i]->get_studentID(); SetConsoleTextAttribute(h, FOREGROUND_BLUE); cout << " Avg Days: "; SetConsoleTextAttribute(h, FOREGROUND_RED); cout << avgResult << endl;

		}
	}

	cout << endl;
}
void Roster::printByDegreeProgram(DegreeProgramEnum degreeprogram)
{
	const HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, FOREGROUND_GREEN); cout  << "//// Printing all students in " <<  degreeProgramEnumToString[(int)degreeprogram] << "////" << endl << endl;
	bool findStudents = false;
	for (size_t i = 0; i <= Roster::lIndex; i++) {
		if (degreeprogram == classRosterArray[i]->get_degreeprogram())
		{
			classRosterArray[i]->print(printEnum::ALL);
			findStudents = true;
		}

	}
	if (!findStudents) { SetConsoleTextAttribute(h, FOREGROUND_GREEN); cout <<  "//// No students found in " << degreeProgramEnumToString[(int)degreeprogram] << " program ////" << endl << endl; }
	cout << endl;
}

//contructor 
Roster::Roster() {

	return;
}

//add contructor function
Roster::Roster(const Roster& orig) {
	const HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, FOREGROUND_GREEN); cout << "//// Roster constructor called ////" << endl << endl;
	for (int i = 0; i < orig.studentDataTable; i++) {
		classRosterArray[++lIndex] = new student(*orig.classRosterArray[i]);

	}
	return;
}
//destructor 
Roster::~Roster() {
	const HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, FOREGROUND_GREEN); cout << "//// Roster deconstructor called ////" << endl << endl;
	for (int i = 0; i <= Roster::lIndex; i++)
		//size of numBooks stays the same unlike lastIndex
	{
		delete classRosterArray[i];
		
	}
}
