/*�������ⳤ�ȵ��ַ������ֱ�ͳ�����д�д��ĸ��Сд��ĸ�������ַ��������ַ��ĸ��������ͳ�ƽ����
�ٰ�ͳ��ֵ�Ӷൽ�����������
��ʾ���������������ð��������ð�š�
���룺���ⳤ�ȵ��ַ�����
�����ͳ�����д�д��ĸ��Сд��ĸ�������ַ��������ַ��ĸ�����

Cui Shuning (��������2020/11
*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

typedef struct _count
{
	char kind[20];
	int c;
} Count;

int main()
{
	Count count[4] = {
		{"��д��ĸ��", 0}, {"Сд��ĸ��", 0},
		{"�����ַ���", 0}, {"�����ַ���", 0}
	};
	char countStr[200];
	(void)scanf("%s", countStr);

	int i = 0;
	while (countStr[i])
	{
		if ('A' <= countStr[i] && countStr[i] <= 'Z')
		{
			count[0].c++;
		}
		else if ('a' <= countStr[i] && countStr[i] <= 'z')
		{
			count[1].c++;
		}
		else if ('0' <= countStr[i] && countStr[i] <= '9')
		{
			count[2].c++;
		}
		else
		{
			count[3].c++;
		}
		i++;
	}

	//���
	for (int i = 0; i < 4; i++)
	{
		printf("%s%d ", count[i].kind, count[i].c);
	}

	//����
	for (int i = 0; i < 4; i++)
	{
		for (int j = 3; j > i; j--)
		{
			if (count[j].c > count[j - 1].c)
			{
				Count t = count[j];
				count[j] = count[j - 1];
				count[j - 1] = t;
			}
		}
	}

	//���
	printf("�Ӷൽ������������£� ");
	for (int i = 0; i < 3; i++)
	{
		printf("%s%d ", count[i].kind, count[i].c);
	}
	printf("%s%d", count[3].kind, count[3].c);

	return 0;
}
