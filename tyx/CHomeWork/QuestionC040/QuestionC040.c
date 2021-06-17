//����һ������n(n >= 2)���ж�n�Ƿ�Ϊ������
//��������� "YES", ������� "NO"��
//Cui Shuning (��������2020/11

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int IsPrime(int x);

int main()
{
	int n;
	(void)scanf("%d", &n);
	printf("%s", IsPrime(n) ? "YES" : "NO");
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
