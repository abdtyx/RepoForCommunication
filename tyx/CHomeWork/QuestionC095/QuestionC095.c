/// <ID>C095</ID>
/// <date>2020/11</date>
/// <summary>
/// ���һ�������е�ĳһ�Σ�����������Ԫ�أ��ĸ�Ԫ��ֵ����ͬ�����֮Ϊ��ֵ���жΡ�
/// ��ֵ���ж���Ԫ�صĸ���������ֵ���жεĳ��ȡ�
/// �������г���N��N������[1,50], �Կո������
/// ��������г������ĵ�ֵ���жε�ʼĩ�±꣨0��N - 1������Ӣ�Ķ��ŷָ���
/// ���û�е�ֵ���жΣ������NO.����ж��ͬ�ȳ��ȵĵ�ֵ���У�ֻ�����һ����ֵ���е���ֹ�±ꡣ
/// </summary>
/// <input>���г���N��N������</input>
/// <output>�����г������ĵ�ֵ���жε�ʼĩ�±�</output>
/// <sample>
/// 8 1 1 2 2 2 3 3 5
/// 2,4
/// </sample>
/// <author>Cui Shuning (��������</author>
/// <difficulty>03</difficulty>
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{
	int a[100];
	int n;
	(void)scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		(void)scanf("%d", &a[i]);
	}

	int maxStart = 0; //��ǰ�����ʼ�±�
	int maxEnd = 0; //��ǰ�������±�
	int maxLength = 0; //��ǰ��󳤶�
	int start = 0; //��ǰ��ʼ�±�
	int end = 0; //��ǰ��ʼ�±�
	int length = 0; //��ǰ����

	int i = 0;
	while (i < n)
	{
		//��ǰ��ֵ���жε���ʼ�±�ͽ����±�
		start = i;
		end = i + 1;
		while (a[start] == a[end] && end < n)
		{
			end++;
		}
		//����ǰ��ֵ���жεĳ��ȴ��뵱ǰ����ֵ���жεĳ���
		//���滻ԭ�����Ϊ��ǰ
		if (end - start > 1)
		{
			length = end - start;
			if (length > maxLength)
			{
				maxStart = start;
				maxEnd = end - 1;
				maxLength = length;
			}
		}
		i = end;
	}

	maxLength == 0 ? printf("NO") : printf("%d,%d", maxStart, maxEnd);
	return 0;
}
