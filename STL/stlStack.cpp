#include <iostream>
#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;

void stackInit()
{
	stack<int> s;
	
	// ��ջ
	for (int i = 0; i < 10; ++i) {
		s.push(i + 1);
	}
	cout << "size of s: " << s.size() << endl;

	while (!s.empty()) {
		cout << s.top() << ' '; // ��ȡջ��Ԫ��
		s.pop(); // ����ջ��Ԫ��
	}
	cout << endl;
}

class Teacher
{
public:
	int age;
	char name[32];
public:
	void printTeacher()
	{
		cout << "age: " << age << endl;
	}
};

void stackClass()
{
	Teacher t1, t2, t3;
	t1.age = 21;
	t2.age = 22;
	t3.age = 23;

	stack<Teacher> s;
	s.push(t1);
	s.push(t2);
	s.push(t3);

	while (!s.empty()) {
		Teacher tmp = s.top();
		s.pop();
		tmp.printTeacher();
	}
	/*
	age: 23
	age: 22
	age: 21
	*/
	cout << endl;
}

void stackClassP()
{
	Teacher t1, t2, t3;
	t1.age = 21;
	t2.age = 22;
	t3.age = 23;

	stack<Teacher *> s;
	s.push(&t1);
	s.push(&t2);
	s.push(&t3);

	while (!s.empty()) {
		Teacher *tmp = s.top();
		s.pop();
		tmp->printTeacher();
	}
	/*
	age: 23
	age: 22
	age: 21
	*/
}

int main()
{
	stackInit();
	stackClass();
	stackClassP();

	return 0;
}