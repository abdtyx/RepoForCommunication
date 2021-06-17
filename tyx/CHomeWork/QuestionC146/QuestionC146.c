/// <ID>C111</ID>
/// <date>2020/11</date>
/// <summary>
/// ���������ַ���s, t��(�ַ�����û�пո񣬰�����Сд��ĸ�������Լ��������ţ�
/// ����С����˳�������s��t�г��ֹ�(�����ִ�Сд)�������ַ���������ĸ������д���
/// �ظ����ַ�ֻ����һ�Ρ�
/// </summary>
/// <input>1���ַ���</input>
/// <output>2�У���һ����ת������������2�������������ĺ�</output>
/// <sample>
/// @12EiwTT78## YyYjfisjmp201mr()
/// #()01278@EFIJMPRSTWY
/// </sample>
/// <author>Cui Shuning (��������</author>
/// <difficulty>03</difficulty>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4267)

#include<stdio.h>
#include<string.h>

void StrMerge(char* source, char* dest);
void StrBubble(char* a);

int main()
{
	char s[100];
	char t[100];
	char u[200] = {0};
	(void)scanf("%s%s", s, t);
	_strupr(s);
	_strupr(t);
	StrMerge(s, u);
	StrMerge(t, u);
	StrBubble(u);
	printf("%s", u);
	return 0;
}

/// <summary>
/// ��source�е��ַ�����dest�У��ظ��Ĳ�����
/// </summary>
/// <param name="source">Դ�ַ���</param>
/// <param name="dest">�ϲ�����ַ���</param>
void StrMerge(char* source, char* dest)
{
	int i = 0;
	int j = strlen(dest);
	while (source[i])
	{
		int flag = 0;
		for (int m = 0; m < j; m++)
		{
			if (source[i] == dest[m]) //�ظ�
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			dest[j] = source[i];
			dest[++j] = 0;
		}
		i++;
	}
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
