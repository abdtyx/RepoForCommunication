/*����n��n������������ż����С�������򣬶������Ӵ�С���������С�����ż����������Ӵ�С����������һ���У���һ���ո������
���룺n��n��������, �ÿո������
����������С�����ż����������Ӵ�С����������һ���ո����

Cui Shuning (��������2020/11
*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

void Bubble(int a[], int n);

int main()
{
	int n;
	int a[100];
	(void)scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		(void)scanf("%d", &a[i]);
	}
	int b[100];
	int c[100];
	//ѡ��ż������b�����򣨴�С����
	//��������c
	int nb = 0;
	int nc = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{
			b[nb++] = a[i];
		}
		else
		{
			c[nc++] = a[i];
		}
	}
	Bubble(b, nb);
	for (int i = 0; i < nb; i++)
	{
		printf("%d ", b[i]);
	}
	Bubble(c, nc);
	printf("%d", c[nc - 1]);
	for (int i = nc - 2; i >= 0; i--)
	{
		printf(" %d", c[i]);
	}
	return 0;
}

/// <summary>
/// ð������
/// </summary>
/// <param name="a">�����������</param>
/// <param name="n">����ĸ���</param>
void Bubble(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (a[j] < a[j - 1])
			{
				int t = a[j];
				a[j] = a[j - 1];
				a[j - 1] = t;
			}
		}
	}
}
