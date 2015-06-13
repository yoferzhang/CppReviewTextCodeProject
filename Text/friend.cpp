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

	//��ӡ����
	void printCom()
	{
		cout << a << " + " << b << "i" << endl;
	}

	// ʵ�� + ���������
	Complex operator+(Complex &c2)
	{
		Complex tmp(this->a + c2.a, this->b + c2.b);
		return tmp;
	}

	// ʵ�� - ���������
	Complex operator-(Complex &c2)
	{
		Complex tmp(this->a - c2.a, this->b - c2.b);
		return tmp;
	}

	// ʵ�� ǰ��++ ���������
	Complex& operator++()
	{
		a++;
		b++;
		return *this;
	}

	// ʵ�� ����++ ���������
	// �����漰����ռλ������ʹ�ã���Ϊ��������ռλ����
	// ����++�����غ�����ǰ��++�Ĳ�������ͬ�ˣ��������ؾͳ������﷨����
	Complex& operator++(int) 
	{
		Complex tmp = *this;
		this->a++;
		this->b++;
		return tmp;
	}

	// ʵ�� ǰ��-- ���������
	Complex& operator--()
	{
		a--;
		b--;
		return *this;
	}

	// ʵ�� ����-- ���������
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

// ��Ԫ��������ʵ�� << ����������
ostream& operator<<(ostream& out, Complex &c1)
{
	out << c1.a << "+" << c1.b << "i" << endl;
	return out;
}

// ��Ԫ��������ʵ�� >> ����������
istream& operator>>(istream& in, Complex &c1)
{
	in >> c1.a >> c1.b;
	return in;
}

int main()
{
	
	return 0;
}