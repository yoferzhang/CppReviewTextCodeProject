
#include <iostream>
using namespace std;


class Parent1
{
public:
	Parent1(int a = 0)
	{
		this->a = a;
	}

	void print()
	{
		cout << "����" << endl;
	}
private:
	int a;
};

class Parent2
{
public:
	Parent2(int a = 0)
	{
		this->a = a;
	}

	virtual void print()
	{
		cout << "�����������ĸ���" << endl;
	}
private:
	int a;
};

int main()
{
	printf("sizeof(Parent):%d sizeof(Parent2):%d \n", sizeof(Parent1), sizeof(Parent2));
	// �������ͨ���СΪ4�����Ѻ�������鹹����֮���СΪ8������֤��������vptrָ��Ĵ�����

	return 0;
}
