#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	double pi = 3.1415926;
	int num1 = (int)pi; // C类型转换
	int num2 = static_cast<int>(pi); // 静态类型转换，编译的时候C++编译器会做类型检查
	int num3 = pi; // C语言中隐式类型转换的地方，均可使用static_cast<>()进行类型转换

	char *p1 = "hello";
	int *p2 = NULL;
	//p2 = static_cast<int *>(pi); // 使用static_cast，编译时编译器会报错
	// 会做类型检查，若有错误，提示错误

	p2 = reinterpret_cast<int *>(p1); // 若不同类型之间，进行强制类型转换，用reinterpret_cast<>()进行重新解释

	cout << "p1: " << p1 << endl; // %s
	cout << "p2: " << p2 << endl; // %d
	/*
	p1: hello
	p2: 0127CA54
	*/

	return 0;
}