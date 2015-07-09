#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

// ����������������()
template <typename T>
class ShowElement
{
public:
	ShowElement() 
	{
		n = 0;
	}
	// ����()
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

// ����ģ��
template <typename T>
void FuncShowElement(T &t)
{
	cout << t << ' ';
}

// ��ͨ����
void FuncShowElement2(int &t)
{
	cout << t << ' ';
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

// ��������ĺô�
// �������������������ͻ�ƺ����ĸ���ܱ��ֵ���״̬��Ϣ
void play02()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(5);

	for_each(v.begin(), v.end(), ShowElement<int>()); // �����������������º���
	cout << endl;
	// 1 3 5

	for_each(v.begin(), v.end(), FuncShowElement2); // ͨ���ص�����
	cout << endl;
	// 1 3 5

	// ��дһ����ShowElement
	ShowElement<int> showElement;
	/* for_each����ԭ��

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
	// ���Կ���for_each�㷨�ĺ������󴫵���Ԫ��ֵ���ݣ��������ô���
	for_each(v.begin(), v.end(), showElement);
	cout << endl;
	showElement.printN(); // ���������ӡ�������������Ԥ�ڵ�3
	// n: 0
	
	// ���������for_each����ǰѴ���ȥ�ĺ�����������ֵ����
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