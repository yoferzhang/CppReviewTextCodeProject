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
	for (int i = len - 1; i >= 0 && !alreadySort;) { // 从后往前排序
		alreadySort = true;
		int lastExchange = i; // 记住最后一次交换的位置，可以减少排序趟数
		for (int j = 0; j < i; j++) {
			if (a[j] > a[j + 1]) {
				mySwap(a[j], a[j + 1]);
				alreadySort = false;
				lastExchange = j;
			}
		}
		i = (lastExchange < i ? lastExchange : i - 1);
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
91  48  18  78  96   7  29   4  57  71
78  55   3  69  64  57  17  36  12  21
After sorting:
3   4   7  12  17  18  21  29  36  48
55  57  57  64  69  71  78  78  91  96
*/