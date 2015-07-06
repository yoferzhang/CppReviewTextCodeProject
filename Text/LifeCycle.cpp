#include <iostream>
#include <cstdio>
using namespace std;

// 传统的错误处理机制
int myStrcpy(char *to, char *from)
{
	if (from == NULL) {
		return 1;
	}
	if (to == NULL) {
		return 2;
	}

	// copy时的场景检查
	if (*from == 'a') {
		return 3; // copy时错误
	}
	while (*from != '\0') {
		*to = *from;
		to++;
		from++;
	}
	*to = '\0';

	return 0;
}

int main()
{
	int ret = 0;
	char buf1[] = "zbcdefg";
	char buf2[1024] = { 0 };

	ret = myStrcpy(buf2, buf1);
	if (ret != 0) {
		switch (ret) {
		case 1:
			cout << "源buf出错!\n";
			break;
		case 2:
			cout << "目的buf出错!\n";
			break;
		case 3:
			cout << "copy过程出错!\n";
			break;
		default:
			cout << "未知错误!\n";
			break;
		}
	}
	cout << "buf2:\n" << buf2;
	cout << endl;

	return 0;
}