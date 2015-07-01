#include <iostream>
#include <cstdio>
using namespace std;

int n, tot;
int C[8];
int vis[3][15];
/*
void search(int cur)
{
	if (cur == n) { // �ݹ�߽硣ֻҪ�ߵ�������лʺ��Ȼ����ͻ
		tot++;
	}
	else for (int i = 0; i < n; i++) {
		bool ok = true;
		C[cur] = i; // ���԰ѵ�cur�еĻʺ���ڵ�i��
		for (int j = 0; j < cur; j++) { // ����Ƿ��ǰ����Ļʺ��ͻ
			if (C[cur] == C[j] ||
				cur - C[cur] == j - C[j] || // ���Խ����ж�
				cur + C[cur] == j + C[j]) { // ���Խ����ж�
				ok = false;
				break;
			}
		}
		if (ok) {
			search(cur + 1);
		}
	}
}
*/

void search(int cur)
{
	if (cur == n) {
		tot++;
	}
	else for (int i = 0; i < n; i++) {
		if (!vis[0][i] && !vis[1][cur + i] && !vis[2][cur - i + n]) {
			C[cur] = i;
			vis[0][i] = vis[1][cur + i] = vis[2][cur - i + n] = 1; // �޸�ȫ�ֱ���
			search(cur + 1);
			vis[0][i] = vis[1][cur + i] = vis[2][cur - i + n] = 0; // �ǵøĻ���
		}
	}
}

int main()
{
	cin >> n;
	tot = 0;
	memset(vis, 0, sizeof(vis));
	search(0);
	cout << tot << endl;
	return 0;
}