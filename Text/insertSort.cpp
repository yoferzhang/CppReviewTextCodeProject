#include <iostream>
#include <cstdio>
#include <ctime>
#include <iomanip>
using namespace std;

int arr[10000];

void insertSrot(int *a, int len)
{
	for (int i = 1; i < len; i++) {
		int k = i; // 待插入位置
		int tmp = arr[k];

		for (int j = i - 1; j >= 0 && arr[j] > tmp; j--) {
			arr[j + 1] = arr[j]; // 元素后移
			k = j;
		}
		arr[k] = tmp; // 元素插入
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
	insertSrot(arr, len);
	cout << "After sorting:\n";
	printArray(arr, len);

	return 0;
}

/*
Please input length of array: 20
Before sorting:
41   5  45  17  35  58  29  61  98  89
27   8  97  83  89   3  25  59  12  44
After sorting:
3   5   8  12  17  25  27  29  35  41
44  45  58  59  61  83  89  89  97  98
*/