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

private:
	int m_a;
	int m_b;
};



int main()
{
	// 1���ŷ�
	Text t1; // �����޲������캯��

	// 2�Ⱥŷ�
	Text t2 = (3, 4, 5, 6, 7);
	// C++�ԵȺŽ����˼�ǿ��c++�������Զ��ĵ��ù��캯��

	// 3ֱ�ӵ��ù��캯�����ֶ����ù��캯��
	Text t3 = Text(1, 2); // �����漰����������
	return 0;
}