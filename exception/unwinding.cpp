#include <iostream>
#include <cstdio>
using namespace std;


class MyException {};

class Test
{
public:
	Test(int a = 0, int b = 0)
	{
		this->a = a;
		this->b = b;
		cout << "Test ���캯��ִ��" << "a:" << a << " b: " << b << endl;
	}
	void printT()
	{
		cout << "a:" << a << " b: " << b << endl;
	}
	~Test()
	{
		cout << "Test ��������ִ��" << "a:" << a << " b: " << b << endl;
	}
private:
	int a;
	int b;
};

void myFunc() throw (MyException)
{
	Test t1;
	Test t2;

	cout << "����������ջ����,�쳣�׳������ջ��������α�����" << endl;

	throw MyException();
}

int main()
{
	//�쳣���׳��󣬴ӽ���try���𣬵��쳣������ǰ�����ڼ���ջ�ϵĹ�������ж���
	//���ᱻ�Զ�������������˳���빹���˳���෴��
	//��һ���̳�Ϊջ�Ľ���(unwinding)
	try
	{
		myFunc();
	}
	//catch(MyException &e) //���ﲻ�ܷ����쳣����
	catch (MyException) //���ﲻ�ܷ����쳣����
	{
		cout << "���յ�MyException�����쳣" << endl;
	}
	catch (...)
	{
		cout << "δ֪�����쳣" << endl;
	}

	return 0;
}
