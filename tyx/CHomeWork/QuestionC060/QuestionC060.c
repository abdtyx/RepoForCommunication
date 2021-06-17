/// <ID>C060</ID>
/// <date>2020/11</date>
/// <summary>
/// �������ɸ���������ֵ��0��4�ķ�Χ�ڣ��� - 1��Ϊ��������ı�־��ͳ��ÿ�������ĸ�����
/// </summary>
/// <input>[0, 4]�ڵ�������ɵ����У������ - 1���ÿո������</input>
/// <output>0, 1, 2, 3, 4��ͳ�Ƹ�������һ���ո������</output>
/// <sample>
/// 0 0 -1
/// 2 0 0 0 0
/// </sample>
/// <sample>
/// 0 1 2 3 4 -1
/// 1 1 1 1 1
/// </sample>
/// <author>Cui Shuning (��������</author>
/// <difficulty>02</difficulty>
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
//�������������Ҫ�򵥺ܶ�
//���ǵ�ѧ��������ʱ��δѧϰ���飬�ʱ�����δ������
//����ĩ��ע�͵ķ�ʽ��������Ľ��

int main()
{
	//0-4�ĸ���
	//number of 0-4
	int countZero = 0;
	int countOne = 0;
	int countTwo = 0;
	int countThree = 0;
	int countFour = 0;

	int inputNumber = 0;
	(void)scanf("%d", &inputNumber);
	while (inputNumber != -1)
	{
		switch (inputNumber)
		{
		case 0:
			countZero++;
			break;
		case 1:
			countOne++;
			break;
		case 2:
			countTwo++;
			break;
		case 3:
			countThree++;
			break;
		case 4:
			countFour++;
			break;
		}
		(void)scanf("%d", &inputNumber);
	}

	printf("%d %d %d %d %d\n", countZero,
	       countOne, countTwo, countThree, countFour);
	return 0;
}

/*
int main()
{
	int stat[5] = { 0 };
	int input = 0;
	(void)scanf("%d", &input);
	while (input != -1)
	{
		stat[input]++;
		(void)scanf("%d", &input);
	}
	printf("%d", stat[0]);
	for (int i = 1; i < 5; i++)
	{
		printf(" %d", stat[i]);
	}
}
*/
