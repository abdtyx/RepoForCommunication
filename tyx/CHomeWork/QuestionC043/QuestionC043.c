/// <ID>C043</ID>
/// <date>2020/11</date>
/// <summary>
/// ���������3��ʵ������3������ӣ�
/// ����ӵĽ���Լ����������뷽��ת����������Ľ����ʾ���
/// </summary>
/// <input>3��ʵ�����ո�ָ�</input>
/// <output>�ͣ�%g�����������������������1����ʾ���ո�ָ�</output>
/// <sample>
/// 1.34 2.5 6.78
/// 10.62 11
/// </sample>
/// <author>Cui Shuning (��������</author>
/// <difficulty>01</difficulty>
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{
	double a, b, c;
	(void)scanf("%lf%lf%lf", &a, &b, &c);
	double sum = a + b + c;
	//ʵ������0.5֮��תΪ������������������
	//תΪ����ʱֱ����������С������
	//The real number is converted to an integer after adding 0.5, which is rounding
	//when converting to an integer, all fractional parts are directly discarded
	printf("%g %d", sum, (int)(sum + 0.5));
	return 0;
}
