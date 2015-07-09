#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
class SumVector
{
public:
	T operator()(T t1, T t2) // 二元函数对象
	{
		return t1 + t2;
	}
protected:
private:
};

void play01()
{
	vector<int> v1, v2, v3;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	
	v2.push_back(2);
	v2.push_back(4);
	v2.push_back(6);

	v3.resize(10);
	transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), SumVector<int>());
	/* transform函数原型
	template<class _InIt1,
	class _InIt2,
	class _OutIt,
	class _Fn2> inline
		_OutIt transform(_InIt1 _First1, _InIt1 _Last1,
		_InIt2 _First2, _OutIt _Dest, _Fn2 _Func)
	{	// transform [_First1, _Last1) and [_First2, ...) with _Func
		_DEBUG_RANGE(_First1, _Last1);
		_DEBUG_POINTER(_Dest);
		_DEBUG_POINTER(_Func);
		if (_First1 != _Last1)
			return (_Transform2(_Unchecked(_First1), _Unchecked(_Last1),
			_First2, _Dest, _Func,
			_Is_checked(_Dest)));
		return (_Dest);
	}
	*/
	// transform把运算结果迭代器的开始位置返回出来

	for (vector<int>::iterator it = v3.begin(); it != v3.end(); ++it) {
		cout << *it << ' ';
	}
	cout << endl;
	// 3 7 11 0 0 0 0 0 0 0
}



int main()
{
	play01();

	return 0;
}