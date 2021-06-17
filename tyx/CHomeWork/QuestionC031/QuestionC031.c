/// <ID>C031</ID>
/// <date>2020/11</date>
/// <summary>
/// ��a + aa + aaa + aaaa + �� + aa...a��n����������aΪ1��9֮�������
/// ��a = 1, n = 3ʱ����1 + 11 + 111֮��Ϊ123
/// </summary>
/// <input>������е�����a������������n</input>
/// <output>��</output>
/// <sample>
/// 1 3
/// 123
/// </sample>
/// <author>Cui Shuning (��������</author>
/// <difficulty>02</difficulty>
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{
	int a, n;
	(void)scanf("%d%d", &a, &n);
	int sum = a;
	printf("%d", a);
	int aa = a;
	for (int i = 0; i < n - 1; i++)
	{
		//Recurse to get the next item
		a = a * 10 + aa; //���Ƶõ���һ��
		printf("+%d", a);
		sum += a; //�ۼ� Accumulate
	}
	printf("=%d\n", sum);
	return 0;
}
