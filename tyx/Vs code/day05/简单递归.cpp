#include <stdio.h>
int factorial(int i)
{
	int An;
	if(i == 1)
		return(1);
	else
		An = 2 * factorial(i-1) + 1;
	return An; 
 } 
int summation(int u)
{
	int sum;
	if(u == 0)
		return(0);
	else
		sum = factorial(u) + summation(u-1);
	return sum;
}
int main()
{
	int n;
	int result;
	int sum;
	printf("������nֵ��");
	scanf("%d", &n);
	result = factorial(n);
	printf("��n��ֵΪ��%d\n", result);
	sum = summation(n);
	printf("ǰn���Ϊ��%d", sum);
	return 0;
}
