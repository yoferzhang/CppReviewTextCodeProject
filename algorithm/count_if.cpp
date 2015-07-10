#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

bool GreaterThree(const int &a)
{
	return a > 3;
}

void play_count_if()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(7);
	v1.push_back(9);
	v1.push_back(3);

	int cnt = count_if(v1.begin(), v1.end(), GreaterThree);
	cout << "count of greater 3: " << cnt << endl;
	// count of greater 3: 3

}

int main()
{
	play_count_if();

	return 0;
}