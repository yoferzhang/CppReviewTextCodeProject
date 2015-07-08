#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

void printPriorityQ(priority_queue<int> &pq)
{
	while (!pq.empty()) {
		cout << pq.top() << ' ';
		pq.pop();
	}
	cout << endl;
}

void priorityQueueInit()
{
	priority_queue<int> pq1; // Ĭ������������ֵ���ȼ�����
	priority_queue<int, vector<int>, less<int> > pq2; // ��ǰ����õ�Ԥ���庯����ν��
	priority_queue<int, vector<int>, greater<int> > pq3; // ��Сֵ���ȼ�����

	pq1.push(33);
	pq1.push(11);
	pq1.push(55);
	pq1.push(22);

	cout << "front of pq1: " << pq1.top() << endl;
	// front of pq1: 55
	cout << "size of qp1: " << pq1.size() << endl;
	// size of qp1: 4
	printPriorityQ(pq1);
	// 55 33 22 11
	cout << endl;

	// ������Сֵ���ȼ�����
	pq3.push(33);
	pq3.push(11);
	pq3.push(55);
	pq3.push(22);

	cout << "front of pq3: " << pq3.top() << endl;
	// front of pq3: 11
	cout << "size of qp3: " << pq3.size() << endl;
	// size of qp1: 4
	//printPriorityQ(pq3); // ���������������
	while (!pq3.empty()) {
		cout << pq3.top() << ' ';
		pq3.pop();
	}
	cout << endl;
	// 11 22 33 55
	cout << endl;
}

int main()
{
	priorityQueueInit();

	return 0;
}