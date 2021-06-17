/// <ID>C096</ID>
/// <date>2020/11</date>
/// <summary>
/// ����һ�����Ȳ����� 100 ���ַ�����ɾ�����е��ظ��ַ���
/// ����Ҫ�����ַ��������Ȳ�����100���ַ������磺abacaeedabcdcd��
/// ɾ���ظ��ַ�����ַ��������磺abced��
/// </summary>
/// <input>һ���ַ���</input>
/// <output>ɾ���ظ��ַ�����ַ���</output>
/// <sample>
/// abacaeedabcdcd
/// abced
/// </sample>
/// <author>Cui Shuning (��������</author>
/// <difficulty>03</difficulty>
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
char* DelChar(char* str, char ch);

int main()
{
	char str[100];
	(void)scanf("%s", str);
	int i = 0;
	while (str[i])
	{
		DelChar(str + i + 1, str[i]);
		i++;
	}
	printf("%s", str);
	return 0;
}

/// <summary>
/// ���ַ�����ָ�����ַ�ɾ��
/// </summary>
/// <param name="str">��������ַ���</param>
/// <param name="ch">��Ҫɾ�����ַ�</param>
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
