/*��дһ������������СֵԪ�ؼ���Ԫ��λ�õĺ�����
 *����д���������á�Ҫ���ɼ�������10������
 *����������������С�����Сֵ�ж�������ص�һ�γ��ֵ�λ�á�
 *��ʾ�����Զ���һ�����������飬��СԪ��ֵ�͸�Ԫ��λ�õĽṹ�������
 *�Ա�֤������ͬʱ������СԪ��ֵ�͸�Ԫ��λ�á�
 *���������ʽ��
 *���룺�û������10�������ÿո�ָ���
 *������������֣���һ������Ϊ�����е���СԪ��ֵ��
 *�ڶ�������Ϊ��Ԫ���������е��±�λ�ã��������ÿո�ֿ�����
 *���ж����Сֵ������±���С��һ����
 *
 *Cui Shuning (��������2020/11
*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

typedef struct min
{
	int min;
	int minPosition;
} MinPos;

MinPos Find(int* a, int n);

int main()
{
	int a[10];
	for (int i = 0; i < 10; i++)
	{
		(void)scanf("%d", &a[i]);
	}

	MinPos minPos = Find(a, 10);
	printf("%d %d", minPos.min, minPos.minPosition);
	return 0;
}

/// <summary>
/// Ѱ��һ�������е���Сֵ����λ��
/// </summary>
/// <param name="a">����</param>
/// <param name="n">���ݸ���</param>
/// <returns>��Сֵ���±�</returns>
MinPos Find(int* a, int n)
{
	MinPos minPos = {a[0], 0};
	for (int i = 1; i < n; i++)
	{
		if (a[i] < minPos.min)
		{
			minPos.min = a[i];
			minPos.minPosition = i;
		}
	}
	return minPos;
}
