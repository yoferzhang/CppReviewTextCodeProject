//复杂数据类型的引用
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

//pT是t1的别名 ,相当于修改了t1
void printfT2(Teacher &pT)
{
	//cout<<pT.age<<endl;
	pT.age = 33;
}

//pT和t1的是两个不同的变量
void printfT3(Teacher pT)
{
	cout << pT.age << endl;
	pT.age = 45; //只会修改pT变量 ,不会修改t1变量
}
void main()
{
	Teacher t1;
	t1.age = 35;

	printfT(&t1);

	printfT2(t1); //pT是t1的别名
	printf("t1.age:%d \n", t1.age); //33

	printfT3(t1);// pT是形参 ,t1 copy一份数据 给pT     //---> pT = t1
	printf("t1.age:%d \n", t1.age); //35

	cout << "hello..." << endl;
	system("pause");
	return;
}
