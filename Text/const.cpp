// C语言中的const是一个冒牌货
int main()
{
	// 好像a是一个常量
	const int a = 10;
	int *p = NULL;
	p = (int *)&a;
	*p = 20; // 间接赋值

	printf("a:%d\n", a);
	// C语言中显示a被修改了
	// C++则显示a还是10，没有改变

	return 0;
}