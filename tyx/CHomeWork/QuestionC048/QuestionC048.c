/// <ID>C048</ID>
/// <date>2020/11</date>
/// <summary>
/// �������д�Ϣ����������money����λ��Ԫ��������years��
/// ������rate�����㵽�ڴ�Ϣ������2λС����
/// ���㹫ʽsum = money*(1 + rate)^years
/// </summary>
/// <input>�������ڣ������ʡ���Ϊ�����������ö��ŷָ�</input>
/// <output>��Ϣ������2λС����</output>
/// <sample>
/// 12345,5,0.03
/// 14311.24
/// </sample>
/// <author>Cui Shuning (��������</author>
/// <difficulty>01</difficulty>
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<math.h>

int main()
{
	double money, rate, years;
	(void)scanf("%lf,%lf,%lf", &money, &years, &rate);
	printf("%.2lf", money * pow((1 + rate), years));
	return 0;
}
