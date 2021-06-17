/*��д���򣬼������ж���ʽ��ֵ:
 *poly(n, x) = 1, �� n = 0��
 *poly(n, x) = x, �� n = 1��
 *poly(n, x) = ((2 * n - 1) * x * poly(n - 1, x) - (n - 1) * poly(n - 2, x)) / n, �� n > 1��
 *���룺n��x����ʽ��"%d%lf"��
 *�������n������ʽ��x����ֵ����ʽ��"%lf\n"��
 *
 *Cui Shuning (��������2020/11
 */


#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<math.h>

double Poly(int n, double x);

int main()
{
	int n;
	double x;
	(void)scanf("%d%lf", &n, &x);
	double y = Poly(n, x);
	printf("%lf\n", y);
	return 0;
}

double Poly(int n, double x)
{
	if (n == 0)
		return 1;
	if (n == 1)
		return x;
	return ((2 * (double)n - 1) * x * Poly(n - 1, x) -
		((double)n - 1) * Poly(n - 2, x)) / n;
}
