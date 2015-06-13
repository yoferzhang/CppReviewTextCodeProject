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
}; // 大小应该是12

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
}; //大小可能是12，可能是16，可能是24 

struct S1
{
	int i;
	int j;
	int k;
}; // 大小是12

struct S2
{
	int i;
	int j;
	int k;
	static int m;
}; // 大小可能是12，可能是16

int main()
{
	printf("c1:%d \n", sizeof(C1)); // 结果是12
	printf("c2:%d \n", sizeof(C2)); // 结果是12
	printf("s1:%d \n", sizeof(S1)); // 结果是12
	printf("s2:%d \n", sizeof(S2)); // 结果是12

}
