#include <stdio.h>

int c = 0; // ��̬��

void test(int a, int b) // �β�a��b����ջ��
{
	printf("%d, %d\n", &a, &b);
}

int *geta() // �����ķ���ֵ��һ��ָ��
{
	int a = 100; // ջ��
	return &a;
} // int a��������������{}

int main()
{
	int *p = geta(); // ����õ�һ����ʱջ�����ĵ�ַ�������ַ�ں���geta�������֮���Ѿ���Ч��
	*p = 100;
	printf("%d\n", *p);
	static int d = 0; // ��̬��
	int a = 0; // ջ��
	int b = 0;

	printf("%d, %d, %d, %d, %d\n", &a, &b, &c, &d, main);
	test(a, b);
	return 0;
}

/*
������
100
2619740, 2619728, 9404720, 9404724, 9376059
2619512, 2619516
*/
