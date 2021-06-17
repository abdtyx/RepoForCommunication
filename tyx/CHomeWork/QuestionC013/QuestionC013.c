/// <ID>C013</ID>
/// <date>2020/11</date>
/// <summary>
/// ��һ������4���������ֽ�Ϊ������������֮��
/// �ֽ�����Ψһ��������еĿ���
/// </summary>
/// <input>һ��������</input>
/// <output>���ɷֽ��������������</output>
/// <sample>
/// 24
/// 24=7+8+9
/// </sample>
/// <sample>
/// 123
/// 123=18+19+20+21+22+23
/// 123=40+41+42
/// 123=61+62
/// </sample>
/// <author>Cui Shuning (��������</author>
/// <difficulty>02</difficulty>
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	unsigned n;
	(void)scanf("%u", &n);
	//����С�Ŀ��ܿ�ʼ��һ����
	//Try one by one from the smallest possible
	//1+2+3....
	//2+3+4.....
	for (unsigned i = 1; i <= n / 2; i++)
	{
		unsigned sum = 0;
		for (unsigned j = i; sum <= n; j++)
		{
			sum = sum + j;
			//Adding from i to j is exactly equal to n
			if (sum == n) //��i��j���ǡ�õ���n
			{
				//����ĿҪ�������i��j֮�����
				//Output the number from i to j as required by the title
				printf("%d=%d", n, i);
				for (unsigned k = i + 1; k <= j; k++)
				{
					printf("+%d", k);
				}
				printf("\n");
				break;
			}
		}
	}
	return 0;
}
