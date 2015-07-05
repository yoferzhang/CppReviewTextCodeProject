#include <iostream>
#include <cstdio>
using namespace std;

template <typename T>
class Complex
{
	friend Complex& mySub(Complex &c1, Complex &c2) // 写在里面没什么问题
	{
		Complex tmp(c1.a - c2.a, c1.b - c2.b);
		return tmp;
	}

	friend ostream &operator << (ostream &out, Complex &c2)
	{
		out << c2.a << " + " << c2.b << "i\n";
		return out;
	}

public:
	Complex(T a, T b) : a(a), b(b) {}

	Complex operator + (Complex &c2)
	{
		Complex tem(a + c2.a, b + c2.b);
		return tem;
	}

	void printCom()
	{
		cout << a << " + " << b << "i\n";
	}
private:
	T a;
	T b;
};

// 运算符重载的正规写法
// 重载 << >> 只能用友元函数，其他运算符重载都要写成成员函数，不要滥用友元函数

/* 这部分定义必须写进类的内部
ostream &operator << (ostream &out, Complex &c2)
{
	out << c2.a << " + " << c2.b << "i\n";
	return out;
}
*/

int main()
{
	// 需要把模板类具体化之后才能定义对象，C++编译器需要分配内存
	Complex<int> c1(1, 2);
	c1.printCom();
	Complex<int> c2(3, 4);
	c2.printCom(); 
	Complex<int> c3 = c1 + c2;
	c3.printCom();
	cout << c3 << endl;

	// 滥用友元函数
	{
		Complex<int> c3 = mySub(c1, c2);
		cout << c3;
	
	}

	
	return 0;
}