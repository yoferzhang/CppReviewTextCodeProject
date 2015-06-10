#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *geta() // 错误，不能将一个栈变量的地址通过函数的返回值返回
{
	int a = 0;
	return &a;
}

int *geta1() // 可以通过函数的返回值返回一个堆地址，但记得，一定要free
{
	int *p = (int *)malloc(sizeof(int)); // 申请了一个堆空间
	return p;
}

int *geta2() // 合法的，但是记住这里不能用free
{
	static int a = 0; // 变量在静态区，程序运行过程中一直存在
	return &a;
}

void getHeap(int *p)
{
	printf("p = %p\n", &p);
	p = (int *)malloc(sizeof(int) * 10);
} // getHeap执行完之后，p就消失了，导致他指向的具体堆空间的地址编号也随之消失了
// 这里发生了内存泄漏

void getHeap1(int **p)
{
	*p = (int *)malloc(sizeof(int) * 10);
} // 这里的操作就是正确的

int main1()
{
	int *p = NULL;
	printf("p = %p\n", &p);
	getHeap(p); // 实参没有任何改变
	getHeap1(&p); // 得到了堆内存的地址
	printf("p = %d\n", p);

	p[0] = 1;
	p[1] = 2;
	printf("p[0] = %d, p[1] = %d\n", p[0], p[1]);
	free(p);

	return 0;
}

int main()
{
	char *p = (char *)malloc(10); // 分配内存，但是没有赋初值
	memset(p, 0, 10); // 这里需要手动赋值，下面的方法则不需要
	char *p1 = (char *)calloc(10, sizeof(char)); // 分配内存，并自动设置为0

	char *p2 = (char *)realloc(p1, 20); // 在原有内存基础上，在堆中间连续增加的内存
	// 如果原有内存没有连续空间可拓展，那么会新分配一个空间，将原有内存copy到新空间，然后释放原有内存
	// realloc和malloc，只分配内存，不进行赋值操作
	
	char *p3 = (char *)realloc(NULL, 5); // 等价于mallco(5)

	free(p);
	free(p1);
	free(p2);
	free(p3);
	return 0;
}
