#include <iostream>
#include <cstdio>
using namespace std;

template <typename T>
class Complex; // ���mySub��Ԫ����������

template <typename T>
Complex<T> mySub(Complex<T> &c1, Complex<T> &c2); // ���mySub��Ԫ����������

template <typename T>
class Complex
{
	// �����Ԫ����������
	friend Complex<T> mySub<T>(Complex<T> &c1, Complex<T> &c2); // д������ûʲô����


	// ����55�лᱨ��
	//friend ostream &operator << (ostream &out, Complex &c2);

	// �������
	friend ostream &operator << <T> (ostream &out, Complex &c2);

public:
	Complex(T a, T b);
	Complex operator + (Complex &c2);
	void printCom();

private:
	T a;
	T b;
};

// ���캯���õ�д������ⲿ
template <typename T>
Complex<T>::Complex(T a, T b)
{
	this->a = a;
	this->b = b;
}

template <typename T>
void Complex<T>::printCom()
{
	cout << a << " + " << b << "i\n";
}

// ע�⺯�������ͺ�������ֵ����Ҫ�������;��廯
template <typename T>
Complex<T> Complex<T>::operator + (Complex<T> &c2)
{
	Complex tem(a + c2.a, b + c2.b);
	return tem;
}

// ����ı��ʣ�ģ�������α������еģ���һ�����ɵĺ���ͷ�͵ڶ������ɵĺ���ͷ��һ��
// ��Ԫ����ʵ�� << ���������
template <typename T>
ostream &operator << (ostream &out, Complex<T> &c2)
{
	out << c2.a << " + " << c2.b << "i\n";
	return out;
}
// ����
/*
1>templateComplex2.obj : error LNK2019: �޷��������ⲿ���� 
"class std::basic_ostream<char,struct std::char_traits<char> > 
& __cdecl operator<<(class std::basic_ostream<char,struct std::char_traits<char> >
&,class Complex<int> &)" (??6@YAAAV?$basic_ostream@DU?$char_traits@D@std@@@std@@AAV01@AAV?$Complex@H@@@Z)��
�÷����ں��� _main �б�����
*/

//////////////////////////////////////////////////////
// ������Ԫ����
template <typename T>
Complex<T> mySub(Complex<T> &c1, Complex<T> &c2)
{
	Complex<T> tmp(c1.a - c2.a, c1.b - c2.b);
	return tmp;
}
// ��������������

// �����������ǰ������


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

//���캯�� û������
//��ͨ���� û������
//��Ԫ����������Ԫ�������� << >>
//	friend ostream& operator<< <T> (ostream &out, Complex<T> &c3) ;
//��Ԫ��������Ԫ��������ʵ�ֺ������أ��� << >>��
//1����Ҫ����ǰ���� ���ǰ������ ������ǰ������ 
template<typename T>
class Complex;
template<typename T>
Complex<T> mySub(Complex<T> &c1, Complex<T> &c2);

//2������ڲ����� ����д��: 
friend Complex<T> mySub <T>(Complex<T> &c1, Complex<T> &c2);
//3����Ԫ����ʵ�� ����д�ɣ�
template<typename T>
Complex<T> mySub(Complex<T> &c1, Complex<T> &c2)
{
	Complex<T> tmp(c1.a - c2.a, c1.b - c2.b);
	return tmp;
}
//4����Ԫ�������� ����д��
Complex<int> c4 = mySub<int>(c1, c2);
cout << c4;
