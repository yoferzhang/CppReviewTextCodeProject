#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

// 函数对象，类重载了()
template <typename T>
class ShowElement
{
public:
	ShowElement() 
	{
		n = 0;
	}
	// 重载()
	void operator()(T &t) {
		++n;
		cout << t << ' ';
	}

	void printN()
	{
		cout << "n: " << n << endl;
	}
protected:
private:
	int n;
};

// 函数模版
template <typename T>
void FuncShowElement(T &t)
{
	cout << t << ' ';
}

// 普通函数
void FuncShowElement2(int &t)
{
	cout << t << ' ';
}

void play01()
{
	int a = 10;
	ShowElement<int> showElement;
	showElement(a); // 函数对象的调用，很像一个函数，所以叫仿函数
	// 10

	FuncShowElement<int>(a);
	FuncShowElement2(a);

}

// 函数对象的好处
// 函数对象属于类对象，能突破函数的概念，能保持调用状态信息
void play02()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(5);

	for_each(v.begin(), v.end(), ShowElement<int>()); // 匿名函数对象，匿名仿函数
	cout << endl;
	// 1 3 5

	for_each(v.begin(), v.end(), FuncShowElement2); // 通过回调函数
	cout << endl;
	// 1 3 5

	// 改写一下类ShowElement
	ShowElement<int> showElement;
	/* for_each函数原型

	template<class _InIt,
		class _Fn1> inline
		_Fn1 for_each(_InIt _First, _InIt _Last, _Fn1 _Func)
		{	// perform function for each element
		_DEBUG_RANGE(_First, _Last);
		_DEBUG_POINTER(_Func);
		_For_each(_Unchecked(_First), _Unchecked(_Last), _Func);

		return (_STD move(_Func));
		}
	*/
	// 可以看出for_each算法的函数对象传递是元素值传递，不是引用传递
	for_each(v.begin(), v.end(), showElement);
	cout << endl;
	showElement.printN(); // 所以这里打印结果并不是我们预期的3
	// n: 0
	
	// 解决方案，for_each最后是把传进去的函数对象做了值返回
	showElement = for_each(v.begin(), v.end(), showElement);
	cout << endl;
	showElement.printN(); // bingo
	// n: 3
}

int main()
{
	//play01();
	play02();

	return 0;
}