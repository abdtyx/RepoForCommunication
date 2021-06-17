/*��[n, m]�����е����������������ĸ�����
���룺n, m
������г�[n, m]�е������������м���һ���ո�����������ʾ�����ĸ�����
������
10 30
11 13 17 19 23 29 6

Cui Shuning (��������2020/11
*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
int IsPrime(int x);

int main()
{
	int m, n;
	(void)scanf("%d%d", &n, &m);
	int sum = 0;
	for (int i = n; i <= m; i++)
	{
		if (IsPrime(i))
		{
			printf("%d ", i);
			sum++;
		}
	}
	printf("%d", sum);
	return 0;
}

/// <summary>
/// �ж�һ�������Ƿ�������
/// </summary>
/// <param name="x">�жϵ���</param>
/// <returns>�ǣ��򷵻�1�����򷵻�0</returns>
int IsPrime(int x)
{
	for (int i = 2; i <= x / i; i++)
	{
		if (x % i == 0)
			return 0;
	}
	return 1;
}
