#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

// string�ĳ�ʼ��
void initString()
{
	cout << "init of string object\n";
	string s1 = "lucifer";
	string s2("zhang");
	string s3 = s2; // ͨ���������캯������ʼ������s3
	string s4(10, 'a');

	cout << "s1: " << s1 << endl;
	cout << "s2: " << s2 << endl;
	cout << "s3: " << s3 << endl;
	cout << "s4: " << s4 << endl;
	cout << endl;
}

// ����string
void ergodic()
{
	cout << "ergodic of string object\n";
	string s = "lucifer";

	// 1���鷽ʽ
	for (unsigned int i = 0; i < s.length(); i++) {
		cout << s[i] << ' ';
	}
	cout << endl;

	// 2��������ʽ
	for (string::iterator it = s.begin(); it != s.end(); it++) {
		cout << *it << ' ';
	}
	cout << endl;

	// 3at()����
	try
	{
		for (unsigned int i = 0; i < s.length() + 3; i++) {
			cout << s.at(i) << ' '; // �׳��쳣
		}
		cout << endl;
	}
	catch (...)
	{
		cout << "�����쳣\n";
	}
	cout << endl;

	// ������±꣬����ֱ�Ӿ���ֹ��
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

// �ַ�ָ���string��ת��
void char2string()
{
	string s = "lucifer";

	// string -> char*
	cout << s.c_str() << endl;

	// string������copy��buf��
	char buf[128] = { 0 };
	s.copy(buf, 3, 0); // ע�⣬ֻcopy3���ַ���������C�����ַ���
	cout << "buf: " << buf << endl;
	cout << endl;
}

// string������
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

// string���Һ��滻
void stringFindAndReplace()
{
	string s = "lucifer hello lucifer 111 lucifer 222 lucifer 333";

	int index = s.find("lucifer", 0); // ��λ���±�0��ʼ����
	cout << "index: " << index << endl;

	// ���lucifer���ֵĴ�����ÿһ�γ��ֵ������±�
	int offIndex = s.find("lucifer", 0);
	while (offIndex != string::npos) {
		cout << "off index: " << offIndex << endl;
		offIndex = s.find("lucifer", ++offIndex);
	}

	// ��s�е�lucifer�滻�ɴ�д
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

// �ضϣ�����ɾ�����Ͳ���
void stringDelete()
{
	string s = "hello lucifer hello";
	string::iterator it = find(s.begin(), s.end(), 'l');
	if (it != s.end()) {
		s.erase(it);
	}
	cout << "after delete 'l': " << s << endl;
	// after delete 'l': helo lucifer hello

	s.erase(s.begin(), s.end()); // ȫ��ɾ��
	cout << "after delete all: " << s << endl;
	// after delete all:

	string s2 = "zhang";
	s2.insert(0, "lucifer"); // ͷ�巨
	cout << "after insert: " << s2 << endl;
	// after insert: luciferzhang

	s2.insert(s2.length(), "hello"); // β�巨
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