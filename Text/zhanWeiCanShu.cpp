#include <iostream>
//当函数默认参数遇上函数重载会发生什么
int func(int a, int b, int c = 0)
{
	return a * b * c;
}

int func(int a, int b)
{
	return a + b;
}

//1个参数的允许
int func(int a)
{
	return a + b;
}


int main()
{
	int c = 0;

	c = func(1, 2); // 存在二义性，调用失败，编译不能通过

	printf("c = %d\n", c);

	printf("Press enter to continue ...");
	getchar();
	return 0;
}

