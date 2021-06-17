/// <ID>C106</ID>
/// <date>2020/11</date>
/// <summary>
/// ĳ���ӽ����±�����ѵ�������±���1��ʼ��˳�����α�ţ�
/// ���ų�һ�к�ӣ�ѵ���Ĺ������£�
/// ��ͷ��ʼ1��2������������2�ĳ��У�
/// ʣ�µ���С��ŷ���£���ٴ�ͷ��ʼ����1��3������
/// ������3�ĳ��У�ʣ�µ���С��ŷ���£��
/// ������ͷ��ʼ����1��2�������Ժ��ͷ��ʼ��������1��2������
/// 1��3����ֱ��ʣ�µ���������������Ϊֹ��
/// </summary>
/// <input>NΪ�ʼ���±�������2����NС��6000��</input>
/// <output>ʣ�µ��±�����ı��</output>
/// <sample>
/// 21
/// 1 7 19
/// </sample>
/// <author>Cui Shuning (��������</author>
/// <difficulty>03</difficulty>
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

int Compress(int a[], int n);

int main()
{
	int n;  //���ڶ�����ʣ����±�����
	//�˴����дa[6000]����Ϊ����̫�����һ������
	int* a = (int*)malloc(6000 * sizeof(int));
	if (a == NULL)
	{
		return 0;
	}
	
	(void)scanf("%d", &n);
	for (int i = 0; i < n; i++) //��ʼ������
	{
		a[i] = i + 1;
	}
	
	int flag = 0; //������1-2��������1-3����
	while (n > 3) //ʣ�µ���������3��
	{
		if (flag == 0) //1-2����
		{
			for (int i = 0; i < n; i++)
			{
				if ((i + 1) % 2 == 0)
				{
					a[i] = 0; //���ӵı��Ϊ0
				}
			}
			flag = 1;
		}
		else //1-3����
		{
			for (int i = 0; i < n; i++)
			{
				if ((i + 1) % 3 == 0)
				{
					a[i] = 0;
				}
			}
			flag = 0;
		}
		//ȥ�������е�0�����е�������ǰ�ƶ�
		n = Compress(a, n);
	}

	n == 3 ? printf("%d %d %d", a[0], a[1], a[2])
		: printf("%d %d", a[0], a[1]);
	return 0;
}

/// <summary>
/// �������е�0�޳���ͬʱ��0��ǰ��
/// </summary>
/// <param name="a">����</param>
/// <param name="n">��Ҫ���������</param>
/// <returns>�������Ŀ</returns>
int Compress(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == 0)
		{
			for (int k = i; k <= n - 1; k++)
			{
				a[k] = a[k + 1];
			}
			n = n - 1;
		}
	}
	return n;
}
