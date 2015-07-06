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


void selectSort(int *a, int len)
{
	for (int i = 0; i < len; i++) {
		int k = i; // 记录最小的位置
		for (int j = i + 1; j < len; j++) {
			if (a[j] < a[k]) {
				k = j;
			}
		}
		if (k != i) {
			mySwap(a[i], a[k]);
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
	selectSort(arr, len);
	cout << "After sorting:\n";
	printArray(arr, len);
	
	return 0;
}

/*
Please input length of array: 20
Before sorting:
3  28  35  97  87   7  33  60  84  47
18  71  94  68  54  94  30   8  95  31
After sorting:
3   7   8  18  28  30  31  33  35  47
54  60  68  71  84  87  94  94  95  97
*/