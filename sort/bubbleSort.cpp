#include <iostream>
#include <cstdio>
#include <ctime>
#include <iomanip>
using namespace std;

int arr[10000];

void mySwap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}


void bubbleSort(int *a, int len)
{
	bool alreadySort = false; // 记录如果已经排序完成，可以提前退出
	for (int i = len - 1; i >= 0 && !alreadySort; i--) { // 从后往前排序
		alreadySort = true;
		for (int j = 0; j < i; j++) {
			if (a[j] > a[j + 1]) {
				mySwap(a[j], a[j + 1]);
				alreadySort = false;
			}
		}
	}
}

void printArray(int *a, int len)
{
	for (int i = 0; i < len; i++) {
		if (i != 0 && i % 10 == 0) {
			cout << endl;
		}
		cout << setw(3) << a[i] << ' ';
	}
	cout << endl;
}

int main()
{
	srand(time(0));
	cout << "Please input length of array: ";
	int len;
	cin >> len;
	for (int i = 0; i < len; i++) {
		arr[i] = rand() % 100;
	}
	cout << "Before sorting:\n";
	printArray(arr, len);
	bubbleSort(arr, len);
	cout << "After sorting:\n";
	printArray(arr, len);

	return 0;
}

/*
Please input length of array: 20
Before sorting:
70  53  65  69  99  67  36  49  66  16
58  73  65  20  75  30  93   8  42  57
After sorting:
8  16  20  30  36  42  49  53  57  58
65  65  66  67  69  70  73  75  93  99
*/