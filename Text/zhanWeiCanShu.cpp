#include <iostream>
//������Ĭ�ϲ������Ϻ������ػᷢ��ʲô
int func(int a, int b, int c = 0)
{
	return a * b * c;
}

int func(int a, int b)
{
	return a + b;
}

//1������������
int func(int a)
{
	return a + b;
}


int main()
{
	int c = 0;

	c = func(1, 2); // ���ڶ����ԣ�����ʧ�ܣ����벻��ͨ��

	printf("c = %d\n", c);

	printf("Press enter to continue ...");
	getchar();
	return 0;
}

