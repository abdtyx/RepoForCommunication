/*����һ���ַ������䳤�Ȳ�����81����
�ֱ�ͳ������26��Ӣ����ĸ���ֵĴ����������ִ�Сд��ĸ����
������ĸ���ִ����Ӹߵ���������������ͬ������ĸ˳�����С�
��ĸ�����ʽ���������磺A - 3����ʾ��ĸA����3�Σ�
C - 0��ʾ��ĸCû�г��֡�
���룺
��һ��Ϊ���룬ռһ��
�����
�ڶ���Ϊ�����ռһ�С�������ĸ�����ʽ�Ӹߵ��������
����ĸ���֮����һ���ո��ַ��ָ�

Cui Shuning (��������2020/11
*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>

typedef struct _count
{
	char alphabet;
	int c;
} Count;

void BubbleAlpha(Count count[]);

int main()
{
	Count count[26];
	//��ʼ��
	for (int i = 0; i < 26; i++)
	{
		count[i].alphabet = 'A' + i;
		count[i].c = 0;
	}
	char input[100];
	(void)scanf("%[^\n]", input);
	_strupr(input); //תΪ��д��ĸ

	int i = 0;
	while (input[i])
	{
		if (input[i] >= 'A' && input[i] <= 'Z')
		{
			count[input[i] - 'A'].c++;
		}
		i++;
	}
	//����
	BubbleAlpha(count);
	//���
	printf("%c-%d", count[0].alphabet, count[0].c);
	for (int i = 1; i < 26; i++)
	{
		printf(" %c-%d", count[i].alphabet, count[i].c);
	}
	return 0;
}

void BubbleAlpha(Count count[])
{
	for (int i = 0; i < 26; i++)
	{
		for (int j = 25; j > i; j--)
		{
			if (count[j].c > count[j - 1].c)
			{
				Count temp = count[j];
				count[j] = count[j - 1];
				count[j - 1] = temp;
			}
		}
	}
}
