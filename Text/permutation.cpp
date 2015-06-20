#include <iostream>
using namespace std;

int P[100], A[100];

// �������p��Ԫ�ص�ȫ���С�����p�п������ظ�Ԫ��
void printPermutation(int n, int* A, int cur)
{
	if (cur == n) { // �ݹ�߽�
		for (int i = 0; i < n; i++) {
			printf("%d ", A[i]);
		}
		printf("\n");
	}
	else {
		for (int i = 1; i <= n; i++) { // ������A[cur]�����������i
			int ok = 1;
			for (int j = 0; j < cur; j++) {
				if (A[j] == i) {
					ok = 0; // ���i�Ѿ���A[0]~A[cur-1]���ֹ���������ѡ
				}
			}
			if (ok) {
				A[cur] = i;
				printPermutation(n, A, cur + 1); // �ݹ����
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