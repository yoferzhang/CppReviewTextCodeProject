#include <iostream>
#include <cstdio>
using namespace std;

// ��ͳ�Ĵ��������
int myStrcpy(char *to, char *from)
{
	if (from == NULL) {
		return 1;
	}
	if (to == NULL) {
		return 2;
	}

	// copyʱ�ĳ������
	if (*from == 'a') {
		return 3; // copyʱ����
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
			cout << "Դbuf����!\n";
			break;
		case 2:
			cout << "Ŀ��buf����!\n";
			break;
		case 3:
			cout << "copy���̳���!\n";
			break;
		default:
			cout << "δ֪����!\n";
			break;
		}
	}
	cout << "buf2:\n" << buf2;
	cout << endl;

	return 0;
}