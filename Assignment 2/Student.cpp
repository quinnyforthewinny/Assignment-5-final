#include "stdafx.h"
#include "Student.h"

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

Student::Student()
{
}

//Student initializer
Student::Student(const string &lastName, const string &firstName, int studentID, const string &major) :
	StudentLastName(lastName), StudentFirstName(firstName), StudentID(studentID), StudentMajor(major)
{}

//A series of get and set functions that grab the student information
string Student::getStudentLastName() {
	return StudentLastName;
}

string Student::getStudentFirstName() {
	return StudentFirstName;
}

int Student::getStudentID() {
	return StudentID;
}

string Student::getStudentMajor() {
	return StudentMajor;
}

void Student::setStudentLastName(const string lastName) {
	this->StudentLastName = lastName;
}

void Student::setStudentFirstName(const string firstName) {
	this->StudentFirstName = firstName;
}

void Student::setStudentID(int studentID) {
	this->StudentID = studentID;
}

void Student::setStudentMajor(const string major) {
	this->StudentMajor = major;
}

void Student::display() 
{
	cout << left << setw(15) << StudentLastName;
	cout << setw(25) << StudentFirstName;
	cout << setw(18) << StudentID;
	cout << right << setw(10) << StudentMajor;
	cout << endl;
}

Student::~Student()
{
}
