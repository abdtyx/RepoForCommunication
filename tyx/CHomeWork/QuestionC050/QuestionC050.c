/// <ID>C050</ID>
/// <date>2020/11</date>
/// <summary>
/// ��д��������������ܷ񹹳������Σ����鷽�����������ߺ;�Ҫ���ڵ�����
/// </summary>
/// <input>���߳��ȣ�ʵ�����ո�ָ�</input>
/// <output>�������Թ��ɣ����YES���������ERROR DATA</output>
/// <sample>
/// 1.1 1.1 1.1
/// YES
/// </sample>
/// <sample>
/// 1 2 30
/// ERROR DATA
/// </sample>
/// <author>Cui Shuning (��������</author>
/// <difficulty>01</difficulty>
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{
	double a, b, c;
	(void)scanf("%lf%lf%lf", &a, &b, &c);

	printf(a + b > c && b + c > a && c + a > b ? "YES" : "ERROR DATA");

	return 0;
}
