/*��Ŀ������ĳ��ĳ��ĳ�գ��ж���һ������һ��ĵڼ��죿
�����������3��5��Ϊ����Ӧ���Ȱ�ǰ�����µļ�������Ȼ���ټ���5�켴����ĵڼ��죬��������������������·ݴ���3ʱ�迼�Ƕ��һ�졣*/
#include <stdio.h>
int main()
{
	int detective(int year);
	int monthday(int year, int month, int day);
	int year, month, day, sum;
	printf("�����������գ�");
	scanf_s("%d %d %d", &year, &month, &day);
	if (monthday(year, month, day) == -1)
		printf("��Ч���·�");
	else
	{
		if (day <= 0 || monthday(year, month, day) == -2)
			printf("��Ч������");
		else
		{
			sum = monthday(year, month, day) + day;
			if (detective(year) && month > 2)
				sum = sum + 1;
			printf("��һ������һ��ĵ�%d��", sum);
		}
	}
	return 0;
}