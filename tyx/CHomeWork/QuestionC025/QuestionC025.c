/*���㼶��
*2 / 1, -3 / 2, 5 / 3, -8 / 5, ...
*��ǰn��͡�
*�������ص��ǣ���1�����Ȳ����Ƿ��ţ���ǰһ��ķ����Ǻ�һ��ķ�ĸ��
*ǰһ��ķ��ӷ�ĸ֮��Ϊ��һ��ķ��ӡ���2����������������Ž���
*���룺����n, 0 < n < 100.
*�����ǰn��ĺͣ���ʽ"%f"��

* Cui Shuning (��������2020/11
*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{
	int n;
	(void)scanf("%d", &n);
	float sum = 0;
	long long numerator = 2;
	long long denominator = 1;
	int sign = 1;

	for (int i = 0; i < n; i++)
	{
		sum = sum + sign * (float)numerator / denominator;
		sign = -sign;
		long long temp = numerator;
		numerator = numerator + denominator;
		denominator = temp;
	}

	printf("%f", sum);
	return 0;
}
