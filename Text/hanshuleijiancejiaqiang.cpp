#include <stdio.h>
int g_var;
int g_var = 1;
// C语言可以编译通过
// C++直接拒绝这种二义性
int main(int argc, char *argv[])
{
	printf("g_var = %d\n", g_var);
	return 0;
}