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

private:
	int m_a;
	int m_b;
};



int main()
{
	// 1括号法
	Text t1; // 调用无参数构造函数

	// 2等号法
	Text t2 = (3, 4, 5, 6, 7);
	// C++对等号进行了加强，c++编译器自动的调用构造函数

	// 3直接调用构造函数，手动调用构造函数
	Text t3 = Text(1, 2); // 这里涉及到匿名对象
	return 0;
}