#include <iostream>
#include <cstdio>
#include <ctime>
#include <iomanip>
using namespace std;

int arr[10000];

void shellSort(int *a, int len)
{
	int gap = len;
	do {
		gap = gap / 3 + 1; // 业界统一实验的，平均最好情况，经过若干次后，收敛为1
		for (int i = gap; i < len; i += gap) {
			int k = i;
			int tmp = a[k];

			for (int j = i - gap; j >= 0 && a[j] > tmp; j -= gap) {
				a[j + gap] = a[j];
				k = j;
			}
			a[k] = tmp;
		}
	} while (gap > 1);
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
	shellSort(arr, len);
	cout << "After sorting:\n";
	printArray(arr, len);

	return 0;
}

/*
Please input length of array: 20
Before sorting:
15  40  55   7  80  67  17  36  23  96
54  29  85  81  57  77  63  54  28  78
After sorting:
 7  15  17  23  28  29  36  40  54  54
55  57  63  67  77  78  80  81  85  96
*/