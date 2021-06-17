/// <ID>C120</ID>
/// <date>2020/11</date>
/// <summary>
/// ��д������ȥ��һ���ַ����г�ͷ����β���ո�������пո񣬲���д���������е��ò���
/// </summary>
/// <input>������ַ������Ȳ��ᳬ��200</input>
/// <output>����ַ���</output>
/// <sample>
///      we5et et ewtew ter te   et     
///      we5etetewtewterteet
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
	char inputStr[100];
	gets_s(inputStr,100);
	//���ַ�����ߵ�һ���ǿո��ַ�
	int i = 0;
	while (inputStr[i] && inputStr[i] == ' ')
	{
		i++;
	}

	//���ַ����ұߵ�һ���ǿո��ַ�
	int j = strlen(inputStr) - 1;
	while (inputStr[j] && inputStr[j] == ' ')
	{
		j--;
	}
	printf("%s", DelCharBetweenStr(inputStr, i, j, ' '));
	return 0;
}

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
