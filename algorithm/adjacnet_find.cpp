#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

void play_adjacent_find()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(5);

	vector<int>::iterator it = adjacent_find(v1.begin(), v1.end());
	if (it == v1.end())
	{
		cout << "没有找到 重复的元素" << endl;
	}
	else
	{
		cout << *it << endl;
	}
	// 2
	int index = distance(v1.begin(), it);
	cout << index << endl;
	// 1

}

int main()
{
	play_adjacent_find();

	return 0;
}