/*��д������Ѱ�Ҿ���n��Ԫ�ص�һά�����е����ֵ����Сֵ������������Ԫ�ص�ƽ��ֵ������ԭ�����£�
double fun(int a[], int n, int* max, int* min);
���������ʽ��
���룺�û������n + 1�������ÿո�ָ�����һ����Ϊ����Ԫ�ظ���n��
�����3�����֣���һ������Ϊ�����е����Ԫ��ֵ���ڶ�������Ϊ�����е���СԪ��ֵ��
����������Ϊ����Ԫ�ص�ƽ��ֵ������С�����6λ��Ч����)��3�����ÿո�ֿ���

Cui Shuning (��������2020/11
*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

double fun(int a[], int n, int* max, int* min);

int main()
{
	int n;
	int a[100];
	(void)scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		(void)scanf("%d", &a[i]);
	}
	int max;
	int min;
	double average = fun(a, n, &max, &min);
	printf("%d %d %lf", max, min, average);
	return 0;
}

double fun(int a[], int n, int* max, int* min)
{
	double sum = 0; //���
	*max = *min = a[0]; //�����С

	for (int i = 0; i < n; i++)
	{
		sum += a[i];
		if (a[i] > *max)
		{
			*max = a[i];
		}
		if (a[i] < *min)
		{
			*min = a[i];
		}
	}

	return sum / n;
}
