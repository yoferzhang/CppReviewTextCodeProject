#include <iostream>
#include <cstdio>
#include <deque>
#include <algorithm>

using namespace std;

void printDeque(deque<int> &d)
{
	for (deque<int>::iterator it = d.begin(); it != d.end(); it++) {
		cout << *it << ' ';
	}
	cout << endl;
}

void dequeInit()
{
	deque<int> d1;
	d1.push_back(1);
	d1.push_back(3);
	d1.push_back(5);

	d1.push_front(-11);
	d1.push_front(-33);
	d1.push_front(-55);
	printDeque(d1);
	// -55 -33 -11 1 3 5

	cout << "front element: " << d1.front() << endl;
	// front element: -55
	cout << "back element: " << d1.back() << endl;
	// back element: 5
	
	d1.pop_front();
	d1.pop_back();
	printDeque(d1);
	// -33 -11 1 3

	// 查找1在d1中的位置
	deque<int>::iterator it = find(d1.begin(), d1.end(), 1);
	if (it != d1.end()) {
		cout << "position of 1: " << distance(d1.begin(), it) << endl;
	}
	else {
		cout << "no 1\n";
	}
	// position of 1: 2
}

int main()
{
	dequeInit();

	return 0;
}