/*�Ӽ�����������������m��n��Ȼ���m + 1��ʼ�ҳ�����m��n��������
���룺m, n
�����n�����������ݼ���һ���ո�ָ���

Cui Shuning (��������2020/11
*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
int IsPrime(int x);

int main()
{
	int m, n;
	(void)scanf("%d%d", &m, &n);
	int num = 0;
	while (num < n)
	{
		while (IsPrime(++m) == 0);
		num++ == 0 ? printf("%d", m) : printf(" %d", m);
	}
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
