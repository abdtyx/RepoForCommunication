/// <ID>C111</ID>
/// <date>2020/11</date>
/// <summary>
/// ����һ�����пո���ַ�����������ĸ�����֡��ո��Լ��������ţ���
/// ��ȡ�ַ����е�����ת��Ϊ�����������
/// �ַ����еķ������ַ���Ϊ�ָ����
/// ������ݼ��Կո�ָ���ĩβû�пո񣬲�����������������ĺ�ֵ����
/// �ַ�����û���κ�����ʱ�������NO����������ַ������Ȳ�����80�� 
/// </summary>
/// <input>1���ַ���</input>
/// <output>2�У���һ����ת������������2�������������ĺ�</output>
/// <sample>
/// 2
/// 1/2 1/2
/// 1
/// </sample>
/// /// <sample>
/// 3
/// -1/2 -1/2 -1/2
/// -1 1/2
/// </sample>
/// <author>Cui Shuning (��������</author>
/// <difficulty>03</difficulty>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4267)

#include<stdio.h>
#include<string.h>

int SplitString(char str[], char ch, char r[][100]);
int Convert(char str[]);

int main()
{
	char inStr[1000];
	gets_s(inStr, 1000);
	int i = 0;
	while (inStr[i])
	{
		if (!(inStr[i] >= '0' && inStr[i] <= '9'))
		{
			inStr[i] = '*';
		}
		i++;
	}
	char splitStr[100][100];
	int m = SplitString(inStr, '*', splitStr);
	if (m == 0)
	{
		printf("NO");
		return 0;
	}
	int num[100] = { 0 };
	int sum = 0;
	for (i = 0; i < m; i++)
	{
		num[i] = Convert(splitStr[i]);
		sum += num[i];
	}
	printf("%d", num[0]);
	for (i = 1; i < m; i++)
	{
		printf(" %d", num[i]);
	}
	printf("\n%d", sum);
	return 0;
}

int SplitString(char str[], char ch, char r[][100])
{
	int i = 0;
	int m = 0;
	int n = 0;
	while (str[i] == ch && str[i] != 0)
	{
		i++;
	}
	while (str[i] != 0)
	{
		while (str[i] != ch && str[i] != 0)
		{
			r[m][n] = str[i];
			n++;
			i++;
		}
		r[m][n] = 0;
		m++;
		n = 0;
		while (str[i] == ch && str[i] != 0)
		{
			i++;
		}
	}
	return m;
}

int Convert(char str[])
{
	int n = 0;
	int len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		n = n * 10 + (str[i] - '0');
	}
	return n;
}
