// C�����е�const��һ��ð�ƻ�
int main()
{
	// ����a��һ������
	const int a = 10;
	int *p = NULL;
	p = (int *)&a;
	*p = 20; // ��Ӹ�ֵ

	printf("a:%d\n", a);
	// C��������ʾa���޸���
	// C++����ʾa����10��û�иı�

	return 0;
}