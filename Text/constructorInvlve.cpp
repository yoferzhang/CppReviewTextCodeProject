#include <iostream>
using namespace std;

class Text
{
public:
	Text() // �޲������캯��
	{
		m_a = 0;
		m_b = 0;
		cout << "�޲������캯��" << endl;
	}

	Text(int a) // �в������캯��
	{
		m_a = a;
		m_b = 0;
		cout << "�޲������캯��" << endl;
	}

	Text(int a, int b) // �в������캯���������ֵ��÷���
	{
		m_a = a;
		m_b = b;
		cout << "�в������캯��" << endl;
	}

	// ��ֵ���캯����Ҳ��copy���캯��
	Text(const Text& obj)
	{
		cout << "��Ҳ�ǹ��캯��" << endl;
	}

	~Text();

	void printT()
	{
		cout << "��ͨ��Ա����" << endl;
		cout << "m_a" << m_a << " m_a" << m_b << endl;
	}

private:
	int m_a;
	int m_b;
};

// 1 ��ֵ���캯������1������ȥ��ʼ������һ������
int main()
{
	Text t1(1, 2);
	Text t0(1, 2);

	// ��ֵ = ������������ù��캯��
	t0 = t1;
	// ��t1��t0��ֵ���ͳ�ʼ����������ͬ�ĸ���

	// ��һ�ֵ���ʱ��
	Text t2 = t1; // ��t1����ʼ��t2
	t2.printT;
	return 0;
}

// �ڶ��ֵ��÷���
int main()
{
	Text t1(1, 2);
	Text t0(1, 2);

	Text t2(t1); // ��t1�����ʼ��t2����
	t2.printT();

	return 0;
}