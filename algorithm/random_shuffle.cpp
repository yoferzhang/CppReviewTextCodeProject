#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

void printIntVector(vector<int> &v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
		cout << *it << ' ';
	}
	cout << endl;
}

void play_random_shuffle()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(5);
	v.push_back(7);
	v.push_back(9);

	printIntVector(v);
	// 1 3 5 7 9

	srand(time(0));
	random_shuffle(v.begin(), v.end());

	printIntVector(v);
	// 1 5 9 3 7
}



int main()
{
	play_random_shuffle();

	return 0;
}