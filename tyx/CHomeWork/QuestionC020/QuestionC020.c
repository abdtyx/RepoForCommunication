/*�κ�һ����Ȼ��m����������д��m����������֮�͡����磺
*1 ^ 3 = 1
*2 ^ 3 = 3 + 5
*3 ^ 3 = 7 + 9 + 11
*4 ^ 3 = 13 + 15 + 17 + 19
*���ʵ�֣�����һ��Ȼ��n�������n ^ 3��n������������
*���룺һ��������n����������n ^ 3��������������һ���ո�ָ�
*
* Cui Shuning (��������2020/11
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int num;
	(void)scanf("%d", &num);
	//�������һ������
	//Calculate the first odd number
	int a = num * (num - 1) + 1;
	printf("%d", a);
	for (int i = 1; i < num; i++)
	{
		printf(" %d", a += 2);
	}
	return 0;
}
