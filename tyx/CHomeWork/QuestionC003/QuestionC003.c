/// <ID>C003</ID>
/// <date>2020/11</date>
/// <summary>
/// ��ȡ3������1~10��������ֵ��ÿ��ȡһ��ֵ�������ӡ����ֵ������Ӣ���Ǻ�(*)
/// </summary>
/// <input>3��������3��</input>
/// <output>3���Ǻ�</output>
/// <sample>
/// 2
/// 3
/// 4
/// **
/// ***
/// ****
/// </sample>
/// <author>Cui Shuning (��������</author>
/// <difficulty>02</difficulty>
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int one, two, three;
	(void)scanf("%d%d%d", &one, &two, &three);

	for (int i = 0; i < one; i++)
	{
		printf("*");
	}
	printf("\n");
	for (int i = 0; i < two; i++)
	{
		printf("*");
	}
	printf("\n");
	for (int i = 0; i < three; i++)
	{
		printf("*");
	}
	printf("\n");
	return 0;
}
