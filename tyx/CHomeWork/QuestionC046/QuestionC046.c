/// <ID>C046</ID>
/// <date>2020/11</date>
/// <summary>
/// ������������ת��Ϊ��Ӧ��ʱ���֡���
/// </summary>
/// <input>1������</input>
/// <output>3��������ð�ŷָ�ֺ��벻��2λʱ���λ��0</output>
/// <sample>
/// 1234567
/// 342:56:07
/// </sample>
/// <author>Cui Shuning (��������</author>
/// <difficulty>01</difficulty>
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{
	int totalSecond;
	(void)scanf("%d", &totalSecond);
	printf("%d:%.2d:%.2d\n", totalSecond / 3600,
	       (totalSecond % 3600) / 60, totalSecond % 3600 % 60);
	return 0;
}
