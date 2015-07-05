#include <iostream>
#include <cstdio>
using namespace std;

// ģ����
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

// ��ģ������������ͨ��
// ģ��������ʱ����Ҫ���廯ģ���࣬C++��������Ҫ֪�������������������ʲô���ӵ�
// Ҫ֪��������ռ���ڴ��С�Ƕ��٣�ֻ���������͹̶���������֪����η����ڴ�
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

// ��ģ��������ģ����
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


// C++������Ҫ�������࣬����Ҫд��A<int> &a��ǧ�������<int>
void useA(A<int> &a)
{
	a.printA();
}




int main01()
{
	// ģ���ࣨ����������ͻ��ģ�=>�������=>�������ı���
	A<int> a1(11), a2(20), a3(30); // ģ���ǳ���� => ��Ҫ������������
	//a1.printA();


	return 0;
}