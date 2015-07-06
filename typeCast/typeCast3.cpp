#include <iostream>
#include <cstdio>
using namespace std;

// const char *p的const修饰，让p指向的内存空间变成只读属性
void printBuf(const char *p)
{
	//p[0] = 'Z'; // 报错
	char *p1 = NULL;
	// 程序员需要清楚的知道变量转换之前是什么类型，转换之后是什么类型
	// const char * ==> char * 把只读属性去掉了 
	p1 = const_cast<char *>(p);

	p1[0] = 'Z'; // 通过p1修改了内存空间
	cout << p << endl;
}

int main()
{
	char buf[] = "aaaaaaaasssssssssdddddddd";

	printBuf(buf);

	// 注意，要确保p所指向的内存空间确实能修改，如果不能修改，会带来灾难性后果
	char *myp = "aaaaaadfdafaf"; // myp指向一块常量空间，这里是无论如何都不能被修改的
	//printBuf(myp); // 运行直接奔溃

	return 0;
}