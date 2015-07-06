#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	double pi = 3.1415926;
	int num1 = (int)pi; // C����ת��
	int num2 = static_cast<int>(pi); // ��̬����ת���������ʱ��C++�������������ͼ��
	int num3 = pi; // C��������ʽ����ת���ĵط�������ʹ��static_cast<>()��������ת��

	char *p1 = "hello";
	int *p2 = NULL;
	//p2 = static_cast<int *>(pi); // ʹ��static_cast������ʱ�������ᱨ��
	// �������ͼ�飬���д�����ʾ����

	p2 = reinterpret_cast<int *>(p1); // ����ͬ����֮�䣬����ǿ������ת������reinterpret_cast<>()�������½���

	cout << "p1: " << p1 << endl; // %s
	cout << "p2: " << p2 << endl; // %d
	/*
	p1: hello
	p2: 0127CA54
	*/

	return 0;
}