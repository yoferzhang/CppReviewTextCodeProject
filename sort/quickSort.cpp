#include <iostream>
#include <cstdio>
#include <ctime>
#include <iomanip>
using namespace std;

const int cutoff = 3;
int arr[10000];

void mySwap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}

void insertSrot(int *a, int len)
{
	for (int i = 1; i < len; i++) {
		int tmp = a[i];
		int j;
		for (j = i; j > 0 && a[j - 1] > tmp; j--) {
			a[j] = a[j - 1]; // 元素后移
		}
		a[j] = tmp; // 元素插入
	}
}

// 实现三数中值分割法
int median3(int *a, int low, int high)
{
	int center = (low + high) / 2;
	
	if (a[low] > a[center]) {
		mySwap(a[low], a[center]);
	}
	if (a[low] > a[high]) {
		mySwap(a[low], a[high]);
	}
	if (a[center] > a[high]) {
		mySwap(a[center], a[high]);
	}

	mySwap(a[center], a[high - 1]);
	return high - 1;
}

void QSort(int *a, int low, int high)
{
	if (low + cutoff <= high) {
		int pivot = median3(a, low, high);

		// Begin partitioning
		int i = low, j = high - 1;
		while (1) {
			while (a[++i] < a[pivot]);
			while (a[--j] > a[pivot]);
			if (i < j) {
				mySwap(a[i], a[j]);
			}
			else {
				break;
			}
		}

		mySwap(a[i], a[high - 1]);

		QSort(a, low, i - 1);
		QSort(a, i + 1, high);
	}
	else {
		insertSrot(a + low, high - low + 1);
	}
}

void quickSort(int *a, int len)
{
	QSort(a, 0, len - 1);
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
	quickSort(arr, len);
	cout << "After sorting:\n";
	printArray(arr, len);

	return 0;
}

/*
Please input length of array: 20
Before sorting:
71  77  25  92  52  37  85   5  29  81
93  32  77  35  43  37  93  72  14  42
After sorting:
 5  14  25  29  32  35  37  37  42  43
52  71  72  77  77  81  85  92  93  93
*/