/*���������ַ����������������1���ַ������ַ����������
���Ȳ�ͬʱ�����ֻ��������ַ����е��ַ���
����team��good, ���Ϊtgeoaomd ��
�������ַ�����challenge��put, 
�����Ϊcphuatllenge���ַ��ĳ��Ȳ�����100��
�����ַ������Կո�ָ���

Cui Shuning (��������2020/11
*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{
	char input01[120];
	char input02[120];
	(void)scanf("%s%s", input01, input02);
	int i = 0;
	int j = 0;
	while (input01[i] || input02[j])
	{
		if (input01[i])
		{
			printf("%c", input01[i++]);
		}
		if (input02[j])
		{
			printf("%c", input02[j++]);
		}
	}
	return 0;
}
