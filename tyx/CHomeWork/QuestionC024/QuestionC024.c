/*�ܾ���ǰ�����ﻹ�����һ�Ӳ�ҡ�
*��n��1Ԫֽ�һ���һ�֡����ֺ������ֵ��Ӳ�ң�
*����ÿ������һö�����ж����ֻ�����
*n ֵ���û��Ӽ������룬������������
*���룺����n
*�����һ������

* Cui Shuning (��������2020/11
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int n;
	(void)scanf("%d", &n);
	n = n * 100;
	int sum = 0;
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n / 2; j++)
		{
			for (int k = 1; k < n / 5; k++)
			{
				if (n == i + j * 2 + k * 5)
				{
					sum++;
				}
			}
		}
	}
	printf("%d", sum);
	return 0;
}
