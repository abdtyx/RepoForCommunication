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
	while(n<=0)
	{
		printf("������nֵ��");
		scanf("%d", &n);
		if(n<=0)
			printf("n�����Ǵ���0�����������������룡\n");
		else
			printf("���ڼ�����......\n");
	}
	result = factorial(n);
	sum = summation(n);
	if(n == 31)
		printf("��n��ֵΪ��%d\nǰn��ͳ������㷶Χ��", result);
	else
		if(sum<=0)
			printf("�������㷶Χ��");
		else
		{
			printf("��n��ֵΪ��%d\n", result);
			printf("ǰn���Ϊ��%d", sum);
		}
	return 0;
}
