#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

// ������������ӡ
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

	// ����1
	map1.insert(pair<int, string>(1, "zhang01"));
	map1.insert(pair<int, string>(2, "zhang02"));
	
	// ����2
	map1.insert(make_pair(3, "zhang03"));
	map1.insert(make_pair(4, "zhang04"));

	// ����3
	map1.insert(map<int, string>::value_type(5, "zhang05"));
	map1.insert(map<int, string>::value_type(6, "zhang06"));

	// ����4
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

//��������ַ��� ��ͬ
//ǰ���ַ��� ����ֵΪpair<iterator,bool>	��key�Ѿ����� �򱨴�
//������									��key�Ѿ�����,���޸�	

void mapReturn()
{
	map<int, string> map1;

	// ����1
	pair<map<int, string>::iterator, bool> mypair01 = map1.insert(pair<int, string>(1, "zhang01"));
	pair<map<int, string>::iterator, bool> mypair02 = map1.insert(pair<int, string>(2, "zhang02"));

	// ����2
	map1.insert(make_pair(3, "zhang03"));
	map1.insert(make_pair(4, "zhang04"));

	// ����3
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

	// ����4
	map1[7] = "zhang07";
	map1[7] = "zhang77";

	printMap(map1);
}

void mapFind()
{
	map<int, string> map1;

	// ����1
	map1.insert(pair<int, string>(1, "zhang01"));
	map1.insert(pair<int, string>(2, "zhang02"));

	// ����2
	map1.insert(make_pair(3, "zhang03"));
	map1.insert(make_pair(4, "zhang04"));

	// ����3
	map1.insert(map<int, string>::value_type(5, "zhang05"));
	map1.insert(map<int, string>::value_type(6, "zhang06"));

	// ����4
	map1[7] = "zhang07";
	map1[8] = "zhang08";

	printMap(map1);

	// map���ң��쳣����
	map<int, string>::iterator it2 =  map1.find(100);
	if (it2 == map1.end()) {
		cout << "key 100 is not find\n";
	}
	else {
		cout << it2->first << "\t" << it2->second << endl;
	}
	// key 100 is not find

	// equal_range()�쳣����
	// typedef pair<iterator, iterator> _Pairii;
	pair<map<int, string>::iterator, map<int, string>::iterator> mypair = map1.equal_range(5); // �����������������γ�һ��pair
	// ��һ������������ >= 5��λ��
	// �ڶ������������� > 5��λ��
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