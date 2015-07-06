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
		cout << "BadProcessType���캯��do \n";
	}


	BadProcessType(const BadProcessType &obj)
	{
		cout << "BadProcessType copy���캯��do \n";
	}

	~BadProcessType()
	{
		cout << "BadProcessType��������do \n";
	}

};

//throw ����� �����쳣
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

	//copy�ǵ� �������
	if (*from == 'a')
	{
		printf("��ʼ BadProcessType�����쳣 \n");
		throw BadProcessType(); //�᲻�����һ����������?
	}

	if (*from == 'b')
	{
		throw &(BadProcessType()); //�᲻�����һ����������?
	}

	if (*from == 'c')
	{
		throw new BadProcessType; //�᲻�����һ����������?
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
	catch (int e) //e����д Ҳ���Բ�д
	{
		cout << e << " int�����쳣" << endl;
	}
	catch (char *e)
	{
		cout << e << " char* �����쳣" << endl;
	}

	//---
	catch (BadSrcType e)
	{
		cout << " BadSrcType �����쳣" << endl;
	}
	catch (BadDestType e)
	{
		cout << " BadDestType �����쳣" << endl;
	}
	//����1: ��� �����쳣��ʱ�� ʹ��һ���쳣����,��copy�����쳣����.  
	/*
	catch( BadProcessType e) //�ǰ���������copy��e ����e�����Ǹ���������
	{
	cout << " BadProcessType �����쳣" << endl;
	}
	*/
	/*����2: ʹ�����õĻ� ��ʹ��throwʱ����Ǹ�����
	catch( BadProcessType &e) //�ǰ���������copy��e ����e�����Ǹ���������
	{
	cout << " BadProcessType �����쳣" << endl;
	}
	*/

	//����3: ָ����Ժ�����/Ԫ��д��һ�� �������ú�Ԫ�ز���д��һ��
	catch (BadProcessType *e) //�ǰ���������copy��e ����e�����Ǹ���������
	{
		cout << " BadProcessType �����쳣" << endl;
		delete e;
	}

	//����4: �����ʱ, ʹ�����ñȽϺ��� 

	// --
	catch (...)
	{
		cout << "δ֪ �����쳣" << endl;
	}

	return 0;
}