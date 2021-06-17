/// <ID>C087</ID>
/// <date>2020/11</date>
/// <summary>
/// ��д����ɾ���ַ����м�������Ǻ�*�������β��*�ţ��������䡣�ַ������Ȳ�����200��
/// </summary>
/// <input>��*�ŵ��ַ������ַ����в����ո�</input>
/// <output>�м�û��*�ŵ��ַ���</output>
/// <sample>
/// ***street*****music***
/// ***streetmusic***
/// </sample>
/// <author>Cui Shuning (��������</author>
/// <difficulty>03</difficulty>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4267)

#include<stdio.h>
#include<string.h>

char* DelCharBetweenStr(char* str, int i, int j, char delch);

int main()
{
	char inStr[100];
	gets_s(inStr, 100);
	int i = 0;
	while (inStr[i++] == '*');
	int j = strlen(inStr) - 1;
	while (inStr[j--] == '*');
	printf("%s", DelCharBetweenStr(inStr, i - 1, j + 1, '*'));
	return 0;
}
/// <summary>
/// ɾ���ַ�����i��j֮��ָ�����ַ�
/// </summary>
/// <param name="str">�ַ�����</param>
/// <param name="i">ɾ������ʼλ��</param>
/// <param name="j">ɾ���Ľ���λ��</param>
/// <param name="delch">ɾ�����ַ�</param>
/// <returns>ɾ���Ľ���ַ���</returns>
char* DelCharBetweenStr(char* str, int i, int j, char delch)
{
	//ɾ��i��j֮�������ַ���
	while (j >= i)
	{
		if (str[j] == delch)
		{
			int n = j;
			while (str[n])
			{
				str[n] = str[n + 1];
				n++;
			}
			str[n] = 0;
		}
		j--;
	}
	return str;
}
