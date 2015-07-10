#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class IsGreat
{
public:
	IsGreat(int i)
	{
		m_num = i;
	}
	bool operator()(int &num)
	{
		return m_num > num;
	}
private:
	int m_num;
};

void play01()
{
	vector<int> v1;
	for (int i = 0; i<10; i++)
	{
		v1.push_back(i + 1);
	}
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	int num1 = count(v1.begin(), v1.end(), 3);
	cout << "num1:" << num1 << endl;

	//ͨ�� ν�� �����2 �ĸ���
	int num2 = count_if(v1.begin(), v1.end(), IsGreat(2));
	cout << "num2:" << num2 << endl;

	/*
	template<class _Ty>
	struct greater
	: public binary_function<_Ty, _Ty, bool>
	{	// functor for operator>
	bool operator()(const _Ty& _Left, const _Ty& _Right) const
	{	// apply operator> to operands
	return (_Left > _Right);
	}
	};
	*/
	//ͨ�� Ԥ����ĺ������� �����2 �ĸ���
	//greater<int>() ���������� ���������������Ԫ�� ���Ҳ����̶���2 ��ͨ��bind2nd���ģ�
	int num3 = count_if(v1.begin(), v1.end(), bind2nd(greater<int>(), 2));
	cout << "num3: " << num3 << endl;
	// num3: 8

	//�� �����ĸ���
	int num4 = count_if(v1.begin(), v1.end(), bind2nd(modulus<int>(), 2));
	cout << "count of odd num4: " << num4 << endl;
	// count of odd num4: 5

	//�� ż���ĸ��� ȡ����(negator) 
	int num5 = count_if(v1.begin(), v1.end(), not1(bind2nd(modulus<int>(), 2)));
	cout << "count of even num5: " << num5 << endl;
	// count of even num5: 5
}

int main()
{
	play01();

	return 0;
}