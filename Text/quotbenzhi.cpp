#include <iostream>
using namespace std;

int main()
{
	int a = 10;
	// �������������ʱ�������ʼ����˵������һ������
	int &b = a;
	// b��a�ı���
	b = 11;
	cout << "b--->" << a << endl;
	printf("a:%d\n", a);
	printf("b:%d\n", b); 
	printf("&a:%d\n", &a);
	printf("&b:%d\n", &b);
	system("pause");
	return 0;
}

struct Teacer {
	int &a;
	int &b;
};
int main()
{
	printf("sizeof(Teacher) %d\n", sizeof(Teacer));
	system("pause");
	return 0;
}
