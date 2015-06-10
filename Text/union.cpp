#include <stdio.h>
#include <stdlib.h>

union A
{
	char a;
	char *b; // 联合体的指针成员要特别注意
};

int main()
{
	A a;
	a.b = (char *)malloc(10); // b指向了一个堆的地址
	// 如果联合体中有指针成员，那么一定要使用完这个指针，并且free指针之后才能使用其他成员
	a.a = 10; // b的值也成了10了
	free(b); // 此时释放b是错误的，因为在上面一行对a进行赋值时，已经将b的值更改了，这里造成了内存泄漏
	return 0;
}