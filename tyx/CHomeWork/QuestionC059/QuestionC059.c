/// <ID>C059</ID>
/// <date>2020/11</date>
/// <summary>
/// һ������A�д���n��n > 0�����������ڲ�����ʹ�����������ǰ���£���ÿ��������
/// ѭ��������m��m >= 0����λ�ã�
/// ����A�е������ɣ�A0A1����An - 1���任Ϊ��An - m���� An - 1A0A1����An - m - 1��
/// ��/// ���m����ѭ������A����ǰ���m��������
/// ����n(1 <= n <= 100)��m��m >= 0����n��������
/// ���ѭ������mλ�Ժ���������С�
/// </summary>
/// <input>��1������n��m��������n��m֮���ÿո�ָ�����2����������A�е�n���������ݼ��ÿո�ָ���</input>
/// <output>��λ��Ľ�������ݼ���һ���ո�ָ���</output>
/// <sample>
/// 10 5
/// 1 2 3 4 5 6 7 8 9 0
/// </sample>
/// <author>Cui Shuning (��������</author>
/// <difficulty>03</difficulty>
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{
	int a[100]; //Ҫ�ƶ�������
	int n, m; //��������n�������ƶ�m��
	(void)scanf("%d%d", &n, &m);

	//��n������������
	for (int i = 0; i < n; i++)
	{
		(void)scanf("%d", &a[i]);
	}
	//ѭ���ƶ�
	for (int i = 0; i < m; i++)
	{
		//int x = a[n - 1];
		int x = 0;
		if (n - 1 >= 0 && n - 1 < 100)
		{
			x = a[n - 1];
		}
		for (int j = n - 2; j >= 0; j--)
		{
			a[j + 1] = a[j];
		}
			
		a[0] = x;
	}
	//���
	for (int i = 0; i < n; i++)
	{
		i == 0 ? printf("%d", a[i]) : printf(" %d", a[i]);
	}

	return 0;
}
