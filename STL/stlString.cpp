#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

// string的初始化
void initString()
{
	cout << "init of string object\n";
	string s1 = "lucifer";
	string s2("zhang");
	string s3 = s2; // 通过拷贝构造函数来初始化对象s3
	string s4(10, 'a');

	cout << "s1: " << s1 << endl;
	cout << "s2: " << s2 << endl;
	cout << "s3: " << s3 << endl;
	cout << "s4: " << s4 << endl;
	cout << endl;
}

// 遍历string
void ergodic()
{
	cout << "ergodic of string object\n";
	string s = "lucifer";

	// 1数组方式
	for (unsigned int i = 0; i < s.length(); i++) {
		cout << s[i] << ' ';
	}
	cout << endl;

	// 2迭代器方式
	for (string::iterator it = s.begin(); it != s.end(); it++) {
		cout << *it << ' ';
	}
	cout << endl;

	// 3at()方法
	try
	{
		for (unsigned int i = 0; i < s.length() + 3; i++) {
			cout << s.at(i) << ' '; // 抛出异常
		}
		cout << endl;
	}
	catch (...)
	{
		cout << "发生异常\n";
	}
	cout << endl;

	// 如果用下标，程序直接就中止了
	/*
	try
	{
		for (unsigned int i = 0; i < s.length() + 3; i++) {
			cout << s[i] << ' ';
		}
		cout << endl;
	}
	catch (...)
	{
		
	}
	*/
}

// 字符指针和string的转换
void char2string()
{
	string s = "lucifer";

	// string -> char*
	cout << s.c_str() << endl;

	// string的内容copy，buf中
	char buf[128] = { 0 };
	s.copy(buf, 3, 0); // 注意，只copy3个字符，不会变成C风格的字符串
	cout << "buf: " << buf << endl;
	cout << endl;
}

// string的连接
void stringAppend()
{
	string s1 = "lucifer ";
	string s2 = "zhang";
	s1 = s1 + s2;
	cout << "s1: " << s1 << endl;

	string s3 = "333";
	string s4 = "444";
	s3.append(s4);
	cout << "s3: " << s3 << endl;
	cout << endl;
}

// string查找和替换
void stringFindAndReplace()
{
	string s = "lucifer hello lucifer 111 lucifer 222 lucifer 333";

	int index = s.find("lucifer", 0); // 从位置下标0开始查找
	cout << "index: " << index << endl;

	// 求出lucifer出现的次数，每一次出现的数组下标
	int offIndex = s.find("lucifer", 0);
	while (offIndex != string::npos) {
		cout << "off index: " << offIndex << endl;
		offIndex = s.find("lucifer", ++offIndex);
	}

	// 把s中的lucifer替换成大写
	offIndex = s.find("lucifer", 0);
	while (offIndex != string::npos) {
		cout << "off index: " << offIndex << endl;
		s.replace(offIndex, 7, "LUCIFER");
		offIndex = s.find("lucifer", ++offIndex);
	}
	cout << "after replace: " << s << endl;
	cout << endl;
	// after replace: LUCIFER hello LUCIFER 111 LUCIFER 222 LUCIFER 333
}

// 截断（区间删除）和插入
void stringDelete()
{
	string s = "hello lucifer hello";
	string::iterator it = find(s.begin(), s.end(), 'l');
	if (it != s.end()) {
		s.erase(it);
	}
	cout << "after delete 'l': " << s << endl;
	// after delete 'l': helo lucifer hello

	s.erase(s.begin(), s.end()); // 全部删除
	cout << "after delete all: " << s << endl;
	// after delete all:

	string s2 = "zhang";
	s2.insert(0, "lucifer"); // 头插法
	cout << "after insert: " << s2 << endl;
	// after insert: luciferzhang

	s2.insert(s2.length(), "hello"); // 尾插法
	cout << "after insert: " << s2 << endl;
	// after insert: luciferzhanghello
	cout << endl;
}

void stringTransform()
{
	string s = "LuciferZhang";
	transform(s.begin(), s.end(), s.begin(), toupper);
	cout << "s: " << s << endl;
	// s: LUCIFERZHANG

	transform(s.begin(), s.end(), s.begin(), tolower);
	cout << "s: " << s << endl;
	// s: luciferzhang

	cout << endl;
}

int main()
{
	initString();
	ergodic();
	char2string();
	stringAppend();
	stringFindAndReplace();
	stringDelete();
	stringTransform();

	return 0;
}