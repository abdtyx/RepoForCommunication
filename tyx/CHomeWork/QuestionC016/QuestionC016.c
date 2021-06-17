/// <ID>C016</ID>
/// <date>2020/11</date>
/// <summary>
/// ������������a, b, c���� a ^ 2 + b ^ 2 = c ^ 2����������һ�鹴������
/// ��д�������������[m, n]�еĹ�����������(��һ�鹴��������a < b < c)
/// </summary>
/// <input>������m, n, m, n > 0</input>
/// <output>[m, n]�еĹ�����������</output>
/// <sample>
/// 2 30
/// 11
/// </sample>
/// <author>Cui Shuning (��������</author>
/// <difficulty>02</difficulty>
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{
	//Loop control variable
	//ѭ�����Ʊ���
	int i, j, k;
	//���� input
	int m, n;
	//���� count
	int sum = 0;
	(void)scanf("%d%d", &m, &n);
	for (i = m; i <= n; i++)
		for (j = i + 1; j <= n; j++)
			for (k = j + 1; k <= n; k++)
				if (k * k == i * i + j * j)
				{
					sum++;
				}

	printf("%d\n", sum);
	return 0;
}
