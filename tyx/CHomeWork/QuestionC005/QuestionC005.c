/// <ID>C005</ID>
/// <date>2020/11</date>
/// <summary>
/// ������һ��8λ��ʮ����������
/// ��д����ȡ�����������м�4λ����
/// �ֱ����ȡ������4λ���Լ���4λ������1024�ĵ�����
/// </summary>
/// <input>һ������</input>
/// <output>�����������ÿո�ָ�</output>
/// <sample>
/// 12233478
/// 2334 3358
/// </sample>
/// <author>Cui Shuning (��������</author>
/// <difficulty>01</difficulty>

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{
	int eightDigital;
	(void)scanf("%d", &eightDigital);
	//ȡ���м�4λ����
	//Take out the middle 4 digits
	int midFour = (eightDigital / 100) % 10000;
	printf("%d %d\n", midFour, midFour + 1024);
	return 0;
}
