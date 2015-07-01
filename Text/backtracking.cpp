#include <iostream>
#include <cstdio>
using namespace std;

int n, tot;
int C[8];
int vis[3][15];
/*
void search(int cur)
{
	if (cur == n) { // 递归边界。只要走到这里，所有皇后必然不冲突
		tot++;
	}
	else for (int i = 0; i < n; i++) {
		bool ok = true;
		C[cur] = i; // 尝试把第cur行的皇后放在第i列
		for (int j = 0; j < cur; j++) { // 检查是否和前面你的皇后冲突
			if (C[cur] == C[j] ||
				cur - C[cur] == j - C[j] || // 主对角线判定
				cur + C[cur] == j + C[j]) { // 副对角线判定
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
			vis[0][i] = vis[1][cur + i] = vis[2][cur - i + n] = 1; // 修改全局变量
			search(cur + 1);
			vis[0][i] = vis[1][cur + i] = vis[2][cur - i + n] = 0; // 记得改回来
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