/// <ID>C113</ID>
/// <date>2020/11</date>
/// <summary>
/// ��ν����������ָ���Ϊ 2 ������������
/// ������С������������3��5, 5��7Ҳ����������
/// ��д�������������[m, n]�е���������������
/// </summary>
/// <input>������m, n, m, n > 1.</input>
/// <output>[m, n]�е�����������</output>
/// <sample>
/// 2 10
/// 2
/// </sample>
/// <author>Cui Shuning (��������</author>
/// <difficulty>03</difficulty>
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
int IsPrime(int x);

int main()
{
	int m, n;
	(void)scanf("%d%d", &m, &n);
	int sum = 0;

	for (int i = m; i <= n - 2; i++)
	{
		if (IsPrime(i) && IsPrime(i + 2))
		{
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
