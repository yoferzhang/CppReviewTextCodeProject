#include <iostream>
using namespace std;
//返回值是基础类型，当引用
int getAA1()
{
	int a;
	a = 10;
	return a;
}

//基础类型a返回的时候，也会有一个副本
int& getAA2()
{
	int a; // 如果返回栈上的引用，有可能会有问题
	a = 10;
	return a;
}

int* getAA3()
{
	int a;
	a = 10;
	return &a;
}

int main()
{
	int a1 = 0;
	int a2 = 0;

	a1 = getAA1();
	a2 = getAA2(); // a是10
	int &a3 = getAA2(); // 若返回栈变量，不能成为其他引用的初始值
	cout << a1 << endl;
	cout << a2 << endl;
	cout << a3 << endl; // a3是乱码，这里出现了问题
	// 编译器看到a3是个引用，自动进行对a3的地址进行取值
	// 但是函数getAA2退出的时候已经释放了这个地址的内存，所以这里是乱码

	return 0;
}

//static修饰变量的时候，变量是一个状态变量
int j()
{
	static int a = 10;
	a++;
	printf("a:%d \n", a);
	return a;

}

int& j1()
{
	static int a = 10;
	a++;
	printf("a:%d \n", a);
	return a;
}

int *j2()
{
	static int a = 10;
	a++;
	printf("a:%d \n", a);
	return &a;
}


void main()
{
	// j()的运算结果是一个数值，没有内存地址，不能当左值
	//11 = 100;
	//*(a>b?&a:&b) = 111;
	//当被调用的函数当左值的时候，必须返回一个引用
	j1() = 100; //编译器帮我们打造了环境
	j1();
	*(j2()) = 200; //相当于手工的打造，做左值的条件
	j2();
	system("pause");
}
