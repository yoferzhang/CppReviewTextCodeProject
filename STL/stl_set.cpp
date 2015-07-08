#include <iostream>
#include <cstdio>
#include <ctime>
#include <set>
#include <functional>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

void printSet(set<int> &s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); ++it) {
		cout << *it << ' ';
	}
	cout << endl;
}

void setInit()
{
	set<int> set1;
	for (int i = 0; i < 5; i++) {
		int tmp = rand();
		set1.insert(tmp);
	}
	// 插入元素
	set1.insert(100);
	set1.insert(100);
	set1.insert(100);

	// 自动排序，默认情况下是从小到大
	printSet(set1);
	// 100 2076 8661 9632 10043 14926

	// 删除元素
	//set1.clear();
	while (!set1.empty()) {
		set1.erase(set1.begin());
	}
	printSet(set1);
	cout << endl;
}

void setGreater()
{
	set<int> set1;
	set<int, less<int> > set2;
	set<int, greater<int> > set3;

	for (int i = 0; i < 5; ++i) {
		int tmp = rand();
		set3.insert(tmp);
	}

	//printSet(set3); // 不能使用这个函数了
	for (set<int, greater<int> >::iterator it = set3.begin(); it != set3.end(); ++it) {
		cout << *it << ' ';
	}
	cout << endl;
	// 21698 10498 5437 4902 1864
}

class Student
{
public:
	Student(char *_name, int _age) {
		strcpy(name, _name);
		age = _age;
	}
public:
	char name[32];
	int age;
};

// 仿函数用法
struct FuncStudent
{
	bool operator()(const Student &left, const Student &right) {
		return left.age < right.age;
	}
};

void setFuncStudend()
{
	set<Student, FuncStudent> set1;

	Student s1("s1", 12);
	Student s2("s2", 43);
	Student s3("s3", 25);
	Student s4("s4", 14);
	Student s5("s5", 43);

	set1.insert(s1);
	set1.insert(s2);
	set1.insert(s3);
	set1.insert(s4);
	set1.insert(s5); // 按照年龄排序，有两个43，第二次就不插入了

	// 遍历
	for (set<Student, FuncStudent>::iterator it = set1.begin(); it != set1.end(); ++it)	{
		cout << it->age << "\t" << it->name << endl;
	}
	/*
	12      s1
	14      s4
	25      s3
	43      s2
	*/

}

// 如果判断set1.insert函数的返回值
void setPari()
{
	set<Student, FuncStudent> set1;

	Student s1("s1", 12);
	Student s2("s2", 43);
	Student s3("s3", 25);
	Student s4("s4", 14);
	Student s5("s5", 43);

	pair<set<Student, FuncStudent>::iterator, bool> it1 = set1.insert(s1);
	set1.insert(s2);
	set1.insert(s3);
	set1.insert(s4);
	pair<set<Student, FuncStudent>::iterator, bool> it5 = set1.insert(s5); // 按照年龄排序，有两个43，第二次就不插入了

	if (it1.second == true) {
		cout << "s1 insert success\n";
	}
	else {
		cout << "s1 insert fail\n";
	}
	// s1 insert success

	if (it5.second == true) {
		cout << "s5 insert success\n";
	}
	else {
		cout << "s5 insert fail\n";
	}
	// s5 insert fail
}

void setFind()
{
	set<int> set1;
	for (int i = 0; i < 10; i++) {
		set1.insert(i + 1);
	}

	printSet(set1);
	// 1 2 3 4 5 6 7 8 9 10

	set<int>::iterator it0 = set1.find(5);
	cout << "it0: " << *it0 << endl;
	// it0: 5

	int num = set1.count(5); // 5的个数
	cout << "num: " << num << endl;
	// num: 1

	set<int>::iterator it1 = set1.lower_bound(5); // 大于等于5的元素的迭代器位置
	cout << "it1: " << *it1 << endl;
	// it1: 5

	set<int>::iterator it2 = set1.upper_bound(5); // 大于5的元素的迭代器位置
	cout << "it2: " << *it2 << endl;
	// it2: 6

	//set1.erase(5);
	pair<set<int>::iterator, set<int>::iterator> mypair = set1.equal_range(5);
	cout << *mypair.first << endl;
	// 5
	// 如果先执行set1.erase(5);则这里输出6

	cout << *mypair.second << endl;
	// 6
}

int main()
{
	srand(time(0));
	setInit();
	setGreater();
	setFuncStudend();
	setPari();
	setFind();

	return 0;
}