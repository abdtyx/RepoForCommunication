#include <stdio.h>
#include <string.h>
int main()
{
	char str[] = "China";
	int i,j;
	for (i=0;i<6;i++)
	{
		printf("%c", str[i]);
	}
	j = strlen(str);
	printf("%d", j);//�ַ���ʵ�ʳ��Ȳ�����\0����
	return 0;
}