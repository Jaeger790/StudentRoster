#include "roster.h"
#include "degree.h"
#include "student.h "
#include <vector>
#include <regex>
using namespace std;


//parse student data table array
void Roster::parse(string studentData) {

	std::regex regex("\\,");
	std::vector<string> field(std::sregex_token_iterator(studentData.begin(), studentData.end(), regex, -1),
		std::sregex_token_iterator());
	
	//default degree program
	DegreeProgram degreeprogram = DegreeProgram::UNDECIDED;
	
	//check last character of string to confirm degree type
	if (field.at(8).back() == 'Y') {
		degreeprogram = DegreeProgram::SECURITY;
	}
	if (field.at(8).back() == 'K') {
		degreeprogram = DegreeProgram::NETWORK;
	}
	if (field.at(8).back() == 'E') {
		degreeprogram = DegreeProgram::SOFTWARE;
	}

	add(field.at(0), field.at(1), field.at(2),
		field.at(3), std::stoi(field.at(4)), std::stoi(field.at(5)), 
		std::stoi(field.at(6)), std::stoi(field.at(7)), degreeprogram);

}	

void Roster::add(string studentID, string firstName, string lastName, string emailAddress,
				 int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {

	int dayArray[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };

	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, dayArray, degreeprogram);
}

//print entire roster with header
void Roster::printAll() {

	Student::printHeader();

	for (int i = 0; i <= Roster::lastIndex; i++) {
		this->classRosterArray[i]->print();
	}
}

//print by degree type with header
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	
	Student::printHeader();

	for (int i = 0; i <= Roster::lastIndex; i++) {
		
		if (this->classRosterArray[i]->getDegreeProgram() == degreeProgram) {
			this->classRosterArray[i]->print();
		}
	}
	std::cout << std::endl;
}

//invalid email: must have '@' , '.' , and no ' '.
void Roster::printInvalidEmails() {
	
	bool validEmail = true;
	
	for (int i = 0; i <= Roster::lastIndex; i++) {
		string email = (classRosterArray[i]->getEmail());

		if ((email.find('@') == string::npos) || ((email.find('.') == string::npos) || (email.find(' ') != string::npos))) {
			validEmail = false;
			std::cout << classRosterArray[i]->getEmail() << std::endl;
		}
	}
	
}

//print the average days to complete 3 courses
void Roster::printAverageDaysInCourse(string studentID) {
	bool validID = false;
	
	for (int i = 0; i <= Roster::lastIndex; i++) {
		

		if (this->classRosterArray[i]->getStudentID() == studentID){
			validID = true;

			double averageDaysToComplete = static_cast<double>(classRosterArray[i]->getDaysToComplete()[0]
				+ classRosterArray[i]->getDaysToComplete()[1]
				+ classRosterArray[i]->getDaysToComplete()[2]) / 3.0;

			std::cout << classRosterArray[i]->getStudentID() << ": ";
			std::cout << averageDaysToComplete;
			std::cout << std::endl;
		}
	}
	if (!validID) {
		std::cout << studentID << ": was not found." << std::endl;
	}
	std::cout << std::endl;
}

//remove student from roster by student ID.
void Roster::removeStudentByID(string studentID) {
	bool validDelete = false;

	for (int i = 0; i <= Roster::lastIndex  ; i++){
		if (this->classRosterArray[i]->getStudentID() == studentID) {
			validDelete = true;

			Student* swap = classRosterArray[lastIndex - 1];
			classRosterArray[i] = swap;
			classRosterArray[lastIndex - 1] = classRosterArray[lastIndex];
			lastIndex--;
			std::cout << studentID << ": was deleted from the roster." << std::endl << std::endl;
		}
		
	}
	if (!validDelete) {
		std::cout << std::endl << studentID << ": was not found" << std::endl;
	}
}
//destructor
Roster::~Roster() {

	std::cout << "Destruction sequence initiated." << std::endl << std::endl;

	for (int i = 0; i <= lastIndex; i++) {

		std::cout << "Releasing Student #" << i + 1 << std::endl;
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
	std::cout << std::endl << "Roster released from memory." << std::endl;
}