#include <iostream>
using namespace std;

class Complex
{
public:
	Complex(int a = 0, int b = 0)
	{
		this->a = a;
		this->b = b;
	}
	~Complex();

	//打印复数
	void printCom()
	{
		cout << a << " + " << b << "i" << endl;
	}

	// 实现 + 运算符重载
	Complex operator+(Complex &c2)
	{
		Complex tmp(this->a + c2.a, this->b + c2.b);
		return tmp;
	}

	// 实现 - 运算符重载
	Complex operator-(Complex &c2)
	{
		Complex tmp(this->a - c2.a, this->b - c2.b);
		return tmp;
	}

	// 实现 前置++ 运算符重载
	Complex& operator++()
	{
		a++;
		b++;
		return *this;
	}

	// 实现 后置++ 运算符重载
	// 这里涉及到了占位参数的使用，因为不过不用占位参数
	// 后置++的重载函数和前置++的参数就相同了，这样重载就出现了语法错误
	Complex& operator++(int) 
	{
		Complex tmp = *this;
		this->a++;
		this->b++;
		return tmp;
	}

	// 实现 前置-- 运算符重载
	Complex& operator--()
	{
		a--;
		b--;
		return *this;
	}

	// 实现 后置-- 运算符重载
	Complex& operator--(int)
	{
		Complex tmp = *this;
		this->a--;
		this->b--;
		return tmp;
	}
	friend ostream& operator<<(ostream& out, Complex &c1);
	friend istream& operator>>(istream& in, Complex &c1);

private:
	int a;
	int b;
};

// 友元函数方法实现 << 操作符重载
ostream& operator<<(ostream& out, Complex &c1)
{
	out << c1.a << "+" << c1.b << "i" << endl;
	return out;
}

// 友元函数方法实现 >> 操作符重载
istream& operator>>(istream& in, Complex &c1)
{
	in >> c1.a >> c1.b;
	return in;
}

int main()
{
	
	return 0;
}