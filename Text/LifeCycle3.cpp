#include <iostream>
#include <cstdio>
using namespace std;

class BadSrcType {};
class BadDestType {};
class BadProcessType
{
public:
	BadProcessType()
	{
		cout << "BadProcessType构造函数do \n";
	}


	BadProcessType(const BadProcessType &obj)
	{
		cout << "BadProcessType copy构造函数do \n";
	}

	~BadProcessType()
	{
		cout << "BadProcessType析构函数do \n";
	}

};

//throw 类对象 类型异常
void my_strcpy3(char *to, char *from)
{
	if (from == NULL)
	{
		throw BadSrcType();
	}
	if (to == NULL)
	{
		throw BadDestType();
	}

	//copy是的 场景检查
	if (*from == 'a')
	{
		printf("开始 BadProcessType类型异常 \n");
		throw BadProcessType(); //会不会产生一个匿名对象?
	}

	if (*from == 'b')
	{
		throw &(BadProcessType()); //会不会产生一个匿名对象?
	}

	if (*from == 'c')
	{
		throw new BadProcessType; //会不会产生一个匿名对象?
	}
	while (*from != '\0')
	{
		*to = *from;
		to++;
		from++;
	}
	*to = '\0';
}

int main()
{
	int ret = 0;
	char buf1[] = "cbbcdefg";
	char buf2[1024] = { 0 };

	try
	{
		//my_strcpy1(buf2, buf1);
		//my_strcpy2(buf2, buf1);
		my_strcpy3(buf2, buf1);
	}
	catch (int e) //e可以写 也可以不写
	{
		cout << e << " int类型异常" << endl;
	}
	catch (char *e)
	{
		cout << e << " char* 类型异常" << endl;
	}

	//---
	catch (BadSrcType e)
	{
		cout << " BadSrcType 类型异常" << endl;
	}
	catch (BadDestType e)
	{
		cout << " BadDestType 类型异常" << endl;
	}
	//结论1: 如果 接受异常的时候 使用一个异常变量,则copy构造异常变量.  
	/*
	catch( BadProcessType e) //是把匿名对象copy给e 还是e还是那个匿名对象
	{
	cout << " BadProcessType 类型异常" << endl;
	}
	*/
	/*结论2: 使用引用的话 会使用throw时候的那个对象
	catch( BadProcessType &e) //是把匿名对象copy给e 还是e还是那个匿名对象
	{
	cout << " BadProcessType 类型异常" << endl;
	}
	*/

	//结论3: 指针可以和引用/元素写在一块 但是引用和元素不能写在一块
	catch (BadProcessType *e) //是把匿名对象copy给e 还是e还是那个匿名对象
	{
		cout << " BadProcessType 类型异常" << endl;
		delete e;
	}

	//结论4: 类对象时, 使用引用比较合适 

	// --
	catch (...)
	{
		cout << "未知 类型异常" << endl;
	}

	return 0;
}