#include <iostream>
#include <cstdio>
using namespace std;


class Tree {};

class Animal
{
	virtual void cry() = 0;
};

class Dog : public Animal
{
public:
	virtual void cry()
	{
		cout << "bowwow~" << endl;
	}

	void doHome()
	{
		cout << "look after the house!" << endl;
	}
};

class Cat : public Animal
{
public:
	virtual void cry()
	{
		cout << "meow" << endl;
	}

	void doThing()
	{
		cout << "catch a Mouse" << endl;
	}
};

void playObj(Animal *base)
{
	base->cry(); // 1�м̳У�2�麯�����أ�3����ָ�룬ָ���������
	// �ᷢ����̬

	// ʶ���������
	// dynamic_cast<>()����ʱ����ʶ��

	Dog *pDog = dynamic_cast<Dog *>(base);
	if (pDog != NULL) {
		pDog->doHome();
	}

	Cat *pCat = dynamic_cast<Cat *>(base);
	if (pCat != NULL) {
		pCat->doThing();
	}
}

int main()
{
	Dog d1;
	Cat c1;

	Animal *pBase = NULL;
	pBase = &d1;
	pBase = static_cast<Animal *>(&d1); // ��C++�������ڱ����ʱ��������ͼ��

	// ǿ������ת��
	pBase = reinterpret_cast<Animal *>(&d1);

	{
		Tree t1;
		//pBase = static_cast<Animal *>(&t1); // C++�����������ͼ�飬����
		pBase = reinterpret_cast<Animal *>(&t1); // reinterpret_cast���½��ͣ�������ǿ������ת���ĸо�
	}

	playObj(&d1);
	playObj(&c1);

	return 0;
}