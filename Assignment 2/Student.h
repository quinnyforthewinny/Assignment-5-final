#pragma once
#ifndef Student_H
#define Student_H

#include <string>
#include <vector>
using namespace std;

class Student
{
public:
	//constructors
	Student();
	Student(const string&, const string&, int, const string&);

	//get student items
	string getStudentLastName();
	string getStudentFirstName();
	int getStudentID();
	string getStudentMajor();

	//set student items
	void setStudentLastName(string);
	void setStudentFirstName(string);
	void setStudentID(int);
	void setStudentMajor(string);
	void display();

	//deconstructor
	~Student();
private:
	string StudentLastName;
	string StudentFirstName;
	int StudentID;
	string StudentMajor;
};
#endif // !Student_H
