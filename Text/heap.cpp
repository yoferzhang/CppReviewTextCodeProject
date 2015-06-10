#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *geta() // ���󣬲��ܽ�һ��ջ�����ĵ�ַͨ�������ķ���ֵ����
{
	int a = 0;
	return &a;
}

int *geta1() // ����ͨ�������ķ���ֵ����һ���ѵ�ַ�����ǵã�һ��Ҫfree
{
	int *p = (int *)malloc(sizeof(int)); // ������һ���ѿռ�
	return p;
}

int *geta2() // �Ϸ��ģ����Ǽ�ס���ﲻ����free
{
	static int a = 0; // �����ھ�̬�����������й�����һֱ����
	return &a;
}

void getHeap(int *p)
{
	printf("p = %p\n", &p);
	p = (int *)malloc(sizeof(int) * 10);
} // getHeapִ����֮��p����ʧ�ˣ�������ָ��ľ���ѿռ�ĵ�ַ���Ҳ��֮��ʧ��
// ���﷢�����ڴ�й©

void getHeap1(int **p)
{
	*p = (int *)malloc(sizeof(int) * 10);
} // ����Ĳ���������ȷ��

int main1()
{
	int *p = NULL;
	printf("p = %p\n", &p);
	getHeap(p); // ʵ��û���κθı�
	getHeap1(&p); // �õ��˶��ڴ�ĵ�ַ
	printf("p = %d\n", p);

	p[0] = 1;
	p[1] = 2;
	printf("p[0] = %d, p[1] = %d\n", p[0], p[1]);
	free(p);

	return 0;
}

int main()
{
	char *p = (char *)malloc(10); // �����ڴ棬����û�и���ֵ
	memset(p, 0, 10); // ������Ҫ�ֶ���ֵ������ķ�������Ҫ
	char *p1 = (char *)calloc(10, sizeof(char)); // �����ڴ棬���Զ�����Ϊ0

	char *p2 = (char *)realloc(p1, 20); // ��ԭ���ڴ�����ϣ��ڶ��м��������ӵ��ڴ�
	// ���ԭ���ڴ�û�������ռ����չ����ô���·���һ���ռ䣬��ԭ���ڴ�copy���¿ռ䣬Ȼ���ͷ�ԭ���ڴ�
	// realloc��malloc��ֻ�����ڴ棬�����и�ֵ����
	
	char *p3 = (char *)realloc(NULL, 5); // �ȼ���mallco(5)

	free(p);
	free(p1);
	free(p2);
	free(p3);
	return 0;
}
