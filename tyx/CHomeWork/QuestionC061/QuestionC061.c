/// <ID>C061</ID>
/// <date>2020/11</date>
/// <summary>
/// ��n���������Լ����2<=n<50
/// </summary>
/// <input>n������������0��Ϊ���Ľ������ÿո������</input>
/// <output>���Լ������n��������һ���ո������</output>
/// <sample>
/// 210 54 24 0
/// 6 210 54 24
/// </sample>
/// <author>Cui Shuning (��������</author>
/// <difficulty>03</difficulty>
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{
	int inputNum[50];
	int i = 0;
	do
	{
		(void)scanf("%d", &inputNum[i]);
	}
	while (inputNum[i++]);
	
	int gcd = inputNum[0];
	int flag = 1;
	while (flag)
	{
		flag = 0;
		for (int n = 0; n < i - 1; n++)
		{
			if (inputNum[n] % gcd)
			{
				flag = 1;
				break;
			}
		}
		if (flag)
		{
			gcd--;
		}
	}
	printf("%d", gcd);
	for (int n = 0; n < i - 1; n++)
	{
		printf(" %d", inputNum[n]);
	}

	return 0;
}
