#include <stdio.h>
int main()
{
	int i, a[10];
	for (i=0;i<=9;i++)
		a[i]=i;
	for (i=9;i<=5;i--)
		printf("%d", a[i]);//˵��������ʼֵ�����ж�����ʱ��ֱ������ѭ�� 
	return 0;
}
