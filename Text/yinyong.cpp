//�����������͵�����
#include <iostream>
using namespace std;

struct Teacher
{
	char name[64];
	int age;
};

void printfT(Teacher *pT)
{
	cout << pT->age << endl;
}

//pT��t1�ı��� ,�൱���޸���t1
void printfT2(Teacher &pT)
{
	//cout<<pT.age<<endl;
	pT.age = 33;
}

//pT��t1����������ͬ�ı���
void printfT3(Teacher pT)
{
	cout << pT.age << endl;
	pT.age = 45; //ֻ���޸�pT���� ,�����޸�t1����
}
void main()
{
	Teacher t1;
	t1.age = 35;

	printfT(&t1);

	printfT2(t1); //pT��t1�ı���
	printf("t1.age:%d \n", t1.age); //33

	printfT3(t1);// pT���β� ,t1 copyһ������ ��pT     //---> pT = t1
	printf("t1.age:%d \n", t1.age); //35

	cout << "hello..." << endl;
	system("pause");
	return;
}
