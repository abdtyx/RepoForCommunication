/*��һ����������������������У����̰������¹�������
���ֵ�����м䣬��Сֵ����������ֵ�������ң�����ֵ��Ϊ0��
����2�У���һ��n��ʾҪ��������ĸ�����n���������ڶ��������n������
��������������飬���ݿո�ָ������һ�����ݺ���û�пո�

Cui Shuning (��������2020/11
*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

void Bubble(int a[], int n);

int main()
{
	int n;
	(void)scanf("%d", &n);
	int a[100] = {0};
	for (int i = 0; i < n; i++)
	{
		(void)scanf("%d", &a[i]);
	}
	Bubble(a, n);
	int min = a[0];
	int mid = a[n / 2];
	int max = a[n - 1];
	//��0�����
	printf("%d", a[0]);
	for (int i = 1; i < n; i++)
	{
		if (i == n / 2)
		{
			a[i] = max;
		}
		else if (i == n - 1)
		{
			a[i] = mid;
		}
		else
		{
			a[i] = 0;
		}
		printf(" %d", a[i]);
	}
	return 0;
}

/// <summary>
/// ð������(��С����
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
