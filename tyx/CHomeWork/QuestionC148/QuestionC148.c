/*�����ַ�������str�������鳤��Ϊ81�����̶���һ���ַ���������81���ַ����������ַ����г��ֵ�����Сд��ĸ����ĸ�������������ĸ��Ϊ��abcdefg��xyz����
���������ʽҪ��
���������ռһ�У���һ�������룬�ڶ����������

Cui Shuning (��������2020/11
*/

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4267)

#include<stdio.h>
#include<string.h>

void StrBubble(char* a);

int main()
{
	char low[100];
	char inStr[200];
	(void)scanf("%s", inStr);
	int i = 0;
	int j = 0;
	while (inStr[i])
	{
		if (inStr[i] >= 'a' && inStr[i] <= 'z')
		{
			low[j] = inStr[i];
			j++;
		}
		i++;
	}
	low[j] = 0;
	StrBubble(low);
	printf("%s", low);
	return 0;
}

void StrBubble(char* a)
{
	int len = strlen(a);
	for (int i = 0; i < len; i++)
	{
		for (int j = len - 1; j > i; j--)
		{
			if (a[j] < a[j - 1])
			{
				char temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
			}
		}
	}
}
