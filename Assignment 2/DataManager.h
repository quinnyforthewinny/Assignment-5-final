#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <string>
#include <vector>
#include <map>
#include "Student.h"
using std::map;
using std::vector;
using std::string;

typedef map<unsigned, Student> studentMap;

class DataManager
{
private:
	vector<Student> info;
	studentMap readDataFile();
	studentMap studentMap;
	string inputFile;
	void splitString(vector<string> &, const string &, char);

public:
	DataManager(const string &);
	
	void writeDataFile();
	void display();
	void addStudent(Student&);
	Student * findStudent(int);
	DataManager::~DataManager();
};

#endif // !1
