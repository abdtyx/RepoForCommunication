//C051 - �����Լ������С����
//Cui Shuning (��������2020/11

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int a, b, c;
	(void)scanf("%d%d%d", &a, &b, &c);
	int max = a;
	int min = a;
	while (a % min || b % min || c % min)
		min--;
	while (max % a || max % b || max % c)
		max += a;
	printf("%d %d\n", min, max);
	return 0;
}
