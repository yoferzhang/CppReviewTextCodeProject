#include <stdio.h>



struct A
{
	int a; // ��ʱ�ṹ��ռ��4���ֽ�
	char b; // ��ʱ�ṹ��ռ��8���ֽ�
	char c; // ����8���ֽ�
	char d; // ����8���ֽ�
	char e; // ����8���ֽ�
	char f; // ������12���ֽ�  
};

struct B
{
	char a; // 1���ֽ�
	char b; // 2���ֽ�
	char c; // 3���ֽ�
};

struct c
{
	char name[10]; // 10���ֽ�
	char a; // 11���ֽ�
	// ����char��������˵���������ÿ��Ԫ�ص���һ��char����
};

struct d
{
	int name[10]; // 40���ֽ�
	char a; // 44���ֽ�
	char b; // 44���ֽ�
};

struct e
{
	char a; // 1���ֽ�
	int b; // 8���ֽ�
	char c; // 12���ֽ�
	// ����д���ڴ���������A�ͻ���
};

struct f
{
	char a; // 1
	short b; // 4ע������shortռ�õ���ʣ�������ֽ��еĺ�����
	// �ڴ����������2�ı�������
	char c; // ���Դ�ʱ��6
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
	name1 = name2; // �����ǳ���ģ�����������֮����и�ֵ
	struct name a1 = { "hello" };
	struct name a2 = { 0 };
	a2 = a1; // ����ͨ���ṹ����Ը�ֵ�����Ա���ʵ��������ĸ�ֵ
	return 0;
}

