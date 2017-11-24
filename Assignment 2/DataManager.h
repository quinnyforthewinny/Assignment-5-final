#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <string>
#include <vector>
#include "Student.h"
using std::vector;
using std::string;

class DataManager
{
private:
	vector<Student> info;
	string inputFile;
	void splitString(vector<string> &, const string &, char);

public:
	DataManager(const string &);
	void readDataFile();
	void writeDataFile();
	void display();
	void addStudent(Student&);
	Student * findStudent(int);
	DataManager::~DataManager();
};

#endif // !1
