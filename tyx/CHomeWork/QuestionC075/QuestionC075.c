/*����ֻ��Сд��ĸ���ַ�����Ҫ���ֵ����Դ�С�����˳��������������ÿ���ַ�֮���1��(�ַ������Ȳ�����20��
	������
	abazc
	a a b c z

	Cui Shuning (��������2020/11
*/

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4267)

#include<stdio.h>
#include<string.h>

void StrBubble(char* a);
char* DelChar(char* str, char ch);

int main()
{
	char inStr[100];
	gets_s(inStr, 100);
	DelChar(inStr, ' ');

	StrBubble(inStr);

	printf("%c", inStr[0]);
	for (int i = 1; i < strlen(inStr); i++)
	{
		printf(" %c", inStr[i]);
	}
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

/// <summary>
/// ɾ���ַ�����ָ�����ַ�
/// </summary>
/// <param name="str">������ַ���</param>
/// <param name="ch">ɾ�����ַ�</param>
/// <returns>ɾ������ַ���</returns>

char* DelChar(char* str, char ch)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] == ch)
		{
			int j = 0;
			while (str[i + j + 1])
			{
				str[i + j] = str[i + j + 1];
				j++;
			}
			str[i + j] = 0;
		}
		else
		{
			i++;
		}
	}
	return str;
}
