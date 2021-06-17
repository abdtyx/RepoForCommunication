/*��һ����Ȼ���������������ĸ�λ���ֵ�λ�þ����������Ϊ������
������Ǿ�������������13��31����������
��������Ҳ�Ǿ�������������1����λ��������
�ж����Ƿ�Ϊ��������������ǣ������YES���������NO��

Cui Shuning (��������2020/11
*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int IsPrime(int x);
int ResverseInt(int x);

int main()
{
	int x;
	(void)scanf("%d", &x);
	printf("%s", IsPrime(x) && IsPrime(ResverseInt(x)) ? "YES" : "NO");
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

/// <summary>
/// ��תһ����������1234��Ϊ4321
/// </summary>
/// <param name="x">����ת������</param>
/// <returns>��ת�Ľ��</returns>

int ResverseInt(int x)
{
	int n = 0;
	while (x)
	{
		n = n * 10 + x % 10;
		x /= 10;
	}
	return n;
}
