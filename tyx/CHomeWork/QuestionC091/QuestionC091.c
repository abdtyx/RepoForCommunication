/*һά�����а�˳������1, 2, 3, ..., 15��15��������
 *����n, m, 1 <= n <= m <= 15Ϊ������
 *����n����m��Ԫ���Ƶ������ĩβ��
 *���룺������n, m���м��ÿո������
 *�����˳��ı������Ԫ�أ���Ӣ�Ķ��Ÿ�����ĩβû�ж��š�
 *
 *Cui Shuning (��������2020/11
 */

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{
	int a[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	int n;
	int m;
	(void)scanf("%d%d", &n, &m);

	for (int i = 0; i < 15 - m; i++)
	{
		a[i + n - 1] = m + i + 1;
	}
	for (int i = n + 14 - m; i < 15; i++)
	{
		a[i] = m + i - 14;
	}
	printf("%d", a[0]);
	for (int i = 1; i < 15; i++)
	{
		printf(",%d", a[i]);
	}
	return 0;
}
