struct Student
{
	char name[100];
	int age;
};

int main(int argc, char *argv[])
{
	// C��������Ҫ�ڶ���ṹ���ʱ���struct����C++����Ҫ
	Student s1 = { "wang", 1 };
	Student s2 = { "wang2", 2 };
	return 0;
}
