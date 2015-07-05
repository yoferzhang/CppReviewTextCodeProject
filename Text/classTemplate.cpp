#include <iostream>
#include <cstdio>
using namespace std;

// 模板类
template <typename T>
class A
{
public:
	A(T a = 0) {
		this->a = a;
	}
	
	void printA()
	{
		cout << "a: " << a << endl;
	}
protected:
	T a;
};

// 从模板类派生的普通类
// 模板类派生时，需要具体化模板类，C++编译器需要知道，父类的数据类型是什么样子的
// 要知道父类所占的内存大小是多少，只有数据类型固定下来，才知道如何分配内存
class B : public A<int>
{
public:
	B(int a = 10, int b = 20) : A<int>(a)
	{
		this->b = b;
	}

	void printB()
	{
		cout << "a: " << a << "\nb: " << b << endl;
	}

private:
	int b;
};

// 从模板类派生模板类
template <typename T>
class C : public A < T >
{
public:
	C(T c, T a) : A<T>(a)
	{
		this->c = c;
	}
	void printC()
	{
		cout << "a: " << a << "\nc: " << c << endl;
	}
private:
	T c;
};

int main()
{
	C<int> c1(10, 20);
	c1.printC();
	return 0;
}


int main02()
{
	B b1(1, 2);
	b1.printB();
	return 0;
}


// C++编译器要求具体的类，所以要写成A<int> &a，千万别忘了<int>
void useA(A<int> &a)
{
	a.printA();
}




int main01()
{
	// 模板类（本身就是类型化的）=>具体的类=>定义具体的变量
	A<int> a1(11), a2(20), a3(30); // 模版是抽象的 => 需要给出具体类型
	//a1.printA();


	return 0;
}