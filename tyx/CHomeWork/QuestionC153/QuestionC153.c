/// <ID>C153</ID>
/// <date>2020/11</date>
/// <summary>
/// ��������n��2n�������������Ϊ����������С��������
/// �����Ϊż�������Ӵ�С����n����1�Ҳ�����20����Ŵ�1��ʼ��
/// </summary>
/// <input>����n��2n���������ո�ָ�</input>
/// <output>��Ҫ����������������Կո���������û�пո�</output>
/// <sample>
/// 2 4 3 8 2
/// 4 3 8 2
/// </sample>
/// <author>Cui Shuning (��������</author>
/// <difficulty>03</difficulty>

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{
	int n;
	int a[100];
	(void)scanf("%d", &n);
	for (int i = 0; i < 2 * n; i++)
	{
		(void)scanf("%d", &a[i]);
	}
	//����ð��
	for (int i = 1; i < 2 * n - 1; i += 2)
	{
		for (int j = 2 * n - 1; j > i; j -= 2)
		{
			if (a[j] > a[j - 2])
			{
				int temp = a[j];
				a[j] = a[j - 2];
				a[j - 2] = temp;
			}
		}
	}

	//ż��ð��

	for (int i = 0; i < 2 * n - 2; i += 2)
	{
		for (int j = 2 * n - 2; j > i; j -= 2)
		{
			if (a[j] < a[j - 2])
			{
				int temp = a[j];
				a[j] = a[j - 2];
				a[j - 2] = temp;
			}
		}
	}

	//���
	printf("%d", a[0]);
	for (int i = 1; i < 2 * n; i++)
	{
		printf(" %d", a[i]);
	}
	return 0;
}
