/*һ�����100�׸߶��������£�
*ÿ����غ󷴵���ԭ�߶ȵ�һ�룬�����£��ٷ�����
*�����ڵ�n�����ʱ���������˶����ף���n�η����߶��Ƕ��٣�
*���� :
*��n�ε�ֵ, ����
*�����С�򾭹���·�̳��Ⱥ�С�򷴵��ĸ߶ȣ���2�������

Cui Shuning (��������2020/11
*/

#define _CRT_SECURE_NO_WARNINGS
#define HIGH 100

#include<stdio.h>

int main()
{
	int n;
	(void)scanf("%d", &n);
	double length = HIGH;
	double nthHigh = HIGH;
	for (int i = 0; i < n; i++)
	{
		nthHigh = nthHigh / 2;
		length += nthHigh * 2;
	}
	printf("%lf\n%lf\n", length - nthHigh * 2, nthHigh);
	return 0;
}
