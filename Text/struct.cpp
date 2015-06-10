#include <stdio.h>



struct A
{
	int a; // 此时结构体占用4个字节
	char b; // 此时结构体占用8个字节
	char c; // 还是8个字节
	char d; // 还是8个字节
	char e; // 还是8个字节
	char f; // 现在是12个字节  
};

struct B
{
	char a; // 1个字节
	char b; // 2个字节
	char c; // 3个字节
};

struct c
{
	char name[10]; // 10个字节
	char a; // 11个字节
	// 对于char型数组来说，会把数组每个元素当作一个char类型
};

struct d
{
	int name[10]; // 40个字节
	char a; // 44个字节
	char b; // 44个字节
};

struct e
{
	char a; // 1个字节
	int b; // 8个字节
	char c; // 12个字节
	// 这种写法内存的消耗相比A就会变大
};

struct f
{
	char a; // 1
	short b; // 4注意这里short占用的是剩下三个字节中的后两个
	// 内存对齐总是以2的倍数对齐
	char c; // 所以此时是6
	int d; // 12
	short e; // 16
	char f; // 16
};

struct name
{
	char array[10];
};

int main()
{
	char name1[10] = "name1";
	char name2[20] = "name2";
	name1 = name2; // 这里是出错的，不能在数组之间进行赋值
	struct name a1 = { "hello" };
	struct name a2 = { 0 };
	a2 = a1; // 这里通过结构体可以赋值的特性变相实现了数组的赋值
	return 0;
}

