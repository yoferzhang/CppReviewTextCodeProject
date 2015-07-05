#include <iostream>
#include <cstdio>
using namespace std;

template <typename T>
class Complex
{
	friend Complex& mySub(Complex &c1, Complex &c2) // д������ûʲô����
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

// ��������ص�����д��
// ���� << >> ֻ������Ԫ������������������ض�Ҫд�ɳ�Ա��������Ҫ������Ԫ����

/* �ⲿ�ֶ������д������ڲ�
ostream &operator << (ostream &out, Complex &c2)
{
	out << c2.a << " + " << c2.b << "i\n";
	return out;
}
*/

int main()
{
	// ��Ҫ��ģ������廯֮����ܶ������C++��������Ҫ�����ڴ�
	Complex<int> c1(1, 2);
	c1.printCom();
	Complex<int> c2(3, 4);
	c2.printCom(); 
	Complex<int> c3 = c1 + c2;
	c3.printCom();
	cout << c3 << endl;

	// ������Ԫ����
	{
		Complex<int> c3 = mySub(c1, c2);
		cout << c3;
	
	}

	
	return 0;
}