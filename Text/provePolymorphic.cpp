
#include <iostream>
using namespace std;


class Parent1
{
public:
	Parent1(int a = 0)
	{
		this->a = a;
	}

	void print()
	{
		cout << "父类" << endl;
	}
private:
	int a;
};

class Parent2
{
public:
	Parent2(int a = 0)
	{
		this->a = a;
	}

	virtual void print()
	{
		cout << "虚析构函数的父类" << endl;
	}
private:
	int a;
};

int main()
{
	printf("sizeof(Parent):%d sizeof(Parent2):%d \n", sizeof(Parent1), sizeof(Parent2));
	// 结果是普通类大小为4，而把函数变成虚构函数之后大小为8，所以证明了这里vptr指针的存在性

	return 0;
}
