#include <iostream>
using namespace std;
//����ֵ�ǻ������ͣ�������
int getAA1()
{
	int a;
	a = 10;
	return a;
}

//��������a���ص�ʱ��Ҳ����һ������
int& getAA2()
{
	int a; // �������ջ�ϵ����ã��п��ܻ�������
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
	a2 = getAA2(); // a��10
	int &a3 = getAA2(); // ������ջ���������ܳ�Ϊ�������õĳ�ʼֵ
	cout << a1 << endl;
	cout << a2 << endl;
	cout << a3 << endl; // a3�����룬�������������
	// ����������a3�Ǹ����ã��Զ����ж�a3�ĵ�ַ����ȡֵ
	// ���Ǻ���getAA2�˳���ʱ���Ѿ��ͷ��������ַ���ڴ棬��������������

	return 0;
}

//static���α�����ʱ�򣬱�����һ��״̬����
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
	// j()����������һ����ֵ��û���ڴ��ַ�����ܵ���ֵ
	//11 = 100;
	//*(a>b?&a:&b) = 111;
	//�������õĺ�������ֵ��ʱ�򣬱��뷵��һ������
	j1() = 100; //�����������Ǵ����˻���
	j1();
	*(j2()) = 200; //�൱���ֹ��Ĵ��죬����ֵ������
	j2();
	system("pause");
}
