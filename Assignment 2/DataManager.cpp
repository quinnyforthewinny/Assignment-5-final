#include "stdafx.h"
#include "DataManager.h"
#include "Student.h"
#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
using std::string;
using std::cout;


DataManager::DataManager(const string &path) : inputFile(path)
{
	readDataFile();
}

void DataManager::readDataFile()
{
	string line;
	ifstream input(inputFile);

	if (input.fail())
	{
		cerr << "File not found. Will Exit" << endl;
		exit(1);
	}

	while (!input.eof())
	{
		string line;
		vector<string> fieldVector;
		getline(input, line);
		splitString(fieldVector, line, '\t');

		if (fieldVector.size() == 4)
		{

			string lastName = fieldVector[0];
			string firstName = fieldVector[1];
			unsigned studentID = stoi(fieldVector[2]);
			string studentMajor = fieldVector[3];

			Student newStudent(lastName, firstName, studentID, studentMajor);
			info.push_back(newStudent);
		}
	}
}



void DataManager::writeDataFile() {

		ofstream outputFile(inputFile);
		ostringstream s;

		for (auto &start : info) {
			string lName = start.getStudentLastName();
			string fName = start.getStudentFirstName();
			int sID = start.getStudentID();
			string sMajor = start.getStudentMajor();

			s << lName << '\t' << fName << '\t' << sID << '\t' << sMajor << '\t' << endl;
		}
		outputFile << s.str() << endl;
	}

void DataManager::display()
{
	cout << left << setw(15) << "Last Name";
	cout << setw(25) << "First Name";
	cout << setw(18) << "Student ID";
	cout << right << setw(10) << "Student Major";
	cout << endl;

	for (int i = 0; i < info.size(); i++) {
		Student newStudent = info[i];
	}
	cout << string(75, '-') << endl;
}

Student *DataManager::findStudent(int n)
{
	for (int i = 0; i < info.size(); i++) {
		if (n == info[i].getStudentID()) {
			return &info[i];
		}
		return NULL;
	}
}

void DataManager::splitString(vector<string>& info, const string & text, char sep) {

		istringstream ss(text);
		string field;

		while (getline(ss, field, sep)) {
			info.push_back(field);
		}
	}

void DataManager::addStudent(Student &s) {
		Student *it = findStudent(s.getStudentID());
			if (it == NULL)
			{
				info.push_back(s);
			}
	}




	DataManager::~DataManager()
	{
		writeDataFile();
	}

