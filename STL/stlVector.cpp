#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void vectorSample()
{
	vector<int> v1;

	cout << "length of v1: " << v1.size() << endl;
	// length of v1: 0
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	cout << "length of v1: " << v1.size() << endl;
	// length of v1: 3

	cout << "front element: " << v1.front() << endl;
	// front element: 1

	// �޸�ͷ��Ԫ��
	// ��������ֵ����ֵ��Ӧ�÷���һ������
	v1.front() = 11;
	v1.back() = 55;

	while (v1.size() > 0) {
		cout << "back element: " << v1.back() << endl; // ��ȡβ��Ԫ��
		v1.pop_back(); // ɾ��β��Ԫ��
	}
	cout << endl;
}

void vectorInit()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);

	vector<int> v2 = v1; // �������캯����ʼ������

	vector<int> v3(v1.begin(), v1.begin() + 2);
	cout << "length of v3: " << v3.size() << endl;
	// length of v3: 2

}

void printV(vector<int> &v)
{
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ' ';
	}
	cout << endl;
}

void vectorErgodic()
{
	/*
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1[i] = i + 1; // ����ֱ�ӱ���
	}
	*/

	vector<int> v1(10); // ��ǰ���ڴ�׼���ã�����ʼ��Ϊ0
	printV(v1);
	cout << endl;
	// 0 0 0 0 0 0 0 0 0 0

	for (int i = 0; i < 10; i++) {
		v1[i] = i + 1;
	}
	/*
	for (int i = 0; i < 10; i++) {
		cout << v1[i] << ' ';
	}
	cout << endl;
	*/

	printV(v1);
	cout << endl;
	// 1 2 3 4 5 6 7 8 9 10

	v1.push_back(100);
	v1.push_back(200);
	printV(v1);
	cout << endl;
	// 1 2 3 4 5 6 7 8 9 10 100 200
}

void vectorIterator()
{
	vector<int> v1(10);
	for (int i = 0; i < 10; i++) {
		v1[i] = i + 1;
	}

	// ���������
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
		cout << *it << ' ';
	}
	// 1 2 3 4 5 6 7 8 9 10
	cout << endl;

	// ���������
	for (vector<int>::reverse_iterator rit = v1.rbegin(); rit != v1.rend(); rit++) {
		cout << *rit << ' ';
	}
	// 10 9 8 7 6 5 4 3 2 1
	cout << endl;
}

void vectorDelete()
{
	vector<int> v1(10);
	for (int i = 0; i < 10; i++) {
		v1[i] = i + 1;
	}
	
	// ����ɾ��
	v1.erase(v1.begin(), v1.begin() + 3);
	printV(v1);
	// 4 5 6 7 8 9 10

	// ����Ԫ�ص�λ��ɾ��
	v1.erase(v1.begin()); // ��ͷ��ɾ��һ��Ԫ��
	printV(v1);
	// 5 6 7 8 9 10

	v1[1] = 2;
	v1[3] = 2;
	printV(v1);
	// 5 2 7 2 9 10

	for (vector<int>::iterator it = v1.begin(); it != v1.end();) {
		if (*it == 2) {
			it = v1.erase(it); // ��ɾ��������ָ��Ԫ��ɾ����eraseɾ����������it�Զ�����ƶ�
		}
		else {
			it++;
		}
	}
	printV(v1);
	// 5 7 9 10

	v1.insert(v1.begin(), 100);
	v1.insert(v1.end(), 200);
	printV(v1);
	// 100 5 7 9 10 200
}

int main()
{
	vectorSample();
	vectorInit();
	vectorErgodic();
	vectorIterator();
	vectorDelete();

	return 0;
}