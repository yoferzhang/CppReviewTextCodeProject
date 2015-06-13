#include <iostream>
using namespace std;

class Location
{
public:
	Location(int xx = 0, int yy = 0)
	{
		X = xx;
		Y = yy;
		cout << "Constructor Object.\n";
	}

	// copy���캯������ɶ���ĳ�ʼ��
	Location(const Location & obj)
	{
		X = obj.X;
		Y = obj.Y;
	}

	~Location()
	{
		cout << X << "," << Y << " Object destroyed." << endl;
	}

	int getX()
	{
		return X;
	}

	int getY()
	{
		return Y;
	}

private:
	int X, Y;
};

//g��������һ��Ԫ�� 
//����1 : �����ķ���ֵ��һ��Ԫ�� (�������͵�), ���ص���һ���µ���������(���Ի���������������copy���캯��)

//
//����2: �й� ���������ȥ����
//������������󣬳�ʼ������һ��ͬ���͵Ķ���, ��������ת����������
//������������󣬸�ֵ������һ��ͬ���͵Ķ���, �������󣬱�����

//
//��ôд����,��Ʊ������Ĵ�ţ��:
//�ͷ���һ���¶���(û������ ��������)
Location g()
{
	Location A(1, 2);
	return A;
}

//
void objplay2()
{
	g();
}

//
void objplay3()
{
	//�����������ʼ��m����ʱc++��������ֱ�Ӱ�������ת��m;(����)��������ת����������m
	Location m = g();
	printf("��������,������,����������\n");
	cout << m.GetX() << endl;;
}

void objplay4()
{
	//���������󣬸�ֵ��m2��,������������
	Location m2(1, 2);
	m2 = g();
	printf("��Ϊ����������=��m2, ��������,������\n");
	cout << m2.getX() << endl;;
}

