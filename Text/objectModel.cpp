#include <iostream>

using namespace std;

class C1
{
public:
	int i;  //4
	int j; //4
	int k;  //4
protected:
private:
}; // ��СӦ����12

class C2
{
public:
	int i; //4 
	int j; //4
	int k; //4

	static int m; //4
public:
	int getK() const { return k; } //4
	void setK(int val) { k = val; }  //4

protected:
private:
}; //��С������12��������16��������24 

struct S1
{
	int i;
	int j;
	int k;
}; // ��С��12

struct S2
{
	int i;
	int j;
	int k;
	static int m;
}; // ��С������12��������16

int main()
{
	printf("c1:%d \n", sizeof(C1)); // �����12
	printf("c2:%d \n", sizeof(C2)); // �����12
	printf("s1:%d \n", sizeof(S1)); // �����12
	printf("s2:%d \n", sizeof(S2)); // �����12

}
