/// <ID>C007</ID>
/// <date>2020/11</date>
/// <summary>
/// �ҳ�m��n֮�������ͬ������m < n��
/// һ��������x���������ƽ������β�������xΪͬ����
/// ���磬6����ƽ����36��β����25����ƽ����625��β������ô6��25����ͬ����
/// </summary>
/// <input>m��n�������������ÿո�ָ�</input>
/// <output>�������ͬ���������ݼ��ÿո�ָ�</output>
/// <sample>
/// 5 50
/// 5 6 25
/// </sample>
/// <author>Cui Shuning (��������</author>
/// <difficulty>02</difficulty>
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<math.h>

/*
int IsomorphicNumber(int x, int xx);
int main()
{
	int m, n;
	
	(void)scanf("%d%d", &m, &n);
	int firstNum = 0;
	for (int i = m; i <= n; i++)
	{
		
		if (IsomorphicNumber(i, i * i))
		{
			if (firstNum == 0)
			{
				printf("%d", i);
				firstNum = 1;
			}
			else
			{
				printf(" %d", i);
			}
		}
		
	}
	return 0;
}

int IsomorphicNumber(int x, int xx)
{
	while (x && xx)
	{
		if (x % 10 != xx % 10)
		{
			return 0;
		}
		x = x / 10;
		xx = xx / 10;
	}
	return 1;
}

*/
int main()
{
	int m, n;
	(void)scanf("%d%d", &m, &n);
	int firstNum = 0;
	for (int i = m; i <= n; i++)
	{
		//Find the number of digits of i
		//��i��λ��
		int digi = (int)log10(i) + 1;
		//Determine whether i is an isomorphic number
		//�ж�i�Ƿ���ͬ����
		if ((i * i) % (int)pow(10, digi) == i)
		{
			//Is the first number?
			//�Ƿ�������ĵ�һ����
			firstNum++ == 0 ? printf("%d", i) : printf(" %d", i);
		}
	}
}
