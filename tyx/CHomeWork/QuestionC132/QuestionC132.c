/*��д����, ����ԭ������:
void fun(int n, char res[]);
�ú����Ĺ����ǽ�����n�ĸ�λ�����������У���ŵ�res�ַ������С���������1035�������Ϊ5301��
���������ʽ��
���룺һ������(������λ������15λ)��
�����������ֵ��

Cui Shuning (��������2020/11
*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

void fun(int n, char res[]);

int main()
{
	int n;
	(void)scanf("%d", &n);
	char res[20];
	fun(n, res);
	printf("%s", res);
	return 0;
}

void fun(int n, char res[])
{
	int i = 0;
	while (n)
	{
		res[i++] = n % 10 + '0';
		n /= 10;
	}
	res[i] = 0;
}
