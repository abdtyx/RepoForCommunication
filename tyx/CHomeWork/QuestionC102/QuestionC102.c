/// <ID>C102</ID>
/// <date>2020/11</date>
/// <summary>
/// ��һ�����е����ֵ��Ȼ��ͳ�Ƹ����ֵ���������г��ֵĴ���
/// </summary>
/// <input>Ԫ�ظ���n��n��������nС��200</input>
/// <output>���ֵ�����ֵĴ��������ݼ���һ�����Ÿ�����</output>
/// <sample>
/// 6 99 0 34 34 34 99
/// 99, 2
/// </sample>
/// <author>Cui Shuning (��������</author>
/// <difficulty>02</difficulty>
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int n;
	(void)scanf("%d", &n);

	int i = 1;
	int nextNum;
	(void)scanf("%d", &nextNum);
	int max = nextNum;
	int maxNum = 1;

	while (i < n)
	{
		(void)scanf("%d", &nextNum);
		if (nextNum == max)
		{
			maxNum++;
		}
		if (nextNum > max)
		{
			max = nextNum;
			maxNum = 1;
		}
		i++;
	}
	printf("%d,%d", max, maxNum);
	return 0;
}
