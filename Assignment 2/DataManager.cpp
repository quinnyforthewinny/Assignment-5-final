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
#include <map>
#include <iterator>
using std::iterator;
using std::map;
using std::string;
using std::cout;


DataManager::DataManager(const string &path) : inputFile(path)
{
	readDataFile();
}

studentMap DataManager::readDataFile()
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

			//Add newStudent to the studentMap
			studentMap.insert(std::pair<unsigned, Student>(studentID, newStudent));
		}
	}
}



void DataManager::writeDataFile() {

		ofstream outputFile(inputFile);
		ostringstream s;

		for (auto it = studentMap.begin(); it != studentMap.end(); it++) {
			string lName = it->second.getStudentLastName();
			string fName = it->second.getStudentFirstName();
			int sID = it->second.getStudentID();
			string sMajor = it->second.getStudentMajor();

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

	/**for (int i = 0; i < studentMap.size(); i++) {
		Student newStudent = studentMap[i];**/

	for (auto it = studentMap.begin(); it != studentMap.end(); it++) {

		cout << left << setw(15) << it->second.getStudentLastName();
		cout << setw(25) << it->second.getStudentFirstName();
		cout << setw(18) << it->second.getStudentID();
		cout << right << setw(10) << it->second.getStudentMajor();
		cout << endl;

	}
	cout << string(75, '-') << endl;
}

Student *DataManager::findStudent(int n)
{
	auto it = studentMap.find(n);

	if (it == studentMap.end()) {
		return NULL;
	}

	return &it->second;
	/*for (int i = 0; i < info.size(); i++) {
		if (n == info[i].getStudentID()) {
			return &info[i];
		}
		return NULL;
	}*/

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
				studentMap.insert(std::pair<unsigned, Student>(s.getStudentID(), s));
			}
	}




	DataManager::~DataManager()
	{
		writeDataFile();
	}

