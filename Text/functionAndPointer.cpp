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

// ����ָ��

// ����һ���������
// void myfunc(int a, int b)
typedef void(myTypeFunc)(int a, int b);

// ����һ������ָ������
typedef void(*myTypeFunc0)(int a, int b); // ������һ��ָ�����������

// ����һ������ָ�����
void(*myVarPFunc)(int a, int b); 

int main()
{
	myTypeFunc *myfuncp = NULL; // ����һ������ָ�룬���ָ��ָ��������ڵ�ַ
	// ����ֻ�ܶ��庯��ָ�룬���ܰѡ�*��ȥ��������

	myTypeFunc0 funcp = NULL; // ͨ������ָ�����Ͷ�����һ������ָ��
	funcp = myfunc;
	myfunc(1);

	{
		char buf1[] = "aadaf";
		char buf2[] = "bbb";
		myfunc(buf1, buf2);
	}
	return 0;
}