#include <iostream>
#include <cstdio>
#include <list>
#include <algorithm>

using namespace std;

void printList(list<int> &l)
{
	for (list<int>::iterator it = l.begin(); it != l.end(); ++it) {
		cout << *it << ' ';
	}
	cout << endl;
}

void listInit()
{
	list<int> l;
	cout << "size of l: " << l.size() << endl;
	// size of l: 0

	for (int i = 0; i < 10; ++i) {
		l.push_back(i); // β�巨
	}
	cout << "size of l: " << l.size() << endl;
	// size of l: 10
	
	printList(l);
	// 0 1 2 3 4 5 6 7 8 9

	// list����������
	list<int>::iterator it = l.begin();
	++it;
	++it;
	++it;
	//it = it + 5;// ��֧������ķ�������
	l.insert(it, 100); // ���뵽3��ǰ��
	printList(l);
	// 0 1 2 100 3 4 5 6 7 8 9

	// ����1������Ľ��index����Ǵ�0��λ�ÿ�ʼ��
	// ��3��λ�ò���Ԫ�أ���ԭ����3��λ�ñ��4��λ�ã�ԭ����4��λ�ñ��5��λ��

}

void listDelete()
{
	list<int> l;

	for (int i = 0; i < 10; ++i) {
		l.push_back(i); // β�巨
	}
	printList(l);
	// 0 1 2 3 4 5 6 7 8 9
	list<int>::iterator it1 = l.begin();
	list<int>::iterator it2 = l.begin();
	++it2;
	++it2;
	++it2;
	l.erase(it1, it2);
	printList(l);
	// 3 4 5 6 7 8 9

	l.insert(l.begin(), 100);
	l.insert(l.begin(), 100);
	l.insert(l.begin(), 100);
	printList(l);
	// 100 100 100 3 4 5 6 7 8 9

	l.erase(l.begin());
	printList(l);
	//100 100 3 4 5 6 7 8 9

	l.remove(100);
	printList(l);
	// 3 4 5 6 7 8 9
}

int main()
{
	listInit();
	listDelete();


	return 0;
}