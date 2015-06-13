#include <iostream>
using namespace std;

class Text
{
public:
	Text() // 无参数构造函数
	{
		m_a = 0;
		m_b = 0;
		cout << "无参数构造函数" << endl;
	}

	Text(int a) // 有参数构造函数
	{
		m_a = a;
		m_b = 0;
		cout << "无参数构造函数" << endl;
	}

	Text(int a, int b) // 有参数构造函数，有三种调用方法
	{
		m_a = a;
		m_b = b;
		cout << "有参数构造函数" << endl;
	}

	// 赋值构造函数，也叫copy构造函数
	Text(const Text& obj)
	{
		cout << "这也是构造函数" << endl;
	}

	~Text();

	void printT()
	{
		cout << "普通成员函数" << endl;
		cout << "m_a" << m_a << " m_a" << m_b << endl;
	}

private:
	int m_a;
	int m_b;
};

// 1 赋值构造函数，用1个对象去初始化另外一个对象
int main()
{
	Text t1(1, 2);
	Text t0(1, 2);

	// 赋值 = 操作，不会调用构造函数
	t0 = t1;
	// 用t1给t0赋值，和初始化是两个不同的概念

	// 第一种调用时机
	Text t2 = t1; // 用t1来初始化t2
	t2.printT;
	return 0;
}

// 第二种调用方法
int main()
{
	Text t1(1, 2);
	Text t0(1, 2);

	Text t2(t1); // 用t1对象初始化t2对象
	t2.printT();

	return 0;
}