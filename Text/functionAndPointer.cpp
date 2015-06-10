#include <iostream>
using namespace std;

void myfunc(int a)
{
	printf("a:%d \n", a);
}

void myfunc(char *p)
{
	printf("%s \n", p);
}

void myfunc(int a, int b)
{
	printf("a:%d \n", a);
}

void myfunc(char *p1, char *p2)
{
	printf("p1:%s \n", p1);
	printf("p2:%s \n", p2);
}

// 函数指针

// 声明一个函数类别
// void myfunc(int a, int b)
typedef void(myTypeFunc)(int a, int b);

// 声明一个函数指针类型
typedef void(*myTypeFunc0)(int a, int b); // 声明了一个指针的数据类型

// 定义一个函数指针变量
void(*myVarPFunc)(int a, int b); 

int main()
{
	myTypeFunc *myfuncp = NULL; // 定义一个函数指针，这个指针指向函数的入口地址
	// 并且只能定义函数指针，不能把“*”去掉！！！

	myTypeFunc0 funcp = NULL; // 通过函数指针类型定义了一个函数指针
	funcp = myfunc;
	myfunc(1);

	{
		char buf1[] = "aadaf";
		char buf2[] = "bbb";
		myfunc(buf1, buf2);
	}
	return 0;
}