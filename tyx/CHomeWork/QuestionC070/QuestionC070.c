/// <ID>C070</ID>
/// <date>2020/11</date>
/// <summary>
/// ����ͬʱ�ڵ�һ������͵ڶ��������е�ȫ��Ԫ�ء�
/// ������������a��Ԫ�ظ���������������a�ĸ���Ԫ�ص�ֵ��������������b��Ԫ�ظ�����
/// ����������b�ĸ���Ԫ�ص�ֵ�����ͬʱ�����������ȫ��Ԫ�ء�
/// </summary>
/// <input>2��������Ԫ�صĸ�������ֵ��ÿ��������û���ظ�Ԫ�أ�</input>
/// <output>ͬʱ�����������ȫ��Ԫ��</output>
/// <sample>
/// 3
/// 1 2 3
/// 5
/// 1 3 5 7 9
/// 1 3
/// </sample>
/// <author>Cui Shuning (��������</author>
/// <difficulty>03</difficulty>

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{
	int a[100], b[100];
	int an, bn; //a��b�е�Ԫ�ظ���
	(void)scanf("%d", &an);

	for (int i = 0; i < an; i++)
	{
		(void)scanf("%d", &a[i]);
	}

	(void)scanf("%d", &bn);
	for (int i = 0; i < bn; i++)
	{
		(void)scanf("%d", &b[i]);
	}

	int ab[100]; //���������ŵ�ab��
	int abn = 0; //�������ĸ���

	for (int i = 0; i < an; i++)
	{
		for (int j = 0; j < bn; j++)
		{
			if (a[i] == b[j])
			{
				ab[abn++] = a[i];
			}
		}
	}

	for (int i = 0; i < abn; i++)
	{
		i == 0 ? printf("%d", ab[i]) : printf(" %d", ab[i]);
	}
	return 0;
}
