#include <stdio.h>
int add(int data[])
{
	int i;
	for (i = 0; i < 5; i++)
	{
		data[i] = data[i] + 1;
	}
	for (i = 0; i < 5; i++)
	{
		printf("#%d ", data[i]);
	}
	printf("\n");
	return 0;
}
int main()
{
	int i;
	int data[5] = { 1,2,3,4,5 };
	for (i = 0; i < 5; i++)
	{
		printf("%d ", data[i]);
	}
	printf("\n");
	add(data);
	for (i = 0; i < 5; i++)
	{
		printf("%d ", data[i]);
	}
}
//���ۣ������ڴ�ֵ����ʱ��ı�ԭֵ����Ϊ�����ϴ�����������Ԫ�ص�ַ���൱�ڻص�������