#include <iostream>
#include <cstdio>

using namespace std;

// 函数对象，类重载了()
template <typename T>  
class ShowElement
{
public:
	// 重载()
	void operator()(T &t) {
		cout << t << endl;
	}
protected:
private:
	int n;
};

// 函数模版
template <typename T>
void FuncShowElement(T &t)
{
	cout << t << endl;
}

// 普通函数
void FuncShowElement2(int &t)
{
	cout << t << endl;
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

int main()
{
	play01();
	
	return 0;
}