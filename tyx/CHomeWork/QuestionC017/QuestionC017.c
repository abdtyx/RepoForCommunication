/// <ID>C017</ID>
/// <date>2020/11</date>
/// <summary>
/// ��������a��b����a* a + b * b���ڵ���100��
/// �����a * a + b * b��λ�����ϵ����֣�
/// �������a * a + b * b
/// </summary>
/// <input>��������</input>
/// <output>һ������</output>
/// <sample>
/// 6 7
/// 85
/// </sample>
/// <sample>
/// 12 34
/// 13
/// </sample>
/// <author>Cui Shuning (��������</author>
/// <difficulty>01</difficulty>
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{
	int a, b;
	(void)scanf("%d%d", &a, &b);
	int c = a * a + b * b;
	printf("%d", c >= 100 ? c / 100 : c);
	return 0;
}
