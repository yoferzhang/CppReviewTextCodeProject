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
		l.push_back(i); // 尾插法
	}
	cout << "size of l: " << l.size() << endl;
	// size of l: 10
	
	printList(l);
	// 0 1 2 3 4 5 6 7 8 9

	// list不能随便访问
	list<int>::iterator it = l.begin();
	++it;
	++it;
	++it;
	//it = it + 5;// 不支持随机的访问容器
	l.insert(it, 100); // 插入到3的前面
	printList(l);
	// 0 1 2 100 3 4 5 6 7 8 9

	// 结论1：链表的结点index序号是从0号位置开始的
	// 在3号位置插入元素，让原来的3号位置变成4号位置，原来的4号位置变成5号位置

}

void listDelete()
{
	list<int> l;

	for (int i = 0; i < 10; ++i) {
		l.push_back(i); // 尾插法
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