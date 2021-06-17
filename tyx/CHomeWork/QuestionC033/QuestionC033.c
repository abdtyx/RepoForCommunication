/*��������n >= 1, ������ʽ��ֵ��
*s = 1 + 1 / (1 + 2) + 1 / (1 + 2 + 3) + �� + 1 / (1 + 2 + 3 + �� + n)
* 
*Cui Shuning (��������2020/11
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int n;
	float sum = 0;
	float denominator = 1;
	(void)scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		sum = sum + (1 / denominator);
		//������һ��ķ�ĸ
		//Recurse the denominator of the next item
		denominator = denominator + i + 2;
	}
	printf("%lf", sum);
	return 0;
}
