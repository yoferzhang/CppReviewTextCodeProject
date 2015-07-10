#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>

using namespace std;

// plus��Ԥ����õĺ���������ʵ�ֲ�ͬ�������ݵ� + ����
// ʵ�����������ͺ��㷨�ķ��룬ͨ������������ʵ�ֵ�
void play01()
{
	/* plus��������ԭ��
	template<class _Ty = void>
	struct plus
		: public binary_function < _Ty, _Ty, _Ty >
	{	// functor for operator+
		_Ty operator()(const _Ty& _Left, const _Ty& _Right) const
		{	// apply operator+ to operands
			return (_Left + _Right);
		}
	};
	*/

	plus<int> intAdd; // Ԥ���庯������
	int x = 10;
	int y = 20;
	int z = intAdd(x, y); // x + y;
	cout << "z: " << z << endl;
	// z : 30

	plus<string> stringAdd;
	string s1 = "lucifer";
	string s2 = "zhang";
	string s3 = stringAdd(s1, s2);
	cout << "s3: " << s3 << endl;
	// s3: luciferzhang
}

void play02()
{
	vector<string> v;
	v.push_back("lucifer");
	v.push_back("zhang");
	v.push_back("yao");
	v.push_back("qi");

	/*
	template<class _Ty = void>
	struct greater
		: public binary_function < _Ty, _Ty, bool >
	{	// functor for operator>
		bool operator()(const _Ty& _Left, const _Ty& _Right) const
		{	// apply operator> to operands
			return (_Left > _Right);
		}
	};
	*/
	//ȱʡ����£�sort()�õײ�Ԫ�����͵�С�ڲ���������������������Ԫ�ء�
	//Ϊ�˽��򣬿��Դ���Ԥ�������ģ��greater,�����õײ�Ԫ�����͵Ĵ��ڲ�������

	sort(v.begin(), v.end(), greater<string>()); // �Ӵ�С����
	for (vector<string>::iterator it = v.begin(); it != v.end(); ++it) {
		cout << *it << ' ';
	}
	cout << endl;
	// zhang yao qi lucifer

	string sl = "lucifer";
	int num = count_if(v.begin(), v.end(), bind2nd(equal_to<string>(), sl));
	cout << "count of 'lucifer': " << num << endl;
	// count of 'lucifer': 1
}

int main()
{
	play01();
	play02();

	return 0;
}