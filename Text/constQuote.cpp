

int main()
{
	int a = 10;
	const int &b = a;

	//int *p = (int *)&b;
	b = 11; //error
	//*p = 11; //只能用指针来改变了

	cout << "b--->" << a << endl;
	printf("a:%d\n", a);
	printf("b:%d\n", b);
	printf("&a:%d\n", &a);
	printf("&b:%d\n", &b);
	system("pause");
	return 0;
}
