#include <iostream>
using namespace std;

int main()
{
	int a = 10;
	// 单独定义的引用时，必须初始化；说明很像一个常量
	int &b = a;
	// b是a的别名
	b = 11;
	cout << "b--->" << a << endl;
	printf("a:%d\n", a);
	printf("b:%d\n", b); 
	printf("&a:%d\n", &a);
	printf("&b:%d\n", &b);
	system("pause");
	return 0;
}

struct Teacer {
	int &a;
	int &b;
};
int main()
{
	printf("sizeof(Teacher) %d\n", sizeof(Teacer));
	system("pause");
	return 0;
}
