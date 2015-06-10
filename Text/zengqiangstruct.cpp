struct Student
{
	char name[100];
	int age;
};

int main(int argc, char *argv[])
{
	// C语言中需要在定义结构体的时候加struct，而C++不需要
	Student s1 = { "wang", 1 };
	Student s2 = { "wang2", 2 };
	return 0;
}
