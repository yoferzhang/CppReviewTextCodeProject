#include <iostream>
#include <cstdio>
using namespace std;

// throw char *
void myStrcpy(char *to, char *from)
{
	if (from == NULL) {
		throw "源buf出错";
	}
	if (to == NULL) {
		throw "目的buf出错";
	}

	// copy时的场景检查
	if (*from == 'a') {
		throw "copy过程出错"; // copy时错误
	}
	while (*from != '\0') {
		*to = *from;
		to++;
		from++;
	}
	*to = '\0';

	return;
}

int main()
{
	int ret = 0;
	char buf1[] = "abcdefg";
	char buf2[1024] = { 0 };

	try
	{
		myStrcpy(buf2, buf1);
	}
	catch (int e) // e可以写可以不写
	{
		cout << e << "int类型异常" << endl;
	}
	catch (char *e)
	{
		cout << "char* 类型异常" << endl;
	}
	catch (...)
	{
	};
	cout << endl;

	return 0;
}