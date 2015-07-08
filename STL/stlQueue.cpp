#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

void queueInit()
{
	queue<int> q;
	q.push(1);
	q.push(3);
	q.push(5);

	cout << "size of q: " << q.size() << endl;
	// size of q: 3
	cout << "front element: " << q.front() << endl;
	// front element: 1

	while (!q.empty()) {
		cout << q.front() << ' ';
		q.pop();
	}
	// 1 3 5
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

void queueClass()
{
	Teacher t1, t2, t3;
	t1.age = 21;
	t2.age = 22;
	t3.age = 23;

	queue<Teacher> q1;
	q1.push(t1);
	q1.push(t2);
	q1.push(t3);
	while (!q1.empty()) {
		Teacher tmp = q1.front();
		q1.pop();
		tmp.printTeacher();
	}
	cout << endl;
	/*
	age: 21
	age: 22
	age: 23
	*/

	queue<Teacher *> q2;
	q2.push(&t1);
	q2.push(&t2);
	q2.push(&t3);
	while (!q2.empty()) {
		Teacher *tmp = q2.front();
		q2.pop();
		tmp->printTeacher();
	}
	cout << endl;
	/*
	age: 21
	age: 22
	age: 23
	*/

}

int main()
{
	queueInit();
	queueClass();

	return 0;
}