#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

bool GreaterThree(const int &a)
{
	return a > 3;
}

void play_find_if()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(7);
	v1.push_back(9);
	v1.push_back(3);

	vector<int>::iterator it = find_if(v1.begin(), v1.end(), GreaterThree);
	if (it == v1.end()) {
		cout << "find fail\n";
	}
	else {
		cout << "find success\n";
		cout << "value: " << *it << endl;
	}
	// find success
	// value: 4

}

int main()
{
	play_find_if();

	return 0;
}