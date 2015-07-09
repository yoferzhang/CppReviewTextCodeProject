#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

struct CompareNoCase
{
	bool operator()(const string &str1, const string &str2)
	{
		string tmpstr1;
		tmpstr1.resize(str1.size());
		transform(str1.begin(), str1.end(), tmpstr1.begin(), tolower);

		string tmpstr2;
		tmpstr2.resize(str2.size());
		transform(str2.begin(), str2.end(), tmpstr2.begin(), tolower);

		return tmpstr1 < tmpstr2;
	}
};

void play01()
{
	set<string> set1;
	set1.insert("lucifer");
	set1.insert("zhang");
	set1.insert("yaoqi");

	set<string>::iterator it1 = set1.find("LUcifer"); // find函数默认区分大小写
	if (it1 == set1.end()) {
		cout << "find fail\n";
	}
	else {
		cout << "find success\n";
	}
	// find fail

	set<string, CompareNoCase> set2;
	set2.insert("lucifer");
	set2.insert("zhang");
	set2.insert("yaoqi");
	set<string, CompareNoCase>::iterator it2 = set2.find("LUcifer"); // find函数默认区分大小写
	if (it2 == set2.end()) {
		cout << "find fail\n";
	}
	else {
		cout << "find success\n";
	}
	// find success
	
}

int main()
{
	play01();

	return 0;
}