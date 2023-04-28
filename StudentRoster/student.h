#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"
using std::string;
using std::cout;

class Student
{

public:
	const static int daysToCompleteClass = 3;

private:
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int daysToComplete[daysToCompleteClass];
	DegreeProgram degreeprogram;

public:
	Student(); 
	Student(string studentID, string firstName, string lastName, string email,
		int age, int daysToComplete[], DegreeProgram degreeProgram); //full constructor
	~Student(); //destructor

	//getters 
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int* getDaysToComplete();
	DegreeProgram getDegreeProgram();

	//setters
	void setStudentId(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string email);
	void setAge(int age);
	void setDaysToComplete(int daysToComplete[]);
	void setDegreeType(DegreeProgram degreeProgram);

	//print methods
	static void printHeader();
	void print();

};