/// <ID>C042</ID>
/// <date>2020/11</date>
/// <summary>
/// �Ӽ�����������3��������Ȼ�������3������ƽ��ֵ
/// </summary>
/// <input>3������</input>
/// <output>һ��ʵ����ʹ��%g�����</output>
/// <sample>
/// 6 7 12
/// 8.33333
/// </sample>
/// <author>Cui Shuning (��������</author>
/// <difficulty>01</difficulty>
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{
	//����3����
	//input three numbers
	int a, b, c;
	(void)scanf("%d%d%d", &a, &b, &c);
	printf("%g", (float)(a + b + c) / 3);
	return 0;
}
