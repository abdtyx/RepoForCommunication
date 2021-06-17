/*��дð��������������ԭ�ͣ�void BubbleSort(int a[], int n); ��n��������������
��дѡ��������������ԭ�ͣ�void SelectionSort(int a[], int n); ��n��������������
��дmain����������10�����������ú������䰴����ͽ���ֱ������������
������������ݼ���һ���ո�ָ���

Cui Shuning (��������2020/11
*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

void BubbleSort(int a[], int n);
void SelectionSort(int a[], int n);

#define NUM 10

int main()
{
	int a[NUM];
	for (int i = 0; i < NUM; i++)
	{
		(void)scanf("%d", &a[i]);
	}
	BubbleSort(a, NUM);
	for (int i = 0; i < NUM; i++)
	{
		printf("%d ", a[i]);
	}
	SelectionSort(a, NUM);
	printf("%d", a[0]);
	for (int i = 1; i < NUM; i++)
	{
		printf(" %d", a[i]);
	}
	return 0;
}

void SelectionSort(int a[], int n)
{
	int biggest;
	for (int i = 0; i < n - 1; i++)
	{
		biggest = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] > a[biggest])
				biggest = j;
		}
		int temp = a[biggest];
		a[biggest] = a[i];
		a[i] = temp;
	}
}

/// <summary>
/// ð������
/// </summary>
/// <param name="a">�����������</param>
/// <param name="n">����ĸ���</param>
void BubbleSort(int a[], int n)
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
