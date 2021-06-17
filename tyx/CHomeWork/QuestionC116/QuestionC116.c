/*���빫Ԫ�ꡢ�¡�����������ֵ��
��������Ǹ���ĵڼ��죨Ӧ�������꣩��
���룬������������ʾ�ꡢ�¡���
�����һ����������ʾ����ڼ���

Cui Shuning (��������2020/11
*/


#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int IsLeapyear(int year);

int main()
{
	const int totalDays[12] =
		{0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

	int year, month, day;
	(void)scanf("%d%d%d", &year, &month, &day);
	int days = totalDays[month - 1] + day;
	if (IsLeapyear(year) && month > 2)
	{
		days++; //����+1
	}
	printf("%d", days);
	return 0;
}


/// <summary>
/// �ж��Ƿ�Ϊ����
/// </summary>
/// <param name="year">���</param>
/// <returns>�ǣ�����1����0</returns>
int IsLeapyear(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}
