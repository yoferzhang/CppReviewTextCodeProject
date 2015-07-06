#include <iostream>
#include <cstdio>
#include <ctime>
#include <iomanip>
using namespace std;

int arr[10000];

inline void mySwap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}

void merge(int A[], int tmpA[], int leftPos, int rightPos, int rightEnd)
{
	int leftEnd = rightPos - 1;
	int tmpPos = leftPos;
	int num = rightEnd - leftPos + 1;

	// 从大到小放到临时矩阵中
	while (leftPos <= leftEnd && rightPos <= rightEnd) {
		if (A[leftPos] <= A[rightPos]) {
			tmpA[tmpPos++] = A[leftPos++];
		}
		else {
			tmpA[tmpPos++] = A[rightPos++];
		}
	}

	// 剩下的
	while (leftPos <= leftEnd) {
		tmpA[tmpPos++] = A[leftPos++];
	}
	while (rightPos <= rightEnd) {
		tmpA[tmpPos++] = A[rightPos++];
	}

	for (int i = 0; i < num; i++, rightEnd--) {
		A[rightEnd] = tmpA[rightEnd];
	}
}

void MSort(int A[], int tmpA[], int L, int R)
{
	int mid;
	if (L < R) {
		mid = (L + R) / 2;
		MSort(A, tmpA, L, mid);
		MSort(A, tmpA, mid + 1, R);
		merge(A, tmpA, L, mid + 1, R);
	}
}


void mergeSort(int A[], int len)
{
	int *tmpA = new int[len];
	if (tmpA != NULL) {
		MSort(A, tmpA, 0, len - 1);
		delete [] tmpA;
	}
	else {
		cout << "No space for tmp array!!!\n";
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
	mergeSort(arr, len);
	cout << "After sorting:\n";
	printArray(arr, len);

	return 0;
}

/*
Please input length of array: 20
Before sorting:
55  89  51  31  24  86  41  82  83  58
36  41  84  88  99   1  38  96  31  27
After sorting:
 1  24  27  31  31  36  38  41  41  51
55  58  82  83  84  86  88  89  96  99
*/