/*����һ��Ӣ���ַ��������� < 81�����ܰ����ո�
ɾ���������з�Сд��ĸ�ַ���
�����ɾ������ַ�����Сд��ĸ�����λ�ñ��ֲ��䣩��

Cui Shuning (��������2020/11
*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

char* DelChar(char* str, char ch);

int main()
{
	char input[100];
	gets_s(input,100);
	int i = 0;
	while (input[i])
	{
		if (!(input[i] >= 'a' && input[i] <= 'z'))
		{
			DelChar(input, input[i]);
			continue;
		}
		i++;
	}
	printf("%s", input);
	return 0;
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
