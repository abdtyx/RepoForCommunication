0/// <ID>C044</ID>
/// <date>2020/11</date>
/// <summary>
/// ����2���������󣺺ͣ��������
/// </summary>
/// <input>2���������ڶ������Ƿ���������</input>
/// <output>4������������Ϊ�͡�������̣����ݼ��ÿո�ָ�</output>
/// <sample>
/// 33 27
/// 60 6 891 1
/// </sample>
/// <author>Cui Shuning (��������</author>
/// <difficulty>01</difficulty>
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{
	int x, y;
	(void)scanf("%d%d", &x, &y);
	printf("%d %d %d %d\n", x + y, x - y, x * y, x / y);
	return 0;
}
