#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <windows.h>
using namespace std;
#include "degree.h"
#include "student.h"
#include "roster.h"



// Declaration - Take data from StudentData and inputs it into the Roster class
Roster inputData(const string studentData[], int numOfStudents);


int main() {
    const HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    //Input studentData Table
    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Michael,Bachman,mbach12@wgu.edu,36,3,7,10,SOFTWARE"
    };
    const int numOfStudents = sizeof(studentData) / sizeof(studentData[0]);
    //Create roster from table
    Roster classRoster = inputData(studentData, numOfStudents);
    cout << endl;

    // Student Info
    SetConsoleTextAttribute(h, FOREGROUND_BLUE); cout << "Scripting and Programming - Applications - C867" << endl;
    SetConsoleTextAttribute(h, FOREGROUND_BLUE); cout << "Language:"; SetConsoleTextAttribute(h, FOREGROUND_RED); cout << " C++" << endl;
    SetConsoleTextAttribute(h, FOREGROUND_BLUE); cout << "Student ID:"; SetConsoleTextAttribute(h, FOREGROUND_RED); cout << " 010130966" << endl;
    SetConsoleTextAttribute(h, FOREGROUND_BLUE); cout << "Name:"; SetConsoleTextAttribute(h, FOREGROUND_RED); cout << " Michael Bachman" << endl << endl << endl;

    // Rubric requirements 
    classRoster.printAll();
    classRoster.printInvalidEmails();
    SetConsoleTextAttribute(h, FOREGROUND_GREEN); cout << "//// Average Days in course for all students ////" << endl << endl;
    for (size_t i = 0; i < classRoster.studentDataTable; i++)
    {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->get_studentID());
    }
    
    classRoster.printByDegreeProgram(DegreeProgramEnum::SOFTWARE);
    classRoster.remove("A3");
    classRoster.printAll();
    classRoster.remove("A3");
    return 0;
    }

// Take data from studentData and inputs it into the Roster class
Roster inputData(const string studentData[], int numOfStudents) {

    const HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    Roster roster;
    string studentIDInput;
    string firstNameInput;
    string lastNameInput;
    string emailAddressInput;
    int ageInput = 0;
    float daysInCourse1Input = 0.00;
    float daysInCourse2Input = 0.00;
    float daysInCourse3Input = 0.00;
    string degreeprogramInput;
    for (size_t i = 0; i < numOfStudents; i++) {
        string str = studentData[i];
        vector<string> vString;
        stringstream sStream(str);
        while (sStream.good()) {
            string substr;
            getline(sStream, substr, ',');
            vString.push_back(substr);
        }
        DegreeProgramEnum degreeprogramInputEnum = DegreeProgramEnum::SOFTWARE;
        for (size_t i = 0; i < vString.size(); i++)
        {

            switch (i)
            {
            case 0:
                studentIDInput = vString[i]; break;
            case 1:
                firstNameInput = vString[i]; break;
            case 2:
                lastNameInput = vString[i]; break;
            case 3:
                emailAddressInput = vString[i]; break;
            case 4:
                ageInput = stoi(vString[i]); break;
            case 5:
                daysInCourse1Input = stof(vString[i]); break;
            case 6:
                daysInCourse2Input = stof(vString[i]); break;
            case 7:
                daysInCourse3Input = stof(vString[i]); break;
            case 8:
                degreeprogramInput = vString[i];
					if (degreeprogramInput == "SECURITY") { degreeprogramInputEnum = DegreeProgramEnum::SECURITY;  break; }
                    if (degreeprogramInput == "NETWORK") { degreeprogramInputEnum = DegreeProgramEnum::NETWORK; break; }
                    if (degreeprogramInput == "SOFTWARE") { degreeprogramInputEnum = DegreeProgramEnum::SOFTWARE; break;}
                    SetConsoleTextAttribute(h, FOREGROUND_RED); cout << "ERROR:"; SetConsoleTextAttribute(h, FOREGROUND_BLUE); cout << " Unknown Degree Program Was Entered." << endl; break;
            default:
                break;
            }


        }
    	//cout << YELLOW << studentIDInput << " " << firstNameInput << " " << lastNameInput << " " << emailAddressInput << " " << ageInput << " " << daysInCourse1Input << " " << daysInCourse2Input << " " << daysInCourse3Input << " " << degreeprogramInput << endl;
        roster.add(studentIDInput, firstNameInput, lastNameInput, emailAddressInput, ageInput, daysInCourse1Input, daysInCourse2Input, daysInCourse3Input, degreeprogramInputEnum);

    }
    return roster;
}