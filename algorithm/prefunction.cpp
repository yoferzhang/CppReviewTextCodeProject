#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>

using namespace std;

// plus，预定义好的函数对象，能实现不同类型数据的 + 运算
// 实现了数据类型和算法的分离，通过函数对象技术实现的
void play01()
{
	/* plus函数对象原型
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

	plus<int> intAdd; // 预定义函数对象
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
	//缺省情况下，sort()用底层元素类型的小于操作符以升序排列容器的元素。
	//为了降序，可以传递预定义的类模板greater,它调用底层元素类型的大于操作符：

	sort(v.begin(), v.end(), greater<string>()); // 从大到小排序
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