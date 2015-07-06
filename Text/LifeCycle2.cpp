#include <iostream>
#include <cstdio>
using namespace std;

// throw char *
void myStrcpy(char *to, char *from)
{
	if (from == NULL) {
		throw "Դbuf����";
	}
	if (to == NULL) {
		throw "Ŀ��buf����";
	}

	// copyʱ�ĳ������
	if (*from == 'a') {
		throw "copy���̳���"; // copyʱ����
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
	catch (int e) // e����д���Բ�д
	{
		cout << e << "int�����쳣" << endl;
	}
	catch (char *e)
	{
		cout << "char* �����쳣" << endl;
	}
	catch (...)
	{
	};
	cout << endl;

	return 0;
}