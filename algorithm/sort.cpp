#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Student
{
public:
	Student(string name, int id) : name(name), id(id) {}
	friend bool CompareStudent(Student &s1, Student &s2);

	string name;
	int id;
};

bool CompareStudent(Student &s1, Student &s2)
{
	return s1.id < s2.id;
}

void play_sort()
{
	Student s1("lucifer", 1);
	Student s2("zhang", 2);
	Student s3("yao", 3);
	Student s4("qi", 4);
	vector<Student> v;
	v.push_back(s4);
	v.push_back(s2);
	v.push_back(s1);
	v.push_back(s3);

	for (vector<Student>::iterator it = v.begin(); it != v.end(); ++it) {
		cout << "name: " << it->name << " id: " << it->id << endl;
	}
	/*
	name: qi id: 4
	name: zhang id: 2
	name: lucifer id: 1
	name: yao id: 3
	*/

	sort(v.begin(), v.end(), CompareStudent);

	for (vector<Student>::iterator it = v.begin(); it != v.end(); ++it) {
		cout << "name: " << it->name << " id: " << it->id << endl;
	}
	/*
	name: lucifer id: 1
	name: zhang id: 2
	name: yao id: 3
	name: qi id: 4
	*/
}



int main()
{
	play_sort();

	return 0;
}