#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

// binary_search是对排序好的进行查找
void play_binary_search()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);
	v1.push_back(9);

	bool b = binary_search(v1.begin(), v1.end(), 7);
	if (b) {
		cout << "find success\n";
	}
	else {
		cout << "find fail\n";
	}
	// find success

}

int main()
{
	play_binary_search();

	return 0;
}