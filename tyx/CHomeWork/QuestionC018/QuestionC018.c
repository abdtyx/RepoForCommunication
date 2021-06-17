/// <ID>C018</ID>
/// <date>2020/11</date>
/// <summary>
/// ��������һ���������������λ���ֵ�ƽ����
/// 1234 �򣺼���1 * 1 + 2 * 2 + 3 * 3 + 4 * 4 = 30
/// </summary>
/// <input>1��������</input>
/// <output>1��������</output>
/// <sample>
/// 1234
/// 30
/// </sample>
/// <author>Cui Shuning (��������</author>
/// <difficulty>02</difficulty>
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{
	unsigned x;
	(void)scanf("%u", &x);
	int sum = 0;
	while (x)
	{
		sum = sum + (x % 10) * (x % 10);
		x = x / 10;
	}
	printf("%d", sum);
	return 0;
}
