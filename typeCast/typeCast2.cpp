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
	base->cry(); // 1有继承，2虚函数重载，3父类指针，指向子类对象。
	// 会发生多态

	// 识别子类对象
	// dynamic_cast<>()运行时类型识别

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
	pBase = static_cast<Animal *>(&d1); // 让C++编译器在编译的时候进行类型检查

	// 强制类型转换
	pBase = reinterpret_cast<Animal *>(&d1);

	{
		Tree t1;
		//pBase = static_cast<Animal *>(&t1); // C++编译器做类型检查，报错
		pBase = reinterpret_cast<Animal *>(&t1); // reinterpret_cast重新解释，这里有强制类型转换的感觉
	}

	playObj(&d1);
	playObj(&c1);

	return 0;
}