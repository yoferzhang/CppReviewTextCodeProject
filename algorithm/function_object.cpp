#include <iostream>
#include <cstdio>

using namespace std;

// ����������������()
template <typename T>  
class ShowElement
{
public:
	// ����()
	void operator()(T &t) {
		cout << t << endl;
	}
protected:
private:
	int n;
};

// ����ģ��
template <typename T>
void FuncShowElement(T &t)
{
	cout << t << endl;
}

// ��ͨ����
void FuncShowElement2(int &t)
{
	cout << t << endl;
}

void play01()
{
	int a = 10;
	ShowElement<int> showElement;
	showElement(a); // ��������ĵ��ã�����һ�����������Խзº���
	// 10

	FuncShowElement<int>(a);
	FuncShowElement2(a);
	
}

int main()
{
	play01();
	
	return 0;
}