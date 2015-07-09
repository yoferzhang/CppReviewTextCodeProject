#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

void printVector(vector<int> &v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
		cout << *it << ' ';
	}
	cout << endl;
}

void FuncShowElemt2(const int &t)
{
	cout << t << ' ';
}

// ¶þÔªÎ½´Ê
bool myCompare(const int &a, const int &b)
{
	return a < b;
}

void play01()
{
	vector<int> v(10);

	srand(time(0));
	for (int i = 0; i < 10; i++) {
		int tmp = rand() % 100;
		v[i] = tmp;
	}

	printVector(v);
	// 90 19 94 50 90 90 24 50 30 74

	for_each(v.begin(), v.end(), FuncShowElemt2);
	cout << endl;
	// 90 19 94 50 90 90 24 50 30 74

	sort(v.begin(), v.end(), myCompare);
	for_each(v.begin(), v.end(), FuncShowElemt2);
	cout << endl;
	// 0 8 14 23 32 33 44 45 63 80
}

int main()
{
	play01();

	return 0;
}