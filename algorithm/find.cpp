#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

bool GreaterThree(const int &a)
{
	return a > 3;
}

void play_find()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(7);
	v1.push_back(9);
	v1.push_back(3);

	vector<int>::iterator it = find(v1.begin(), v1.end(), 4);
	if (it == v1.end()) {
		cout << "find fail\n";
	}
	else {
		cout << "find success\n";
	}
	// find success

}

int main()
{
	play_find();

	return 0;
}