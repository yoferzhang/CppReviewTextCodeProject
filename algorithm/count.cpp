#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

// binary_search是对排序好的进行查找
void play_count()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(3);
	v1.push_back(7);
	v1.push_back(9);
	v1.push_back(3);

	int cnt = count(v1.begin(), v1.end(), 3);
	cout << "count of 3: " << cnt << endl;
	// count of 3: 3

}

int main()
{
	play_count();

	return 0;
}