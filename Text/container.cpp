#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

class Person
{
public:
	Person(char *_name, int _age) {
		name = new char[strlen(_name) + 1];
		strcpy(name, _name);
		age = _age;
	}

	~Person() {
		if (name != NULL) {
			delete[] name;
			name = NULL;
			age = 0;
		}
	}

	Person(const Person &obj) {
		name = new char[strlen(obj.name) + 1];
		strcpy(name, obj.name);
		age = obj.age;
	}

	Person &operator=(const Person &obj) {
		// 先把原先的内存释放掉
		if (name != NULL) {
			if (name != NULL) {
				delete[] name;
				name = NULL;
				age = 0;
			}
		}

		// 根据obj的大小分配内存
		name = new char[strlen(obj.name) + 1];
		strcpy(name, obj.name);
		age = obj.age;
		return *this;
	}

	void printPerson()
	{
		cout << "name: " << name << "\tage: " << age << endl;
	}

protected:
private:
	char *name;
	int age;
};

void containerMap()
{
	Person p1("lucifer", 23);
	p1.printPerson();

	vector<Person> v1;
	v1.push_back(p1);
	v1[0].printPerson();
}

int main()
{
	containerMap();

	return 0;
}