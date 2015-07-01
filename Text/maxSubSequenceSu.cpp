#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	tot = 0;
	best = A[i];
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) { // 检查连续子序列A[i]~A[j]
			int sum = 0;
			for (int k = i; k <= j; k++) {
				sum += A[k];
				tot++;
			}
			if (sum > best) {
				best = sum; // 更新最大值
			}
		}
	}

	S[0] = 0;
	for (int i = 1; i <= n; i++) {
		S[i] = s[i - 1] + A[i]; // 递推前缀和S
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			best = max(best, S[j] - S[i - 1]); // 更新最大值
		}
	}

	
	return 0;
}

int maxSubSum(int* A, int x, int y) // 返回数组在左闭右开区间[x,y)中的最大连续和
{
	if (y - x == 1) {
		return A[x]; // 只有一个元素，直接返回
	}
	int m = x + (y - x) / 2; // 分治第一步：划分成[x,m)和[m,y)
	int maxs = max(maxSubSum(A, x, m), maxSubSum(A, m, y)); // 分治第二步：递归求解
	int v, L, R;
	v = 0; L = A[m - 1]; // 分治第三步：合并(1)，从分界点开始往左的最大连续和L
	for (int i = m - 1; i >= x; i--) {
		L = max(L, v += A[i]);
	}
	v = 0; R = A[m]; // 分治第三步：合并(2),从分界点开始往右的最大连续和R
	for (int i = m; i < y; i++) {
		R = max(R, v += A[i]);
	}
	return max(maxs, L + R); // 把子问题的解与L和R比较
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