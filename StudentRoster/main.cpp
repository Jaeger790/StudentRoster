#include <iostream>
#include "roster.h"
#include "degree.h"
#include "student.h"
#include <string>

using namespace std;

//assignment header
void assignmentHeader() {
	
	std::cout << "C867-Scripting and Programming: Applications" << std::endl
		<< "Language: C++" << std::endl
		<< "Student ID: 005179312" << std::endl
		<< "Bradley Rott" << std::endl
		<< std::endl;
}

int main() {
	//print assignment header
	assignmentHeader();
	
	const string studentData[5] =

	{	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Bradley,Rott,brott1@wgu.edu,32,30,14,45,SOFTWARE"
	};

	const int numStudents = 5;
	

	Roster classRoster;

	//parse student data table
	for (int i = 0; i < numStudents; i++) {
		classRoster.parse(studentData[i]);
	}
	
	//print all student data to screen
	std::cout << "Display all student data: " << std::endl;
	classRoster.printAll();
	std::cout << std::endl << std::endl;

	//print out invalid email addresses
	std::cout << "Display Invalid Emails" << std::endl << std::endl;
	classRoster.printInvalidEmails();
	std::cout << std::endl << std::endl;
	
	//print out students average days to complete a course
	std::cout << "Display average days to complete a course: " << std::endl;
	for (int i = 0; i < numStudents; i++) {
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
	}

	//print students by degree type
	for (int i = 0; i < 3; i++) {

		std::cout << "Display by degree program: " << degreeProgramString[i] << std::endl;
		classRoster.printByDegreeProgram((DegreeProgram)i);
	}

	//remove student from roster by student ID
	std::cout << "Remove Student by ID." << std::endl << std::endl;
	classRoster.removeStudentByID("A3");
	std::cout << std::endl << std::endl;

	//display updated roster
	classRoster.printAll();

	//confirm student has been deleted
	classRoster.removeStudentByID("A3");
	std::cout << std::endl << std::endl;

	system("pause");
	return 0;
}