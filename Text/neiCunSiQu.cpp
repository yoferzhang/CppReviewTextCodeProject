#include <stdio.h>

int c = 0; // 静态区

void test(int a, int b) // 形参a，b都在栈区
{
	printf("%d, %d\n", &a, &b);
}

int *geta() // 函数的返回值是一个指针
{
	int a = 100; // 栈区
	return &a;
} // int a的作用域就是这个{}

int main()
{
	int *p = geta(); // 这里得到一个临时栈变量的地址，这个地址在函数geta调用完成之后已经无效了
	*p = 100;
	printf("%d\n", *p);
	static int d = 0; // 静态区
	int a = 0; // 栈区
	int b = 0;

	printf("%d, %d, %d, %d, %d\n", &a, &b, &c, &d, main);
	test(a, b);
	return 0;
}

/*
输出结果
100
2619740, 2619728, 9404720, 9404724, 9376059
2619512, 2619516
*/
