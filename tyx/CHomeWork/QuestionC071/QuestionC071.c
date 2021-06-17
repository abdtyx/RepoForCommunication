/*����n,m,��������n<=m, 
�ҳ�[n, m]�����ڸ�λ���ֶ���ͬ�����ܱ�3,5,7������ż����
���룺��n, m���ÿո������n <= m.
��������ɷ���������������һ���ո������
������û��������������ʱ��ʾ - 1.
����1��
100 500
210 420
����2��
100 200
- 1

Cui Shuning (��������2020/11
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int IsDifferent(int x);

int main()
{
	int n, m;
	const int step = 2 * 3 * 5 * 7;
	(void)scanf("%d%d", &n, &m);
	int sum = 0;
	int k = 1;
	while (n > k * step)
	{
		k++;
	}

	for (int i = k * step; i <= m; i += step)
	{
		if (IsDifferent(i))
		{
			sum++ == 0 ? printf("%d", i) : printf(" %d", i);
		}
	}

	if (sum == 0)
	{
		printf("-1");
	}
	return 0;
}

/// <summary>
/// �ж�����x�ĸ���λ�Ƿ�����ͬ��
/// </summary>
/// <param name="x">����x</param>
/// <returns>û����ͬ��λ����1�����򷵻�0</returns>
int IsDifferent(int x)
{
	int num = 0;
	int a[100];
	while (x)
	{
		a[num++] = x % 10;
		x /= 10;
	}

	for (int i = 0; i < num - 1; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (a[i] == a[j])
			{
				return 0;
			}
		}
	}
	return 1;
}
