#include <iostream>
using namespace std;

int P[100], A[100];

// 输出数组p中元素的全排列。数组p中可能有重复元素
void printPermutation(int n, int* A, int cur)
{
	if (cur == n) { // 递归边界
		for (int i = 0; i < n; i++) {
			printf("%d ", A[i]);
		}
		printf("\n");
	}
	else {
		for (int i = 1; i <= n; i++) { // 尝试在A[cur]中填各种整数i
			int ok = 1;
			for (int j = 0; j < cur; j++) {
				if (A[j] == i) {
					ok = 0; // 如果i已经在A[0]~A[cur-1]出现过，则不能再选
				}
			}
			if (ok) {
				A[cur] = i;
				printPermutation(n, A, cur + 1); // 递归调用
			}
		}
	}
}

int main()
{
	int A[20];
	printPermutation(5, A, 0);
	return 0;
}