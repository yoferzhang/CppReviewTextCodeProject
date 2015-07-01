#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	tot = 0;
	best = A[i];
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) { // �������������A[i]~A[j]
			int sum = 0;
			for (int k = i; k <= j; k++) {
				sum += A[k];
				tot++;
			}
			if (sum > best) {
				best = sum; // �������ֵ
			}
		}
	}

	S[0] = 0;
	for (int i = 1; i <= n; i++) {
		S[i] = s[i - 1] + A[i]; // ����ǰ׺��S
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			best = max(best, S[j] - S[i - 1]); // �������ֵ
		}
	}

	
	return 0;
}

int maxSubSum(int* A, int x, int y) // ��������������ҿ�����[x,y)�е����������
{
	if (y - x == 1) {
		return A[x]; // ֻ��һ��Ԫ�أ�ֱ�ӷ���
	}
	int m = x + (y - x) / 2; // ���ε�һ�������ֳ�[x,m)��[m,y)
	int maxs = max(maxSubSum(A, x, m), maxSubSum(A, m, y)); // ���εڶ������ݹ����
	int v, L, R;
	v = 0; L = A[m - 1]; // ���ε��������ϲ�(1)���ӷֽ�㿪ʼ��������������L
	for (int i = m - 1; i >= x; i--) {
		L = max(L, v += A[i]);
	}
	v = 0; R = A[m]; // ���ε��������ϲ�(2),�ӷֽ�㿪ʼ���ҵ����������R
	for (int i = m; i < y; i++) {
		R = max(R, v += A[i]);
	}
	return max(maxs, L + R); // ��������Ľ���L��R�Ƚ�
}

int maxSubsequenceSum(const int A[], int N)
{
	int thisSum, maxSum, j;

	thisSum = maxSum = 0;
	for (int j = 0; j < N; j++) {
		thisSum += A[j];
		if (thisSum > maxSum) {
			maxSum = thisSum;
		}
		else if (thisSum < 0) {
			thisSum = 0;
		}
	}
	return maxSum;
}