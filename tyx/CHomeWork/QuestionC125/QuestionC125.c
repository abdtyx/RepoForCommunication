/*����6���������ÿո�ָ���
*�ҳ���6�������е�����������������Щ�������д�С��������
*��δ�ҵ������������NULL��
* 
* Cui Shuning (��������2020/11
*/

#define _CRT_SECURE_NO_WARNINGS
#define NUM 6

#include<stdio.h>

int IsPrime(int x);
void Bubble(int a[], int n);

int main()
{
	int primeNum = 0; //�ҵ��������ĸ���
	int prime[NUM]; //����ҵ�������
	for (int i = 0; i < NUM; i++)
	{
		int x;
		(void)scanf("%d", &x);
		if (IsPrime(x)) //�������������������
		{
			prime[primeNum++] = x;
		}
	}
	if (primeNum > 0)
	{
		Bubble(prime, primeNum); //����
		printf("%d", prime[0]);
		for (int i = 1; i < primeNum; i++)
		{
			printf(" %d", prime[i]);
		}
	}
	else
	{
		printf("NULL");
	}
	return 0;
}

/// <summary>
/// �ж�һ�����Ƿ�������
/// </summary>
/// <param name="x">�ж�x�Ƿ�������</param>
/// <returns>���򷵻�1�����򷵻�0</returns>
int IsPrime(int x)
{
	for (int i = 2; i <= x / i; i++)
	{
		if (x % i == 0)
		{
			return 0;
		}
	}
	return 1;
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
