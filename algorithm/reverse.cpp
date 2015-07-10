#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

void printIntVector(vector<int> &v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
		cout << *it << ' ';
	}
	cout << endl;
}

void play_reverse()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(5);
	v.push_back(7);
	v.push_back(9);

	printIntVector(v);
	// 1 3 5 7 9

	reverse(v.begin(), v.end());

	printIntVector(v);
	// 9 7 5 3 1
}



int main()
{
	play_reverse();

	return 0;
}