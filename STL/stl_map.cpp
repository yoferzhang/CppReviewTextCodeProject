#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

// 迭代器遍历打印
void printMap(map<int, string> &m)
{
	for (map<int, string>::iterator it = m.begin(); it != m.end(); ++it) {
		cout << it->first << "\t" << it->second << endl;
	}
	cout << endl;
}

void mapInit()
{
	map<int, string> map1;

	// 方法1
	map1.insert(pair<int, string>(1, "zhang01"));
	map1.insert(pair<int, string>(2, "zhang02"));
	
	// 方法2
	map1.insert(make_pair(3, "zhang03"));
	map1.insert(make_pair(4, "zhang04"));

	// 方法3
	map1.insert(map<int, string>::value_type(5, "zhang05"));
	map1.insert(map<int, string>::value_type(6, "zhang06"));

	// 方法4
	map1[7] = "zhang07";
	map1[8] = "zhang08";

	printMap(map1);
	/*
	1       zhang01
	2       zhang02
	3       zhang03
	4       zhang04
	5       zhang05
	6       zhang06
	7       zhang07
	8       zhang08
	*/

	while (!map1.empty()) {
		map<int, string>::iterator it = map1.begin();
		cout << it->first << "\t" << it->second << endl;
		map1.erase(it);
	}
	printMap(map1);
}

//插入的四种方法 异同
//前三种方法 返回值为pair<iterator,bool>	若key已经存在 则报错
//方法四									若key已经存在,则修改	

void mapReturn()
{
	map<int, string> map1;

	// 方法1
	pair<map<int, string>::iterator, bool> mypair01 = map1.insert(pair<int, string>(1, "zhang01"));
	pair<map<int, string>::iterator, bool> mypair02 = map1.insert(pair<int, string>(2, "zhang02"));

	// 方法2
	map1.insert(make_pair(3, "zhang03"));
	map1.insert(make_pair(4, "zhang04"));

	// 方法3
	pair<map<int, string>::iterator, bool> mypair05 = map1.insert(map<int, string>::value_type(5, "zhang05"));
	if (mypair05.second) {
		cout << "key 5 insert success\n";
		cout << mypair05.first->first << "\t" << mypair05.first->second << endl;
	}
	else {
		cout << "key 5 insert fail\n";
	}
	// key 5 insert success
	// 5       zhang05

	pair<map<int, string>::iterator, bool> mypair06 = map1.insert(map<int, string>::value_type(5, "zhang55"));
	if (mypair06.second) {
		cout << "key 5 insert success\n";
		cout << mypair06.first->first << "\t" << mypair06.first->second << endl;
	}
	else {
		cout << "key 5 insert fail\n";
	}
	// key 5 insert fail

	// 方法4
	map1[7] = "zhang07";
	map1[7] = "zhang77";

	printMap(map1);
}

void mapFind()
{
	map<int, string> map1;

	// 方法1
	map1.insert(pair<int, string>(1, "zhang01"));
	map1.insert(pair<int, string>(2, "zhang02"));

	// 方法2
	map1.insert(make_pair(3, "zhang03"));
	map1.insert(make_pair(4, "zhang04"));

	// 方法3
	map1.insert(map<int, string>::value_type(5, "zhang05"));
	map1.insert(map<int, string>::value_type(6, "zhang06"));

	// 方法4
	map1[7] = "zhang07";
	map1[8] = "zhang08";

	printMap(map1);

	// map查找，异常处理
	map<int, string>::iterator it2 =  map1.find(100);
	if (it2 == map1.end()) {
		cout << "key 100 is not find\n";
	}
	else {
		cout << it2->first << "\t" << it2->second << endl;
	}
	// key 100 is not find

	// equal_range()异常处理
	// typedef pair<iterator, iterator> _Pairii;
	pair<map<int, string>::iterator, map<int, string>::iterator> mypair = map1.equal_range(5); // 返回两个迭代器，形成一个pair
	// 第一个迭代器返回 >= 5的位置
	// 第二个迭代器返回 > 5的位置
	if (mypair.first == map1.end()) {
		cout << "first iterator >= 5 position is not find\n";
	}
	else {
		cout << mypair.first->first << "\t" << mypair.first->second << endl;
	}
	// 5       zhang05

	if (mypair.second == map1.end()) {
		cout << "first iterator > 5 position is not find\n";
	}
	else {
		cout << mypair.second->first << "\t" << mypair.second->second << endl;
	}
	// 6       zhang06

}

int main()
{
	mapInit();
	mapReturn();
	mapFind();

	return 0;
}