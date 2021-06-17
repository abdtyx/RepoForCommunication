/// <ID>C107</ID>
/// <date>2020/11</date>
/// <summary>
/// ���������������飨��������Ĵ�СΪ������100���ĸ���Ԫ�أ�
/// ��������������鹲�е�Ԫ�أ�����С�������������
/// ����һ�������ھ����ظ���Ԫ�أ�
/// ���Ԫ������һ��������û�У��ǹ��У��������ظ���Ԫ�ض���Ҫ�����
/// </summary>
/// <input>�����Ϊ2�У��ֱ�����2�������е�������ÿ�еĵ�һ������Nָʾ��������Ҫ���������������
/// �������N������</input>
/// <output>���������Ԫ���зǹ��е�Ԫ��, ���Ҵ�С�����������</output>
/// <sample>
/// 7 1 2 3 3 5 6 7
/// 6 5 6 7 8 9 0
/// 0 1 2 3 3 8 9
/// </sample>
/// <author>Cui Shuning (��������</author>
/// <difficulty>03</difficulty>
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>


int NumInput(int num[]); //�������ݵ������У������������ݵĸ���
int FindNoAltogether(int a[], int b[], int na, int nb, int c[], int nc);
void Bubble(int b[], int n);

int main()
{
	int num01[30];
	int num02[30];
	int noAltogether[30];
	int nNum01 = NumInput(num01);
	int nNum02 = NumInput(num02);

	//�����ڵ�һ�������в��ڵڶ��������е���
	int nNoAltogether = FindNoAltogether(num01, num02, nNum01, nNum02, noAltogether, 0);
	//�����ڵڶ��������в��ڵ�һ�������е���
	nNoAltogether += FindNoAltogether(num02, num01, nNum02, nNum01, noAltogether, nNoAltogether);
	//����
	Bubble(noAltogether, nNoAltogether);

	printf("%d", noAltogether[0]);
	for (int i = 1; i < nNoAltogether; i++)
	{
		printf(" %d", noAltogether[i]);
	}

	return 0;
}

/// <summary>
/// �������ݵ������У������������ݵĸ���
/// </summary>
/// <param name="num">�������ݵ�����</param>
/// <returns>�������ݵĸ���</returns>
int NumInput(int num[])
{
	int n;
	(void)scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		(void)scanf("%d", &num[i]);
	}
	return n;
}

/// <summary>
/// Ѱ��������a�У�����������b�е��������������c��nc����ʼ��ţ��������ҵ��ĸ���
/// </summary>
/// <param name="a">����a</param>
/// <param name="b">����b</param>
/// <param name="na">����a�е����ݸ���</param>
/// <param name="nb">����b�����ݵĸ���</param>
/// <param name="c">����c</param>
/// <param name="nc">����c��ŵ���ʼλ��</param>
/// <returns>�ҵ������ݸ���</returns>
int FindNoAltogether(int a[], int b[], int na, int nb, int c[], int nc)
{
	int n = 0;
	for (int i = 0; i < na; i++)
	{
		int flag = 0;
		for (int j = 0; j < nb; j++)
		{
			if (a[i] == b[j]) //���ظ���������ѭ��
			{
				flag = 1;
				break;
			}
		}
		if (!flag) //�ҵ�û���ظ���
		{
			c[nc + n] = a[i];
			n++;
		}
	}
	return n;
}

/// <summary>
/// ð������, ��С����
/// </summary>
/// <param name="b">�����������</param>
/// <param name="n">�������</param>
void Bubble(int b[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (b[j] < b[j - 1])
			{
				int t = b[j];
				b[j] = b[j - 1];
				b[j - 1] = t;
			}
		}
	}
}
