/// <ID>C081</ID>
/// <date>2020/11</date>
/// <summary>
/// ��д���򣬰����й�����������ַ�����
/// ���������һ���ַ����������������ַ�����
/// ���ٳ����������ַ�..., �����������ַ�����
/// </summary>
/// <input>һ���ַ���</input>
/// <output>�ո���������ַ�������һ���ո���</output>
/// <sample>
/// student
/// t nt ent dent udent tudent student
/// </sample>
/// <author>Cui Shuning (��������</author>
/// <difficulty>02</difficulty>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4267)

#include<stdio.h>
#include<string.h>

int main()
{
	char str[100] = { 0 };
	(void)scanf("%s", str);
	int maxi = strlen(str) - 1;
	printf("%s", str + maxi);
	for (int i = 1; i <= maxi; i++)
	{
		printf(" %s", str + maxi - i);
	}
	return 0;
}
