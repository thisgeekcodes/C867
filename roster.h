#pragma once

class Roster {
public:
	//array
	int lIndex = -1;
	const static int studentDataTable = 5;
	student* classRosterArray[studentDataTable];
	//setter functions
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, float daysInCourse1, float daysInCourse2, float daysInCourse3, DegreeProgramEnum degreeprogram);
	void remove(string studentID);

	//print functions
	void printAll() ;
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgramEnum degreeprogram);

	//constructor 
	Roster();

	//destructor 
	~Roster();

	//copy & add contructor
	Roster(const Roster& orig);
};