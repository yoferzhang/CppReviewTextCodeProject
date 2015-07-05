#include <iostream>
#include <cstdio>
using namespace std;

template <typename T>
class Complex; // 解决mySub友元函数的滥用

template <typename T>
Complex<T> mySub(Complex<T> &c1, Complex<T> &c2); // 解决mySub友元函数的滥用

template <typename T>
class Complex
{
	// 这个友元函数是滥用
	friend Complex<T> mySub<T>(Complex<T> &c1, Complex<T> &c2); // 写在里面没什么问题


	// 这样55行会报错
	//friend ostream &operator << (ostream &out, Complex &c2);

	// 解决方案
	friend ostream &operator << <T> (ostream &out, Complex &c2);

public:
	Complex(T a, T b);
	Complex operator + (Complex &c2);
	void printCom();

private:
	T a;
	T b;
};

// 构造函数拿到写在类的外部
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

// 注意函数参数和函数返回值都需要进行类型具体化
template <typename T>
Complex<T> Complex<T>::operator + (Complex<T> &c2)
{
	Complex tem(a + c2.a, b + c2.b);
	return tem;
}

// 报错的本质：模版是两次编译运行的，第一次生成的函数头和第二次生成的函数头不一样
// 友元函数实现 << 运算符重载
template <typename T>
ostream &operator << (ostream &out, Complex<T> &c2)
{
	out << c2.a << " + " << c2.b << "i\n";
	return out;
}
// 报错
/*
1>templateComplex2.obj : error LNK2019: 无法解析的外部符号 
"class std::basic_ostream<char,struct std::char_traits<char> > 
& __cdecl operator<<(class std::basic_ostream<char,struct std::char_traits<char> >
&,class Complex<int> &)" (??6@YAAAV?$basic_ostream@DU?$char_traits@D@std@@@std@@AAV01@AAV?$Complex@H@@@Z)，
该符号在函数 _main 中被引用
*/

//////////////////////////////////////////////////////
// 滥用友元函数
template <typename T>
Complex<T> mySub(Complex<T> &c1, Complex<T> &c2)
{
	Complex<T> tmp(c1.a - c2.a, c1.b - c2.b);
	return tmp;
}
// 报错。。。。。。

// 解决方案，做前置声明


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

//构造函数 没有问题
//普通函数 没有问题
//友元函数：用友元函数重载 << >>
//	friend ostream& operator<< <T> (ostream &out, Complex<T> &c3) ;
//友元函数：友元函数不是实现函数重载（非 << >>）
//1）需要在类前增加 类的前置声明 函数的前置声明 
template<typename T>
class Complex;
template<typename T>
Complex<T> mySub(Complex<T> &c1, Complex<T> &c2);

//2）类的内部声明 必须写成: 
friend Complex<T> mySub <T>(Complex<T> &c1, Complex<T> &c2);
//3）友元函数实现 必须写成：
template<typename T>
Complex<T> mySub(Complex<T> &c1, Complex<T> &c2)
{
	Complex<T> tmp(c1.a - c2.a, c1.b - c2.b);
	return tmp;
}
//4）友元函数调用 必须写成
Complex<int> c4 = mySub<int>(c1, c2);
cout << c4;
