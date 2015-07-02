#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

int a[10005];

void init()
{
	for (int i = 0; i <= 10000; i++) {
		a[i] = i;
	}
}

void solve()
{
	for (int i = 2; i <= 10000; i++) {
		while (a[i] == 0) {
			i++;
		}
		for (int k = 2, j = k * i; j <= 10000; j = (++k) * i) {
			a[j] = 0;
		}
	}
}

void printAns()
{
	int line = 0;
	for (int i = 2; i < 10000; i++) {
		while (a[i] == 0) {
			i++;
		}
		if (i >= 10000) {
			break;
		}
		if (line != 0 && line % 10 == 0) {
			cout << endl;
		}
		cout << setw(5) << i;
		line++;
	}
	cout << "\n10000以内的质数个数为：" << line << endl;
}


int main()
{
	init();
	solve();
	printAns();

	return 0;
}