#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
class IsDiv
{
public:
	IsDiv(const T d)
	{
		divisor = d;
	}
	bool operator()(T &t) // 一元谓词
	{
		return (t % divisor == 0);
	}
protected:
private:
	T divisor;
};

void play01()
{
	vector<int> v;
	for (int i = 10; i < 25; ++i) {
		v.push_back(i);
	}

	int a = 4;
	IsDiv<int> isDiv(a);

	find_if(v.begin(), v.end(), isDiv);
	//find_if(v.begin(), v.end(), IsDiv<int>(4)); // 也可以这样写
	/* find_if()函数原型
	template<class _InIt,
	class _Pr> inline
		_InIt find_if(_InIt _First, _InIt _Last, _Pr _Pred)
	{	// find first satisfying _Pred
		_DEBUG_RANGE(_First, _Last);
		_DEBUG_POINTER(_Pred);
		return (_Rechecked(_First,
			_Find_if(_Unchecked(_First), _Unchecked(_Last), _Pred)));
	}
	*/
	// find_if的返回值值一个迭代器

	vector<int>::iterator it = find_if(v.begin(), v.end(), isDiv);
	if (it == v.end()) {
		cout << "fail\n";
	}
	else {
		cout << "success " << *it << endl;
	}
}

int main()
{
	play01();

	return 0;
}