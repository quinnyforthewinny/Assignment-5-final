// Assignment2.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <vector>
#include<iostream>
#include "Student.h"
#include "DataManager.h"
using namespace std;


int main()
{
	DataManager datam("data.txt");

	Student student_1("Quinlan", "Hunter", 20, "Male");
	Student student_2("Quinlan", "Curran", 22, "Male");
	Student student_3("Bickford", "Kristina", 25, "Female");
	Student student_4("Kazansky", "Thomas", 25, "Female");

	datam.addStudent(student_1);
	datam.addStudent(student_2);
	datam.addStudent(student_3);
	datam.addStudent(student_4);

	datam.display();

	/*
	//Declares the vector 'StudentInfo'
	vector<Student> StudentInfo;

	//Student objects are created and arguments are passed
	Student student_1(123456, "Hunter", 20, "Male");
	Student student_2(123457, "Curran", 22, "Male");
	Student student_3(123458, "Kristina", 25, "Female");

	//Each student is added to the vector
	StudentInfo.push_back(student_1);
	StudentInfo.push_back(student_2);
	StudentInfo.push_back(student_3);

	//iteratting through the Vector to print all the information for each student
	for (int i = 0; i < StudentInfo.size(); i++) {
		cout << "Student ID: " << StudentInfo[i].getStudentID() << endl;
		cout << "Student Name: " << StudentInfo[i].getStudentName() << endl;
		cout << "Student Age: " << StudentInfo[i].getStudentAge() << endl;
		cout << "Student Gender: " << StudentInfo[i].getStudentGender() << endl;
		cout << endl;
	}
	/*
	Here we try to set a new variable to take the information of the first item in the vector.
	It does not work because we can not simply take the information from one object and assign it to another.
	What we are doing here is more on the lines of renaming the student in the first vector position.

	Student student1 = StudentInfo.at(0);
	student1.setStudentAge(22);

	/*
	Here we are creating a pointer to the second student in the vector. The reason this works is
	because we are telling the program to look at the second student, now change the gender of that student.
	We are doing this by the reference.

	Student *student2 = &StudentInfo.at(1);
	student2->setStudentGender("Female");

	/*
	The third student is being addressed through the memory address. We are passing the new arguments by reference.

	Student &student3 = StudentInfo.at(2);
	student3.setStudentID(111111);

	//Printing out the updated student info.
	for (int j = 0; j < StudentInfo.size(); j++) {
		cout << "Student ID: " << StudentInfo[j].getStudentID() << endl;
		cout << "Student Name: " << StudentInfo[j].getStudentName() << endl;
		cout << "Student Age: " << StudentInfo[j].getStudentAge() << endl;
		cout << "Student Gender: " << StudentInfo[j].getStudentGender() << endl;
		cout << endl;
	}


	return 0;
}*/
}
