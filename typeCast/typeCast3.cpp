#include <iostream>
#include <cstdio>
using namespace std;

// const char *p��const���Σ���pָ����ڴ�ռ���ֻ������
void printBuf(const char *p)
{
	//p[0] = 'Z'; // ����
	char *p1 = NULL;
	// ����Ա��Ҫ�����֪������ת��֮ǰ��ʲô���ͣ�ת��֮����ʲô����
	// const char * ==> char * ��ֻ������ȥ���� 
	p1 = const_cast<char *>(p);

	p1[0] = 'Z'; // ͨ��p1�޸����ڴ�ռ�
	cout << p << endl;
}

int main()
{
	char buf[] = "aaaaaaaasssssssssdddddddd";

	printBuf(buf);

	// ע�⣬Ҫȷ��p��ָ����ڴ�ռ�ȷʵ���޸ģ���������޸ģ�����������Ժ��
	char *myp = "aaaaaadfdafaf"; // mypָ��һ�鳣���ռ䣬������������ζ����ܱ��޸ĵ�
	//printBuf(myp); // ����ֱ�ӱ���

	return 0;
}